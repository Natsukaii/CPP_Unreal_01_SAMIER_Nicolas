#include "PickupKey.h"



APickupKey::APickupKey()
{
	PrimaryActorTick.bCanEverTick = false;

}

void APickupKey::Interact_Implementation()
{
	AGameModeBase* GameMode = Cast<AIntroductionUnrealGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (!GameMode)
		return;

	UFlagManager* FlagManager = GameMode->GetComponentByClass<UFlagManager>();
	if (!FlagManager)
		return;

	FlagManager->IncrementFlag(Flag);
	Destroy();
}

FString APickupKey::GetDescription_Implementation()
{
	return FString("Key");
}
