// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Grid.h"
#include "Engine.h"
#include "GameFramework/Info.h"
#include "GridManager.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class DUNGEON1_API AGridManager : public AInfo
{
	GENERATED_BODY()

public:
	Grid* _grid = nullptr;

	UFUNCTION(BlueprintCallable, Category = "Grid Management")
	void ResetGrid(int32 Rows, int32 Columns);

	UFUNCTION(BlueprintCallable, Category = "Grid Management")
	void GenerateSpaces();

	UFUNCTION(BluePrintPure, Category = "Grid Management")
	int32 GetGridRows() { return AGridManager::Rows; };

	UFUNCTION(BluePrintPure, Category = "Grid Management")
	int32 GetGridColumns() { return AGridManager::Columns; };

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	int32 Rows = 10;
	int32 Columns = 10;
};
