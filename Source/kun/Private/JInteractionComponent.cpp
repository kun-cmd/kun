// Fill out your copyright notice in the Description page of Project Settings.


#include "JInteractionComponent.h"

#include "JGameplayInterface.h"


// Sets default values for this component's properties
UJInteractionComponent::UJInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UJInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UJInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
void UJInteractionComponent::PrimaryInteract()
{
	FCollisionObjectQueryParams ObjectQueryParams;
	ObjectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);
	AActor* MyOwner = GetOwner();
	FVector EyeLocation;
	FRotator EyeRotation;
	FVector End = EyeLocation + (EyeRotation.Vector()*1000);
	MyOwner->GetActorEyesViewPoint(EyeLocation,EyeRotation);
	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(Hit,EyeLocation,End,ObjectQueryParams);
	AActor * HitActor = Hit.GetActor();
	if (HitActor->GetClass()->ImplementsInterface(UJGameplayInterface::StaticClass()))

	{
		APawn* MyPawn = Cast<APawn>(MyOwner);
		IJGameplayInterface::Execute_Interact(HitActor,MyPawn);
	}
	 
}

