// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "InteractionWidget.h"
#include "GameHUD.generated.h"

/**
 * 
 */
UCLASS()
class INTRODUCTIONUNREAL_API AGameHUD : public AHUD
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void SetInteractionText(FString Text);
private:
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = true))
	TSubclassOf<UInteractionWidget> WidgetClass;
	
	UInteractionWidget* InteractionWidget;
	
};
