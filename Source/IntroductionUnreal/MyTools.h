#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyTools.generated.h" // toujours en dernier


UCLASS()
class INTRODUCTIONUNREAL_API UMyTools : public UObject
{
	GENERATED_BODY() //ne pas toucher

public:
	static void DebugLog(const FString& Message);
	static void DebugLogWarning(const FString& Message);
	static void DebugLogError(const FString& Message);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "MyTools")
	static FVector MyUnclampLerp(FVector A, FVector B, float T);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "MyTools")
	static float MyClamp(float Value, float Min, float Max);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "MyTools")
	static FVector MyLerp(FVector A, FVector B, float T);
	//UFUNCTION(BlueprintCallable, BlueprintPure, Category = "MyTools")
	//static 

	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "MyTools")
	static FVector BezierInterp(const TArray<FVector>& Points, float Alpha);
};