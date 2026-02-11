// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExerciceInterface.h"
#include "ExerciceActor.generated.h"

UCLASS()
class INTRODUCTIONUNREAL_API AExerciceActor : public AActor, public IExerciceInterface
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
	
	UStaticMesh* CubeMesh;
	UStaticMesh* SphereMesh;

	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditInstanceOnly)
	bool bIsCube;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	AActor* Actor;

private: //Fonctions
	virtual void OnConstruction(const FTransform& Transform) override;

public: //fonction
	//je n'ai pas fait la r�f�rence car �a ne compilait pas avec
	virtual const FVector GetLocation_Implementation() override;
};
