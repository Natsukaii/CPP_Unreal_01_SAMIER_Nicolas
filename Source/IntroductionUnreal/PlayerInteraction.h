// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyTools.h"
#include "Interactable.h"
#include "Camera/CameraComponent.h"
#include "GameHUD.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerInteraction.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INTRODUCTIONUNREAL_API UPlayerInteraction : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerInteraction();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION( BlueprintCallable )
	void UseInteractableActor();
	
private :
	void GetInteractionObject();
	void SetInteractionObject(AActor* Interactible);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	float DetectionRange;

	UCameraComponent* Camera;
	AActor* InteractableActor;

	AGameHUD* Hud;
	
};
