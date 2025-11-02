// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExerciceActor.generated.h"

UCLASS()
class INTRODUCTIONUNREAL_API AExerciceActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AExerciceActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private: //Variables
	
//	UStaticMesh* CubeMesh;
//	UStaticMesh* SphereMesh;
//
//	USceneComponent* Root;
//
//	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
//	UStaticMeshComponent* MeshComponent;
//
//	UPROPERTY(EditInstanceOnly)
//	bool bIsCube;
//
//private: //Fonctions
//	virtual void OnConstruction(const FTransform& Transform) override;

};
