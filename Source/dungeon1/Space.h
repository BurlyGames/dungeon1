// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GridManager.h"
#include "Grid.h"
#include "Cell.h"
#include "Particles/ParticleSystemComponent.h"
#include "Space.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class DUNGEON1_API ASpace : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpace();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Grid Management")
	void BuildRoom();

	UPROPERTY(BlueprintReadWrite, Category = "Space Management")
	AGridManager* GridManager = nullptr;
	Cell* SpaceCell = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "Space Management")
	int Row;

	UPROPERTY(BlueprintReadWrite, Category = "Space Management")
	int Column;

	UPROPERTY(BlueprintReadWrite, Category = "Space Management")
	bool North = false;

	UPROPERTY(BlueprintReadWrite, Category = "Space Management")
	bool South = false;

	UPROPERTY(BlueprintReadWrite, Category = "Space Management")
	bool East = false;

	UPROPERTY(BlueprintReadWrite, Category = "Space Management")
	bool West = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

};
