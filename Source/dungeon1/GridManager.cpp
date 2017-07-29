// Fill out your copyright notice in the Description page of Project Settings.

#include "GridManager.h"
#include "Sidewinder.h"
#include "BinaryTree.h"
#include "Grid.h"
#include "Cell.h"
#include "Space.h"
#include "dungeon1.h"

// Called when this object is instantiated
void AGridManager::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(YourLog, Warning, TEXT("Grid Manager reporting for duty!"));

	AGridManager::ResetGrid(AGridManager::Rows, AGridManager::Columns);
}

void AGridManager::GenerateSpaces()
{
	if (!_grid) { return; }

	// Run through current Grid, spawn Space Actors

	float spaceWidth = 150.0f;
	float spaceHeight = 150.0f;

	// Each Row
	for (int row = 0; row < _grid->NumRows(); row++)
	{
		for (int col = 0; col < _grid->NumColumns(); col++)
		{
			FVector Location(spaceWidth * col, spaceHeight * row, 200.0f);
			FRotator Rotation(0.0f, 0.0f, 0.0f);
			FActorSpawnParameters SpawnInfo;
			SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
			ASpace* _newSpace = GetWorld()->SpawnActor<ASpace>(Location, Rotation, SpawnInfo);

			// Set pointer to this manager onto the Space
			// Or to the Grid?
			_newSpace->GridManager = this;
			_newSpace->SpaceCell = &_grid->Cells()[row][col];
			_newSpace->Row = row;
			_newSpace->Column = col;

			if (_grid->Cells()[row][col].East == nullptr)
			{
				_newSpace->East = false;
			}
			else
			{
				_newSpace->East = true;
			}

			_newSpace->BuildRoom();

			FString _output = "Output:\n\n";
			if (_grid->Cells()[row][col].IsLinked(_grid->Cells()[row][col].North)) _output += FString::Printf(TEXT("row:%d col:%d -- North is linked\n"), row, col);
			if (_grid->Cells()[row][col].IsLinked(_grid->Cells()[row][col].South)) _output += FString::Printf(TEXT("row:%d col:%d -- South is linked\n"), row, col);
			if (_grid->Cells()[row][col].IsLinked(_grid->Cells()[row][col].East)) _output += FString::Printf(TEXT("row:%d col:%d -- East is linked\n"), row, col);
			if (_grid->Cells()[row][col].IsLinked(_grid->Cells()[row][col].West)) _output += FString::Printf(TEXT("row:%d col:%d -- West is linked\n"), row, col);

			UE_LOG(YourLog, Warning, TEXT("%s"), *_output);
		}
	}
}

void AGridManager::ResetGrid(int32 Rows, int32 Columns)
{
	AGridManager::Rows = Rows;
	AGridManager::Columns = Columns;

	// Generate a simple Grid
	_grid = new Grid(Rows, Columns);

	// Process it by the BinaryTree maze algorithm
	Sidewinder().Process(_grid);

	//const FString _debug = *_grid->NumColumns;

	FString _output = _grid->OutputString();

	UE_LOG(YourLog, Warning, TEXT("%s"), *_output);
}

//int32 AGridManager::GetGridRows()
//{
//	// TODO Change this to read from the underlying Grid object
//	return AGridManager::Rows;
//}
//
//int32 AGridManager::GetGridColumns()
//{
//	// TODO Change this to read from the underlying Grid object
//	return AGridManager::Columns;
//}