// Fill out your copyright notice in the Description page of Project Settings.


#include "BezierComponant.h"

// Sets default values for this component's properties
UBezierComponant::UBezierComponant()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	//public
	InterpolationDuration = 0.0f;
	InterpolationPosition = TArray<FVector>();

	//private
	MyActor = GetOwner();
	Timer = 0.0f;

	//------------------Cours---------------------------
	//Timer = 0.0f;
	//Duration = 0.0f;
	//Number = 0;
}


// Called when the game starts
void UBezierComponant::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UBezierComponant::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

