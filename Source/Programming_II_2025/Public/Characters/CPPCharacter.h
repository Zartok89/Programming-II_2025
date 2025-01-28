// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Programming_II_2025/Programming_II_2025Character.h"
#include "CPPCharacter.generated.h"

UCLASS()
class PROGRAMMING_II_2025_API ACPPCharacter : public AProgramming_II_2025Character
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACPPCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
