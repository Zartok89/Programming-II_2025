// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractActor.h"
#include "CPPLampActor.generated.h"

/**
 *
 */
UCLASS()
class PROGRAMMING_II_2025_API ACPPLampActor : public AInteractActor
{
	GENERATED_BODY()
public:
	ACPPLampActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* LampBodyStaticMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* LampHeadStaticMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterialInterface* LampEnabledMaterial;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterialInterface* LampDisabledMaterial;

	virtual void OnInteract() override;

	virtual void FlipFlopStateA() override;

	virtual void FlipFlopStateB() override;
};
