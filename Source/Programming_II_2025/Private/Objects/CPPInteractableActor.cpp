// Fill out your copyright notice in the Description page of Project Settings.


#include "Objects/CPPInteractableActor.h"

// Sets default values
ACPPInteractableActor::ACPPInteractableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MrMesh"));
}

// Called when the game starts or when spawned
void ACPPInteractableActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPPInteractableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPPInteractableActor::OnInteract()
{
	UE_LOG(LogTemp, Error, TEXT("INTERACTED!!"));
}
