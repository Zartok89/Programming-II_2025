#include "InteractActor.h"

// Sets default values
AInteractActor::AInteractActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));  
    SetRootComponent(DefaultSceneRoot); 

	LampBodyStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Lamp Body"));
	LampBodyStaticMeshComponent->SetupAttachment(DefaultSceneRoot);

	LampHeadStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Lamp Head"));
	LampHeadStaticMeshComponent->SetupAttachment(DefaultSceneRoot);
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
	UE_LOG(LogTemp, Error, TEXT("INTERACTED!!"));
}