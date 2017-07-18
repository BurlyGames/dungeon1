// Fill out your copyright notice in the Description page of Project Settings.

#include "Space.h"
#include "Engine.h"
#include "dungeon1.h"

// Sets default values
ASpace::ASpace()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ASpace::BuildRoom();
}

// Called when the game starts or when spawned
void ASpace::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASpace::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASpace::BuildRoom()
{
	// Add floor static mesh
	UBoxComponent* FloorComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("RootComponent"));
	RootComponent = FloorComponent;
	FloorComponent->SetCollisionProfileName(TEXT("Pawn"));

	UStaticMeshComponent* FloorVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	FloorVisual->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> FloorVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Tube.Shape_Tube"));
	if (FloorVisualAsset.Succeeded())
	{
		FloorVisual->SetStaticMesh(FloorVisualAsset.Object);
		FloorVisual->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		FloorVisual->SetWorldScale3D(FVector(1.0f));
	}

	UE_LOG(YourLog, Warning, TEXT("Space object reporting for duty!"));

	// Add corner posts

	// Add north wall if necessary

	// Add south wall if necessary

	// Add east wall if necessary

	// Add west wall if necessary


	//USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	//RootComponent = SphereComponent;
	//SphereComponent->InitSphereRadius(40.0f);
	//SphereComponent->SetCollisionProfileName(TEXT("Pawn"));

	//// Create and position a mesh component so we can see where our sphere is
	//UStaticMeshComponent* SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	//SphereVisual->SetupAttachment(RootComponent);
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
	//if (SphereVisualAsset.Succeeded())
	//{
	//	SphereVisual->SetStaticMesh(SphereVisualAsset.Object);
	//	SphereVisual->SetRelativeLocation(FVector(0.0f, 0.0f, -40.0f));
	//	SphereVisual->SetWorldScale3D(FVector(0.8f));
	//}

}

