// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyTools.h"
#include "BezierComponant.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INTRODUCTIONUNREAL_API UBezierComponant : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBezierComponant();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float InterpolationDuration;
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly)
	TArray<FVector> InterpolationPosition;

private:
	AActor* MyActor;
	float Timer;

//------------------Cours---------------------------
//public:
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//	float Duration;
//
//private:
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
//	int Number;
//	float Timer;

};
