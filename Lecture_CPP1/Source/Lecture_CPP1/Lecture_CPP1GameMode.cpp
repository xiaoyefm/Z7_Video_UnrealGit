// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Lecture_CPP1GameMode.h"
#include "Lecture_CPP1Character.h"
#include "UObject/ConstructorHelpers.h"

ALecture_CPP1GameMode::ALecture_CPP1GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
