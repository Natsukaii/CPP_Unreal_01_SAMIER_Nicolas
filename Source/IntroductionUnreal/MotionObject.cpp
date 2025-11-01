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

	BezierPointList = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BezierPointList"));
	BezierPointList->SetupAttachment(Root);

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

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMeshFinder(TEXT("/Game/LevelPrototyping/Meshes/SM_ChamferCube.SM_ChamferCube"));
	if (CubeMesh.Succeeded())
	{
		//CubeMesh.Object;
		SphereMesh = SphereMeshFinder.Object;
	}
	else 
	{
		SphereMesh = nullptr;
	}

	//public
	Duration = 0.0f;
	PointsLocation = TArray<FVector>();

	//private
	BezierTimer = 0.0f;
	bIsInterpolate = false;
	PointCount = 0;

	bIsRotateTo = false;
	bIsScaleTo = false;
	TargetRotation = FRotator::ZeroRotator;
	InitialRotation = FRotator::ZeroRotator;
	TargetScale = FVector::ZeroVector;
	InitialScale = FVector::ZeroVector;
	RotateDuration = 0.0f;
	ScaleDuration = 0.0f;
	RotateDuration = 0.0f;
	ScaleTimer = 0.0f;

}

// Called when the game starts or when spawned
void AMotionObject::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMotionObject::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	int pointCountDelta = PointCount - BezierPoint.Num();

	if (pointCountDelta == 0)
		return;

	if (PointCount > 0) 
	{
		// Creation des points
		for (int i = 0; i < pointCountDelta; i++)
		{
			BezierPoint.Add(CreateBezierPoint(BezierPoint.Num()));
		}
	}
	else
	{
		for (int i = BezierPoint.Num() - 1; i >= PointCount; i--)
		{
			UStaticMeshComponent* Point = BezierPoint.Pop();
			Point->DestroyComponent();
		}
		// Détruire des points
	}

	//// On detruit l'ancien composant s'il existe
	//if (BezierPoint != nullptr) 
	//{
	//	BezierPoint->DestroyComponent();
	//	BezierPoint = nullptr;
	//}

	//// On creer le composant
	//BezierPoint = NewObject<UStaticMeshComponent>(this, FName("Point"));

	//// On notifie a l'objet que le composant appartient a l'objet
	//BezierPoint->RegisterComponent();

	//// AttachToComponent
	//BezierPoint->AttachToComponent(Root, FAttachmentTransformRules::KeepRelativeTransform);

	//BezierPoint->SetStaticMesh(SphereMesh);
	//BezierPoint->bHiddenInGame = true;
	//BezierPoint->SetCollisionProfileName("NoCollision");
	//BezierPoint->SetWorldScale3D(FVector(0.1f));

}

// Called every frame
void AMotionObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	BezierInterpolation(DeltaTime);

	RotateTo(DeltaTime);
	SclaleTo(DeltaTime);

}

void AMotionObject::StartBezierInterpolation()
{
	bIsInterpolate = true;
	BezierTimer = 0.0f;

	PointsLocation = TArray<FVector>();

	for (int i = 0; i < PointCount; i++)
	{
		//FVector PointLocation = BezierPoint->GetComponentLocation();
		PointsLocation.Add(BezierPoint[i]->GetComponentLocation());
	}
}

void AMotionObject::BezierInterpolation(const float& DeltaTime)
{
	if (!bIsInterpolate)
		return;

	BezierTimer += DeltaTime;
	float Alpha = UMyTools::MyClamp(BezierTimer / Duration, 0, 1);

	FVector Location = UMyTools::BezierInterp(PointsLocation, Alpha);

	Mesh->SetWorldLocation(Location);
}

void AMotionObject::StartRotateTo(FRotator Rotation, float InterDuration)
{
	bIsRotateTo = true;
	TargetRotation = Rotation;
	RotateDuration = InterDuration;
	InitialRotation = Mesh->GetComponentRotation();
	RotateTimer = 0.0f;
}

void AMotionObject::RotateTo(const float& DeltaTime)
{
	if (!bIsRotateTo)
		return;

	RotateTimer += DeltaTime;
	float Alpha = UMyTools::MyClamp(RotateTimer / RotateDuration, 0, 1);

	FRotator NewRotation = FMath::Lerp(InitialRotation, TargetRotation, Alpha);

	Mesh->SetWorldRotation(NewRotation);
}

void AMotionObject::StartSclaleTo(FVector Scale, float InterDuration)
{
	bIsScaleTo = true;
	TargetScale = Scale;
	ScaleDuration = InterDuration;
	InitialScale = Mesh->GetComponentScale();
	ScaleTimer = 0.0f;
}

void AMotionObject::SclaleTo(const float& DeltaTime)
{
	if (!bIsScaleTo)
		return;

	ScaleTimer += DeltaTime;
	float Alpha = UMyTools::MyClamp(ScaleTimer / ScaleDuration, 0, 1);

	FVector NewScale = FMath::Lerp(InitialScale, TargetScale, Alpha);

	Mesh->SetWorldScale3D(NewScale);
}

//void AMotionObject::RotateTo(FVector Rotation, float Duration)
//{
//
//}
//
//void AMotionObject::ScaleTo(FVector Scale, float Duration)
//{
//
//}


UStaticMeshComponent* AMotionObject::CreateBezierPoint(const int& Index)
{


	// On creer le composant
	FName PointName = FName("Point_" + FString::FromInt(Index));
	UStaticMeshComponent* Point = NewObject<UStaticMeshComponent>(this, PointName);

	// On notifie a l'objet que le composant appartient a l'objet
	Point->RegisterComponent();

	// AttachToComponent
	Point->AttachToComponent(BezierPointList, FAttachmentTransformRules::KeepRelativeTransform);

	Point->SetStaticMesh(SphereMesh);
	Point->bHiddenInGame = true;
	Point->SetCollisionProfileName("NoCollision");
	Point->SetWorldScale3D(FVector(0.1f));

	return Point;
}

