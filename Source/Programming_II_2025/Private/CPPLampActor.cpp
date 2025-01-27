// Fill out your copyright notice in the Description page of Project Settings.

#include "CPPLampActor.h"

ACPPLampActor::ACPPLampActor()
{
	LampBodyStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Lamp Body"));
	LampBodyStaticMeshComponent->SetupAttachment(DefaultSceneRoot);
	LampBodyStaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);

	LampHeadStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Lamp Head"));
	LampHeadStaticMeshComponent->SetupAttachment(DefaultSceneRoot);
}

void ACPPLampActor::OnInteract()
{
	Super::OnInteract();

}

void ACPPLampActor::FlipFlopStateA()
{
	Super::FlipFlopStateA();

	LampHeadStaticMeshComponent->SetMaterial(0, LampEnabledMaterial);

}

void ACPPLampActor::FlipFlopStateB()
{
	Super::FlipFlopStateB();

	LampHeadStaticMeshComponent->SetMaterial(0, LampDisabledMaterial);

}
