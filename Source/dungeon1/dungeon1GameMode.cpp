// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "dungeon1GameMode.h"
#include "dungeon1Character.h"
#include "UObject/ConstructorHelpers.h"
#include "dungeon1.h"

Adungeon1GameMode::Adungeon1GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
