// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyTools.h"
#include "MotionObject.generated.h"

UCLASS()
class INTRODUCTIONUNREAL_API AMotionObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMotionObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void StartBezierInterpolation();
	UFUNCTION(BlueprintCallable)
	void StopBezierInterpolation();
	UFUNCTION(BlueprintCallable)
	void ResetInterpolation();

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Bezier")
	float Duration;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Bezier")
	TArray<FVector> Point;

	USceneComponent* Root;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Mesh;

	float Timer;
	bool IsInterpolate;

};
