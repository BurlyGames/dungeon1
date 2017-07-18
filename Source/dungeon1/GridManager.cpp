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

	// Test logging
	UE_LOG(YourLog, Warning, TEXT("Grid Manager reporting for duty!"));

	AGridManager::GenerateGrid(10, 10);
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
		//UE_LOG(YourLog, Warning, TEXT("Row Loop"));

		for (int col = 0; col < _grid->NumColumns(); col++)
		{
			FVector Location(spaceWidth * col, spaceHeight * row, 200.0f);
			FRotator Rotation(0.0f, 0.0f, 0.0f);
			FActorSpawnParameters SpawnInfo;
			SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
			GetWorld()->SpawnActor<ASpace>(Location, Rotation, SpawnInfo);

			//UE_LOG(YourLog, Warning, TEXT("Column Loop"));

			// If East is linked then open, else a wall edge
			if (_grid->Cells()[row][col].IsLinked(_grid->Cells()[row][col].East))
			{
				//UE_LOG(YourLog, Warning, TEXT("East is open"));
			}
			else
			{
				//UE_LOG(YourLog, Warning, TEXT("East is closed"));
			}
		}
	}
}

void AGridManager::GenerateGrid(int32 Rows, int32 Columns)
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