// Fill out your copyright notice in the Description page of Project Settings.


#include "MotionObject.h"

// Sets default values
AMotionObject::AMotionObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//création de la racine du composant
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	//Oncréer le Static Mesh et on l'attache a la racine
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);

	//On cherche le mesh cube puis on le met dans le StaticMeshComponent
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(TEXT("/Game/LevelPrototyping/Meshes/SM_Cube.SM_Cube"));
	if (CubeMesh.Succeeded())
	{
		//CubeMesh.Object;
		Mesh->SetStaticMesh(CubeMesh.Object);
	}

	//public
	Duration = 0.0f;
	Point = TArray<FVector>();

	//private
	Timer = 0.0f;
	IsInterpolate = false;

}

// Called when the game starts or when spawned
void AMotionObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMotionObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!IsInterpolate)
		return;

	Timer += DeltaTime;
	float Alpha = UMyTools::MyClamp(Timer / Duration, 0, 1);

	FVector Location = UMyTools::BezierInterp(Point, Alpha);

	Mesh->SetWorldLocation(Location);
}

void AMotionObject::StartBezierInterpolation()
{
	IsInterpolate = true;
}

void AMotionObject::StopBezierInterpolation()
{
	IsInterpolate = false;
}

void AMotionObject::ResetInterpolation()
{
	Timer = 0.0f;
	Mesh->SetWorldLocation(Point[0]);
}

