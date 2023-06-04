// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JGameplayInterface.h"

#include "GameFramework/Actor.h"

#include "JIItemChest.generated.h"

UCLASS()
class KUN_API AJIItemChest : public AActor, public IJGameplayInterface
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	float TargetPitch;
	void Interact_Implementation(APawn* InstigatorPawn);

protected:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BaseMash;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* LidMash;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Sets default values for this actor's properties
	AJIItemChest();
};
