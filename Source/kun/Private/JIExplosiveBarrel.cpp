// Fill out your copyright notice in the Description page of Project Settings.


#include "JIExplosiveBarrel.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AJIExplosiveBarrel::AJIExplosiveBarrel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	MeshComp->SetSimulatePhysics(true);
	MeshComp->SetCollisionProfileName(UCollisionProfile::PhysicsActor_ProfileName);
	RootComponent = MeshComp;
	ForceComp = CreateDefaultSubobject<URadialForceComponent>("ForceComp");
	ForceComp->SetupAttachment(MeshComp);
	ForceComp->SetAutoActivate(false);
	ForceComp->Radius = 750.0f;
	ForceComp->ImpulseStrength = 2500.0f;
	ForceComp->bImpulseVelChange = true;
	ForceComp->AddCollisionChannelToAffect(ECC_WorldDynamic);
}

// Called when the game starts or when spawned
void AJIExplosiveBarrel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AJIExplosiveBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

