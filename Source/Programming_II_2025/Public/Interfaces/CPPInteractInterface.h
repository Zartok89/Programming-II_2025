// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CPPInteractInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCPPInteractInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PROGRAMMING_II_2025_API ICPPInteractInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void OnInteract() = 0;

};
