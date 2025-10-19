// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ExerciceFunction.generated.h"

/**
 * 
 */
UCLASS()
class INTRODUCTIONUNREAL_API UExerciceFunction : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Debug")
	static void PrintMessage(const FString& Message);

	UFUNCTION(BlueprintCallable, Category = "Movement")
	static void TeleportTo(AActor* ActorToTeleport, AActor* TargetActor);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Vector")
	static FVector FindShortestVector(const TArray<FVector>& Vectors);
};
