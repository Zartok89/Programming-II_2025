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
	AInteractActor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	virtual void OnInteract() override;

	UFUNCTION(BlueprintCallable)
	void FlipFlopInteractToggle();

	UFUNCTION(BlueprintCallable)
	virtual void FlipFlopStateA();

	UFUNCTION(BlueprintCallable)
	virtual void FlipFlopStateB();

	UPROPERTY()
	bool bIsStateA;

	UPROPERTY()
	bool bIsStateB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* DefaultSceneRoot;
};