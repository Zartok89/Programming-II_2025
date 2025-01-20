#include "CPPCharacter.h"

#include "CPPInteractInterface.h"
#include "EnhancedInputComponent.h"
#include "InteractActor.h"
#include "KismetTraceUtils.h"

ACPPCharacter::ACPPCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACPPCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ACPPCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACPPCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) 
	{
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &ACPPCharacter::InteractingWithOneObject);
	}
}

void ACPPCharacter::InteractingWithOneObject()
{
	FHitResult HitResult;
	float SphereRadius = 200.f;

	bool bHit = GetWorld()->SweepSingleByChannel(
		HitResult,
		GetActorLocation(),
		GetActorLocation(),
		FQuat::Identity,
		ECC_Visibility,
		FCollisionShape::MakeSphere(SphereRadius),
		FCollisionQueryParams(FName(TEXT("InteractTrace")), false, this)
	);

	DrawDebugSphereTraceSingle(
		GetWorld(),
		GetActorLocation(),
		GetActorLocation(),
		SphereRadius,
		EDrawDebugTrace::ForDuration,
		false,
		HitResult,
		FLinearColor::Green,
		FLinearColor::Red,
		5.f
	);

	if (bHit)
	{
		TObjectPtr<AInteractActor> OtherActor = Cast<AInteractActor>(HitResult.GetActor());

		if (OtherActor)
		{
			if (OtherActor->GetClass()->ImplementsInterface(UCPPInteractInterface::StaticClass()))
			{
				ICPPInteractInterface* InterfaceInstance = Cast<ICPPInteractInterface>(OtherActor);
				if (InterfaceInstance)
				{
					InterfaceInstance->OnInteract();
				}
			}
		}
	}
}