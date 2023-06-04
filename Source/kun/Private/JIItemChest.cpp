// Fill out your copyright notice in the Description page of Project Settings.


#include "JIItemChest.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AJIItemChest::AJIItemChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BaseMash = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMash"));
	RootComponent = BaseMash;
	LidMash = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LidMash"));
	LidMash->SetupAttachment(BaseMash);
	TargetPitch = 110;
}

void AJIItemChest::Interact_Implementation(APawn* InstigatorPawn)
{
	LidMash->SetRelativeRotation(FRotator(TargetPitch, 0, 0));
	throw std::logic_error("The method or operation is not implemented.");
}

// Called when the game starts or when spawned
void AJIItemChest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AJIItemChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
 
