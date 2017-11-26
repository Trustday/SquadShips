// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "SquadShips2GameMode.h"
#include "SquadShips2Pawn.h"
#include "Protagonista.h"


ASquadShips2GameMode::ASquadShips2GameMode()
{
	// set default pawn class to our flying pawn
	DefaultPawnClass = AProtagonista::StaticClass(); 
	//ASquadShips2Pawn::StaticClass();
	//AProtagonista::StaticClass();

	//DefaultCharacterClass = ;
}