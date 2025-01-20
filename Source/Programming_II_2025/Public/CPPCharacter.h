#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Programming_II_2025/Programming_II_2025Character.h"
#include "CPPCharacter.generated.h"

UCLASS()
class PROGRAMMING_II_2025_API ACPPCharacter : public AProgramming_II_2025Character
{
	GENERATED_BODY()

public:
	ACPPCharacter();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputAction> InteractAction;

	UFUNCTION(BlueprintCallable)
	void InteractingWithOneObject();
};