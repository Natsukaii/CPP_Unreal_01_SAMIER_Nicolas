// Fill out your copyright notice in the Description page of Project Settings.


#include "TestInteraction.h"

// Sets default values
ATestInteraction::ATestInteraction()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(MeshComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> cubeMesh(TEXT("/Game/LevelPrototyping/Meshes/SM_Cube.SM_Cube"));
	if (cubeMesh.Succeeded())
		MeshComponent->SetStaticMesh(cubeMesh.Object);
}

// Called when the game starts or when spawned
void ATestInteraction::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestInteraction::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATestInteraction::Interact_Implementation()
{
	MeshComponent->AddLocalRotation(FRotator(0.0f, 10.0f, 0.0f));
}

FString ATestInteraction::GetDescription_Implementation()
{
	return FString("Rotate");
}

