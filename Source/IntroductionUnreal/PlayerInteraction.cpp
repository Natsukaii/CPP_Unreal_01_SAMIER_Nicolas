// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerInteraction.h"

// Sets default values for this component's properties
UPlayerInteraction::UPlayerInteraction()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	DetectionRange = 0.0f;
	Camera = nullptr;
	InteractableActor = nullptr;
	Hud = nullptr;
}


// Called when the game starts
void UPlayerInteraction::BeginPlay()
{
	Super::BeginPlay();

	Camera = GetOwner()->GetComponentByClass<UCameraComponent>();
	Hud = Cast<AGameHUD>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());
}


// Called every frame
void UPlayerInteraction::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	GetInteractionObject();
}

void UPlayerInteraction::UseInteractableActor()
{
	if (InteractableActor != nullptr)
		IInteractable::Execute_Interact(InteractableActor);
}

void UPlayerInteraction::GetInteractionObject()
{
	UWorld* World = GetWorld();
	if (World == nullptr)
		return;

	FHitResult Hit;
	FVector Start = Camera->GetComponentLocation();
	FVector End = Start + Camera->GetForwardVector() * DetectionRange;
	
	ECollisionChannel Channel(ECC_GameTraceChannel1);
	
	const FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());

	// test de linetrace
	if (World->LineTraceSingleByChannel(OUT Hit, Start, End, Channel, TraceParams))
	{
		//UMyTools::DebugLog(Hit.GetActor()->GetName());

		AActor* HitActor = Hit.GetActor();
		if (HitActor != nullptr && HitActor->Implements<UInteractable>())
		{
			SetInteractionObject(HitActor);
		}
		else
			SetInteractionObject(nullptr);
	}
	else
	{
		SetInteractionObject(nullptr);
	}
			
}

void UPlayerInteraction::SetInteractionObject(AActor* Interactible)
{
	if (Interactible == InteractableActor)
		return;
	
	InteractableActor = Interactible;

	if (InteractableActor == nullptr)
		Hud->SetInteractionText("");
	else
		Hud->SetInteractionText(IInteractable::Execute_GetDescription(InteractableActor));
}

