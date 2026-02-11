#include "FlagManager.h"

UFlagManager::UFlagManager()
{
	PrimaryComponentTick.bCanEverTick = false;

	Flags = TMap<FGameplayTag, FFlag>();
}

int UFlagManager::GetFlagValue(FGameplayTag FlagName) const
{
	if (Flags.Contains(FlagName))
		return Flags[FlagName].FlagValue;

	UE_LOG(LogTemp, Error, TEXT("Tag Not Found : %s"), *FlagName.ToString());
	return -1;
}

void UFlagManager::SetFlag(FGameplayTag FlagName, int Value)
{
	if (!Flags.Contains(FlagName))
	{
		UE_LOG(LogTemp, Error, TEXT("Tag Not Found : %s"), *FlagName.ToString());
		return;
	}

	if (Value < 0)
	{
		UE_LOG(LogTemp, Error, TEXT("Negative flag value : %s, %d"), *FlagName.ToString(), Value);
		return;
	}
		
	Flags[FlagName].FlagValue = Value;
}

void UFlagManager::IncrementFlag(FGameplayTag FlagName)
{
	if (!Flags.Contains(FlagName))
	{
		UE_LOG(LogTemp, Error, TEXT("Tag Not Found : %s"), *FlagName.ToString());
		return;
	}
	Flags[FlagName].FlagValue++;
}

void UFlagManager::DecrementFlag(FGameplayTag FlagName)
{
	if (!Flags.Contains(FlagName))
	{
		UE_LOG(LogTemp, Error, TEXT("Tag Not Found : %s"), *FlagName.ToString());
		return;
	}

	if (Flags[FlagName].FlagValue <= 0)
	{
		UE_LOG(LogTemp, Error, TEXT("Negative flag value : %s, -1"), *FlagName.ToString());
		return;
	}
	
	Flags[FlagName].FlagValue--;
}

void UFlagManager::FlipFlag(FGameplayTag FlagName)
{
	if (!Flags.Contains(FlagName))
	{
		UE_LOG(LogTemp, Error, TEXT("Tag Not Found : %s"), *FlagName.ToString());
		return;
	}

	if (Flags[FlagName].FlagValue == 0)
		Flags[FlagName].FlagValue = 1;
	else if (Flags[FlagName].FlagValue == 1)
		Flags[FlagName].FlagValue = 0;
	else
		UE_LOG(LogTemp, Error, TEXT("Try to flip a non boolean flag : %s"), *FlagName.ToString());
}

void UFlagManager::resetFlag(FGameplayTag FlagName)
{
	if (!Flags.Contains(FlagName))
	{
		UE_LOG(LogTemp, Error, TEXT("Tag Not Found : %s"), *FlagName.ToString());
		return;
	}
	Flags[FlagName].FlagValue = 0;
}

void UFlagManager::BeginPlay()
{
	Super::BeginPlay();

	for (FGameplayTag Tag : FlagNames.GetGameplayTagArray())
	{
		FFlag Flag = FFlag(Tag, 0);
		Flags.Add(Tag, Flag);
	}

	
}

