// Fill out your copyright notice in the Description page of Project Settings.


#include "ExerciceFunction.h"

void UExerciceFunction::PrintMessage(const FString& Message)
{
	UE_LOG(LogTemp, Display, TEXT("%s"), *Message)
}

void UExerciceFunction::TeleportTo(AActor* ActorToTeleport, AActor* TargetActor)
{
	if (!ActorToTeleport || !TargetActor)
		return;

	FVector TargetLocation = TargetActor->GetActorLocation();
	ActorToTeleport->SetActorLocation(TargetLocation);
}

FVector UExerciceFunction::FindShortestVector(const TArray<FVector>& Vectors)
{
	if (Vectors.Num() == 0)
		return FVector();
	else if (Vectors.Num() == 1)
		return Vectors[0];

	float ShortestSize = (Vectors[0].X * Vectors[0].X + Vectors[0].Y * Vectors[0].Y + Vectors[0].Z * Vectors[0].Z);

	int i = 1;
	for (; i < Vectors.Num(); i++)
	{
		float CurrentSize = (Vectors[i].X * Vectors[i].X + Vectors[i].Y * Vectors[i].Y + Vectors[i].Z * Vectors[i].Z);

		if (CurrentSize < ShortestSize)
		{
			ShortestSize = CurrentSize;
		}
	}

	return Vectors[i];
}