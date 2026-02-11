#pragma once

#include "CoreMinimal.h"
#include "Flag.h"
#include "FlagManager.h"
#include "IntroductionUnrealGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Components/ActorComponent.h"
#include "FlagTrigger.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INTRODUCTIONUNREAL_API UFlagTrigger : public UActorComponent
{
	GENERATED_BODY()

public:	
	UFlagTrigger();

	UFUNCTION( BlueprintCallable )
	bool AreFlagTrigger();

protected:
	virtual void BeginPlay();

private:
	UPROPERTY( EditAnywhere )
	TArray<FFlag> Flags;

	UFlagManager* FlagManager;
};
