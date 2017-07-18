// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "dungeon1.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, dungeon1, "dungeon1" );
 
//General Log
DEFINE_LOG_CATEGORY(YourLog);

//Logging during game startup
DEFINE_LOG_CATEGORY(YourInit);

//Logging for your AI system
DEFINE_LOG_CATEGORY(YourAI);

//Logging for Critical Errors that must always be addressed
DEFINE_LOG_CATEGORY(YourCriticalErrors);

