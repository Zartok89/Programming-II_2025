// Fill out your copyright notice in the Description page of Project Settings.

#include "CPPAppleActor.h"

#include "CPPCharacter.h"
#include "Kismet/GameplayStatics.h"

ACPPAppleActor::ACPPAppleActor()
{
	AppleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	AppleMesh->SetupAttachment(DefaultSceneRoot);
}

void ACPPAppleActor::OnInteract()
{
	Super::OnInteract();

	TObjectPtr<APawn> PlayerRef = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	if (PlayerRef)
	{
		TObjectPtr<ACPPCharacter> CPPCharacterRef = Cast<ACPPCharacter>(PlayerRef);

		CPPCharacterRef->ApplesPickedUp++;
		UE_LOG(LogTemp, Log, TEXT("Total Amount of Apples Picked Up: %i"), CPPCharacterRef->ApplesPickedUp);

		Destroy();
	}
}