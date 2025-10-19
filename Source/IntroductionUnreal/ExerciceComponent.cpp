// Fill out your copyright notice in the Description page of Project Settings.


#include "ExerciceComponent.h"

// Sets default values for this component's properties
UExerciceComponent::UExerciceComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...

	BaseScale = FVector(1.0f, 1.0f, 1.0f);
	TargetScale = 4.0f;
	ScaleSpeed = 1.0f;
	Timer = 0.0f;
	bIsActive = false;
}


// Called when the game starts
void UExerciceComponent::BeginPlay()
{
	Super::BeginPlay();

	BaseScale = GetOwner()->GetActorScale3D();

}


// Called every frame
void UExerciceComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!bIsActive)
		return;

	AActor* Owner = GetOwner();
	FVector CurrentScale = Owner->GetActorScale3D();

	Timer += DeltaTime;
	float ScaleOscilation = (cos(Timer * ScaleSpeed) + 1) / 2;

	float NewScaleX = FMath::Lerp(TargetScale, CurrentScale.X, ScaleOscilation);
	float NewScaleY = FMath::Lerp(TargetScale, CurrentScale.Y, ScaleOscilation);
	float NewScaleZ = FMath::Lerp(TargetScale, CurrentScale.Z, ScaleOscilation);

	FVector NewScale = FVector(NewScaleX, NewScaleY, NewScaleZ);

	Owner->SetActorScale3D(NewScale);
}

void UExerciceComponent::StartOscillation()
{
	bIsActive = true;
}

void UExerciceComponent::StopOscillation()
{
	bIsActive = false;
}



