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
		//EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &ACPPCharacter::InteractingWithOneObject);
	}
}

void ACPPCharacter::InteractingWithOneObject(float InInteractRadius)
{
	FHitResult HitResult;

	bool bHit = GetWorld()->SweepSingleByChannel(
		HitResult,
		GetActorLocation(),
		GetActorLocation(),
		FQuat::Identity,
		ECC_Visibility,
		FCollisionShape::MakeSphere(InInteractRadius),
		FCollisionQueryParams(FName(TEXT("InteractTrace")), false, this)
	);

	DrawDebugSphereTraceSingle(
		GetWorld(),
		GetActorLocation(),
		GetActorLocation(),
		InInteractRadius,
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

void ACPPCharacter::InteractingWithManyObjects(float InInteractRadius)
{
	TArray<FHitResult> HitResults;

	bool bHit = GetWorld()->SweepMultiByChannel(
		HitResults,
		GetActorLocation(),
		GetActorLocation(),
		FQuat::Identity,
		ECC_Visibility,
		FCollisionShape::MakeSphere(InInteractRadius),
		FCollisionQueryParams(FName(TEXT("InteractTrace")), false, this)
	);

	DrawDebugSphereTraceMulti(
		GetWorld(),
		GetActorLocation(),
		GetActorLocation(),
		InInteractRadius,
		EDrawDebugTrace::ForDuration,
		false,
		HitResults,
		FLinearColor::Green,
		FLinearColor::Red,
		5.f
	);

	if (bHit)
	{
		for (auto& ActorsHit : HitResults)
		{
			TObjectPtr<AInteractActor> OtherActor = Cast<AInteractActor>(ActorsHit.GetActor());

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
}