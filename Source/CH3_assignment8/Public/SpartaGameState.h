#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "MineItem.h"
#include "SpartaGameState.generated.h"

DECLARE_MULTICAST_DELEGATE(FMineDelegate);

UCLASS()
class CH3_ASSIGNMENT8_API ASpartaGameState : public AGameState
{
	GENERATED_BODY()

public:
	ASpartaGameState();

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Score")
	int32 Score;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score")
	int32 RewardScore;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score")
	int32 Level;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Coin")
	int32 SpawnedCoinCount;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Coin")
	int32 CollectedCoinCount;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Level")
	float LevelDuration;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Level")
	int32 CurrentLevelIndex;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Level")
	int32 MaxLevels;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Level")
	TArray<FName> LevelMapNames;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Level")
	int32 TargetScore;

	FTimerHandle LevelTimerHandle;
	FTimerHandle HUDUpdateTimerHandle;

	UFUNCTION(BlueprintPure, Category = "Score")
	int32 GetScore() const;
	UFUNCTION(BlueprintCallable, Category = "Score")
	void AddScore(int32 Amount);
	UFUNCTION(BlueprintCallable, Category = "Level")
	void OnGameOver();

	void StartLevel();

	void OnLevelTimeUp();

	void OnCoinCollected();

	void EndLevel();

	void UpdateHUD();

	FMineDelegate OnTriggered;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mine")
	int32 MineCount;
	void AddMineCount();
};
