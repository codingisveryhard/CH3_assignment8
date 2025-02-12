#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "MineItem.h"
#include "SpartaGameState.h"
#include "SpartaGameMode.generated.h"


UCLASS()
class CH3_ASSIGNMENT8_API ASpartaGameMode : public AGameMode
{
	GENERATED_BODY()

	ASpartaGameMode();

	void virtual BeginPlay() override;

};

