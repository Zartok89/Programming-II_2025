#pragma once

#include "CoreMinimal.h"
#include "CPPInteractInterface.h"
#include "GameFramework/Actor.h"
#include "InteractActor.generated.h"

UCLASS()
class PROGRAMMING_II_2025_API AInteractActor : public AActor, public ICPPInteractInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AInteractActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	virtual void OnInteract() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* DefaultSceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* LampBodyStaticMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* LampHeadStaticMeshComponent;
};