// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractActor.h"
#include "CPPAppleActor.generated.h"

/**
 * 
 */
UCLASS()
class PROGRAMMING_II_2025_API ACPPAppleActor : public AInteractActor
{
	GENERATED_BODY()

public:
	ACPPAppleActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* AppleMesh;

	virtual void OnInteract() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int32> Numbers;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> Actors;
};
