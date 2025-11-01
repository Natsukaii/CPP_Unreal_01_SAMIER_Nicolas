 // Fill out your copyright notice in the Description page of Project Settings.


#include "ExerciceActor.h"

// Sets default values
AExerciceActor::AExerciceActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//création de la racine du composant
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	//Oncréer le Static Mesh et on l'attache a la racine
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MeshComponent->SetupAttachment(Root);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMeshFinder(TEXT("/Engine/EditorMeshes/EditorCube.EditorCube"));
	if (CubeMeshFinder.Succeeded())
	{
		//CubeMesh.Object;
		MeshComponent->SetStaticMesh(CubeMeshFinder.Object);
	}


	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMeshFinder(TEXT("/Engine/EditorMeshes/EditorSphere.EditorSphere"));
	if (SphereMeshFinder.Succeeded())
	{
		//CubeMesh.Object;
		MeshComponent->SetStaticMesh(SphereMeshFinder.Object);
	}
}

// Called when the game starts or when spawned
void AExerciceActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AExerciceActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

