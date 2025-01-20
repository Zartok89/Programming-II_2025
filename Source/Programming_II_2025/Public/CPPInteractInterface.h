#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CPPInteractInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCPPInteractInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 *
 */
class PROGRAMMING_II_2025_API ICPPInteractInterface
{
	GENERATED_BODY()

public:
	virtual void OnInteract() = 0;

	//UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	//void OnInteractWithBP();;
};
