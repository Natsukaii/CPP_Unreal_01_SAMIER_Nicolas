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
	/*Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	float ScaleOscilation = (sin(DeltaTime * ScaleSpeed) + 1 ) /2 ;


	GetOwner()->SetActorScale3D(BaseScale * NewScale);*/
}

