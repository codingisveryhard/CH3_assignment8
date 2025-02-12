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

	// 레벨 관련 변수들
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Level")
	int32 CurrentLevelIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score")
	int32 Level;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Level")
	int32 MaxLevels;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Level")
	TArray<FName> LevelMapNames;
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Level")	// 웨이브 기준으로 진행되기에 주석처리해두었습니다.
	//float LevelDuration;
	//FTimerHandle LevelTimerHandle;

	// 웨이브 관련 변수들
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Wave")
	int32 Wave;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Wave")
	int32 CurrentWaveIndex;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Wave")
	int32 MaxWaves;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Wave")
	float WaveDuration;

	FTimerHandle WaveTimerHandle;

	// 점수 관련 변수들
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Score")
	int32 Score;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score")
	int32 RewardScore;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Level")
	int32 TargetScore;

	// 코인 관련 변수들
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Coin")
	int32 SpawnedCoinCount;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Coin")
	int32 CollectedCoinCount;

	// 지뢰 관련 변수
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mine")
	int32 MineCount;

	FMineDelegate OnTriggered;


	FTimerHandle HUDUpdateTimerHandle;


	// 각종 함수 모음
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure, Category = "Score")
	int32 GetScore() const;
	UFUNCTION(BlueprintCallable, Category = "Score")
	void AddScore(int32 Amount);
	UFUNCTION(BlueprintCallable, Category = "Level")
	void OnGameOver();

	void StartLevel();

	//void OnLevelTimeUp();

	void OnCoinCollected();

	void EndLevel();

	void UpdateHUD();

	void AddMineCount();

	void StartWave();

	void EndWave();
	
	void IsWaveComplete();


};
