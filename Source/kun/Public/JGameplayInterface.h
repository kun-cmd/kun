// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "JGameplayInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UJGameplayInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class KUN_API IJGameplayInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent)
	void Interact(APawn* InstigatorPawn);
	
};
