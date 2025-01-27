#include "InteractActor.h"

// Sets default values
AInteractActor::AInteractActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	SetRootComponent(DefaultSceneRoot);
}

// Called when the game starts or when spawned
void AInteractActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AInteractActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AInteractActor::OnInteract()
{
	FlipFlopInteractToggle();
	UE_LOG(LogTemp, Error, TEXT("INTERACTED!!"));
}

void AInteractActor::FlipFlopInteractToggle()
{
	bIsStateA = !bIsStateA;

	if (bIsStateA)
	{
		FlipFlopStateA();
	}
	else
	{
		FlipFlopStateB();
	}
}

void AInteractActor::FlipFlopStateA()
{
}

void AInteractActor::FlipFlopStateB()
{
}