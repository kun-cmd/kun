// Fill out your copyright notice in the Description page of Project Settings.


#include "JICharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
AJICharacter::AJICharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->bUsePawnControlRotation = true; 
	SpringArmComp->SetupAttachment(RootComponent);
	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);
	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationYaw = false;
	GetCharacterMovement()->JumpZVelocity = 500.0f;
	GetCharacterMovement()->AirControl = 0.15f;

}

// Called when the game starts or when spawned
void AJICharacter::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void AJICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AJICharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{	
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AJICharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AJICharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAction("Jump", IE_Pressed,this, &AJICharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AJICharacter::Jump);

	PlayerInputComponent->BindAction("PrimaryAttack",IE_Pressed, this, &AJICharacter::PrimaryAttack);
}
void AJICharacter::PrimaryAttack()
{
	FVector HandLocation =  GetMesh()->GetSocketLocation("ik_hand_gun");
	FTransform SpawnTM = FTransform(GetControlRotation(), HandLocation);
	FActorSpawnParameters SpawnParams; 
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	GetWorld()->SpawnActor<AActor>(ProjectileClass, SpawnTM, SpawnParams);
}
void AJICharacter::Jump(){
	Super::Jump();
}

