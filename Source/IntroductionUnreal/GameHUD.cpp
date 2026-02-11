// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHUD.h"

void AGameHUD::BeginPlay()
{
	Super::BeginPlay();

	if (WidgetClass != nullptr)
	{
		InteractionWidget = CreateWidget<UInteractionWidget>(GetWorld(), WidgetClass);
		InteractionWidget->AddToViewport();
	}
}

void AGameHUD::SetInteractionText(FString Text)
{
	InteractionWidget->SetText(Text);
}
