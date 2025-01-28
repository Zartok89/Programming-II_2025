// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/CPPCharacter.h"

// Sets default values
ACPPCharacter::ACPPCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPPCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPPCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPPCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

