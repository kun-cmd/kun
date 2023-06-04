// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "JICharacter.generated.h"
class UCameraComponent;
class USpringArmComponent;

class UJIInteractionComponent;

UCLASS()
class KUN_API AJICharacter : public ACharacter
{	
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> ProjectileClass;
public:
	// Sets default values for this character's properties
	AJICharacter();

protected:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;

	
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void MoveForward(float value) {
		FRotator controlRot = GetControlRotation();

		controlRot.Pitch = 0.0f;
		controlRot.Roll = 0.0f;

		AddMovementInput(controlRot.Vector(), value);

	}

	void MoveRight(float value) {
		FRotator controlRot = GetControlRotation();

		controlRot.Pitch = 0.0f;
		controlRot.Roll = 0.0f;
		// x = forward
		//y = right
		//z = up
		FVector RightVector = FRotationMatrix(controlRot).GetScaledAxis(EAxis::Y);
		AddMovementInput(RightVector, value);
	}
	void PrimaryAttack();
	virtual void Jump() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
