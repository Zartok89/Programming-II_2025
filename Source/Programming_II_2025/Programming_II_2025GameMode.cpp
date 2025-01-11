// Copyright Epic Games, Inc. All Rights Reserved.

#include "Programming_II_2025GameMode.h"
#include "Programming_II_2025Character.h"
#include "UObject/ConstructorHelpers.h"

AProgramming_II_2025GameMode::AProgramming_II_2025GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
