#include "FlagTrigger.h"


UFlagTrigger::UFlagTrigger()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UFlagTrigger::BeginPlay()
{
	Super::BeginPlay();

	AGameModeBase* GameMode = Cast<AIntroductionUnrealGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (!GameMode)
		return;

	FlagManager = GameMode->GetComponentByClass<UFlagManager>();
}

bool UFlagTrigger::AreFlagTrigger()
{
	if (FlagManager == nullptr)
		return false;

	for (FFlag Flag : Flags)
	{
		int FlagValue = FlagManager->GetFlagValue(Flag.FlagName);
		if (FlagValue == -1 || FlagValue != Flag.FlagValue)
			return false;
	}
	
	return true;
}

