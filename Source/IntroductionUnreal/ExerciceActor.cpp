 // Fill out your copyright notice in the Description page of Project Settings.


#include "ExerciceActor.h"

// Sets default values
AExerciceActor::AExerciceActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMeshFinder(TEXT("/Engine/EditorMeshes/EditorCube.EditorCube"));
	//if (CubeMeshFinder.Succeeded())
	//{
	//	CubeMesh = CubeMeshFinder.Object;
	//}

	//static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMeshFinder(TEXT("/Engine/EditorMeshes/EditorSphere.EditorSphere"));
	//if (SphereMeshFinder.Succeeded())
	//{
	//	SphereMesh = SphereMeshFinder.Object;
	//}

	////création de la racine du composant
	//Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	//SetRootComponent(Root);

	////Oncréer le Static Mesh et on l'attache a la racine
	//MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	//MeshComponent->SetupAttachment(Root);

	//bIsCube = true;

}

//void AExerciceActor::OnConstruction(const FTransform& Transform)
//{
//	if (bIsCube)
//	{
//		MeshComponent->SetStaticMesh(CubeMesh);
//	}
//	else
//	{
//		MeshComponent->SetStaticMesh(SphereMesh);
//	}
//}

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

