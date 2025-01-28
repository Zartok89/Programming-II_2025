// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/CPPInteractInterface.h"
#include "CPPInteractableActor.generated.h"

UCLASS()
class PROGRAMMING_II_2025_API ACPPInteractableActor : public AActor, public ICPPInteractInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPPInteractableActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	virtual void OnInteract() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh;

};
