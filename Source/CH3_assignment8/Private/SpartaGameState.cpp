#include "SpartaGameState.h"
#include "SpartaGameInstance.h"
#include "SpartaPlayerController.h"
#include "SpartaCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "SpawnVolume.h"
#include "CoinItem.h"
#include "Components/TextBlock.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"

ASpartaGameState::ASpartaGameState()
{
	// 점수 관련 변수
	Score = 0;
	RewardScore = 100;
	TargetScore = 100;

	// 레벨 관련 변수
	Level = 1;							// 이 변수는 원래 강의에서도 사용되지 않네요.
	//LevelDuration = 30.0f;			// 웨이브 기준으로 진행되기에 주석처리해두었습니다.
	CurrentLevelIndex = 0;
	MaxLevels = 3;

	// 웨이브 관련 변수
	Wave = 1;
	WaveDuration = 30.f;
	CurrentWaveIndex = 0;
	MaxWaves = 3;

	// 아이템 관련 변수들
	SpawnedCoinCount = 0;
	CollectedCoinCount = 0;
	MineCount = 0;

}

void ASpartaGameState::BeginPlay()
{
	Super::BeginPlay();

	StartLevel();

	GetWorldTimerManager().SetTimer(HUDUpdateTimerHandle, this, &ASpartaGameState::UpdateHUD, 0.1f, true);
}

int32 ASpartaGameState::GetScore() const
{
	return Score;
}

void ASpartaGameState::AddScore(int32 Amount)
{
	if (UGameInstance* GameInstance = GetGameInstance()) {
		USpartaGameInstance* SpartaGameInstance = Cast<USpartaGameInstance>(GameInstance);
		if (SpartaGameInstance) {
			SpartaGameInstance->AddToScore(Amount);
		}
	}
	Score += Amount;
	if (Score >= RewardScore) {
		UE_LOG(LogTemp, Error, TEXT("Congratulation! You have reached Reward Score: %d"), RewardScore);
		UE_LOG(LogTemp, Error, TEXT("Your character gain 20 bonus health!!"));
		RewardScore += 100;
		if (GetWorld()) {
			if (ASpartaPlayerController* PlayerController = Cast<ASpartaPlayerController>(GetWorld()->GetFirstPlayerController())) {
				if (ASpartaCharacter* Player = Cast<ASpartaCharacter>(PlayerController->GetPawn())) {
					Player->AddMaxHealth(20);
				}
				else
				{
					UE_LOG(LogTemp, Warning, TEXT("Failed to get player character."));
				}
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Failed to get player controller."));
			}
		}
	}
}


void ASpartaGameState::StartLevel()
{
	if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController()) {
		if (ASpartaPlayerController* SpartaPlayerController = Cast<ASpartaPlayerController>(PlayerController)) {
			SpartaPlayerController->ShowGameHUD();
		}
	}

	if (UGameInstance* GameInstance = GetGameInstance()) {
		USpartaGameInstance* SpartaGameInstance = Cast<USpartaGameInstance>(GameInstance);
		if (SpartaGameInstance) {
			CurrentLevelIndex = SpartaGameInstance->CurrentLevelIndex;
		}
	}
	StartWave();
}

//void ASpartaGameState::OnLevelTimeUp()	// 웨이브 기준으로 진행되기에 주석처리해두었습니다.
//{
//	EndLevel();
//}

void ASpartaGameState::OnCoinCollected()
{
	CollectedCoinCount++;
	UE_LOG(LogTemp, Warning, TEXT("Coin Collected: %d / %d"), CollectedCoinCount, SpawnedCoinCount);

	if (SpawnedCoinCount > 0 && CollectedCoinCount >= SpawnedCoinCount) {
		EndWave();
	}
}

void ASpartaGameState::EndLevel()
{
	GetWorldTimerManager().ClearTimer(WaveTimerHandle);

	UGameInstance* GameInstance = GetGameInstance();
	if (GameInstance) {
		USpartaGameInstance* SpartaGameInstance = Cast<USpartaGameInstance>(GameInstance);
		if (SpartaGameInstance) {

			CurrentLevelIndex++;
			SpartaGameInstance->CurrentLevelIndex = CurrentLevelIndex;

			if (SpartaGameInstance->TotalScore < TargetScore * CurrentLevelIndex) {
				OnGameOver();
				return;
			}
		}
	}

	if (CurrentLevelIndex > MaxLevels) {
		OnGameOver();
		return;
	}

	if (LevelMapNames.IsValidIndex(CurrentLevelIndex)) {
		UGameplayStatics::OpenLevel(GetWorld(), LevelMapNames[CurrentLevelIndex]);
	}
	else {
		OnGameOver();
	}
}

void ASpartaGameState::OnGameOver()
{
	if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController()) {
		if (ASpartaPlayerController* SpartaPlayerController = Cast<ASpartaPlayerController>(PlayerController)) {
			SpartaPlayerController->SetPause(true);
			SpartaPlayerController->ShowMainMenu(true, true);
		}
	}
}


void ASpartaGameState::AddMineCount()
{
	MineCount++;
	UE_LOG(LogTemp, Error, TEXT("Current MineCount: %d"), MineCount);
	if (MineCount >= 3) EndLevel();
}

void ASpartaGameState::StartWave() {
	SpawnedCoinCount = 0;
	CollectedCoinCount = 0;

	TArray<AActor*> FoundVolumes;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnVolume::StaticClass(), FoundVolumes);

	const int32 ItemToSpawn = 40;

	for (int32 i = 0; i < ItemToSpawn; i++) {
		if (FoundVolumes.Num() > 0) {
			ASpawnVolume* SpawnVolume = Cast<ASpawnVolume>(FoundVolumes[0]);
			if (SpawnVolume) {
				AActor* SpawnedActor = SpawnVolume->SpawnRandomItem();
				if (SpawnedActor && SpawnedActor->IsA(ACoinItem::StaticClass())) {
					SpawnedCoinCount++;
				}
			}
		}
	}

	GetWorldTimerManager().SetTimer(WaveTimerHandle, this, &ASpartaGameState::IsWaveComplete, WaveDuration, false);
}

void ASpartaGameState::EndWave() {
	GetWorldTimerManager().ClearTimer(WaveTimerHandle);

	UGameInstance* GameInstance = GetGameInstance();
	if (GameInstance) {
		USpartaGameInstance* SpartaGameInstance = Cast<USpartaGameInstance>(GameInstance);
		if (SpartaGameInstance) {

			CurrentWaveIndex++;
			SpartaGameInstance->CurrentWaveIndex = CurrentWaveIndex;

			if (SpartaGameInstance->TotalScore < TargetScore * CurrentWaveIndex) {
				OnGameOver();
				return;
			}
		}
	}

	if (CurrentWaveIndex >= MaxWaves) {
		EndLevel();
		return;
	}

	StartWave();
}
void ASpartaGameState::IsWaveComplete() {
	EndWave();
}

void ASpartaGameState::UpdateHUD()
{
	if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController()) {
		if (ASpartaPlayerController* SpartaPlayerController = Cast<ASpartaPlayerController>(PlayerController)) {
			if (UUserWidget* HUDWidget = SpartaPlayerController->GetHUdWidget()) {

				if (UTextBlock* TimeText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("Time")))) {
					float RemainingTime = GetWorldTimerManager().GetTimerRemaining(WaveTimerHandle);
					TimeText->SetText(FText::FromString(FString::Printf(TEXT("Time: %.1f"), RemainingTime)));
				}

				if (UProgressBar* Time_Bar = Cast<UProgressBar>(HUDWidget->GetWidgetFromName(TEXT("Time_Bar")))) {
					float RemainingTime = GetWorldTimerManager().GetTimerRemaining(WaveTimerHandle);
					float PercentRemainingTime = RemainingTime / WaveDuration;
					Time_Bar->SetPercent(PercentRemainingTime);
					FLinearColor BarColor = FLinearColor::LerpUsingHSV(FLinearColor::Red, FLinearColor::Green, PercentRemainingTime);	// 퍼센트에 따른 색상 변동
					Time_Bar->SetFillColorAndOpacity(BarColor);
				}

				if (UTextBlock* ScoreText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("Score")))) {
					if (UGameInstance* GameInstance = GetGameInstance()) {
						USpartaGameInstance* SpartaGameInstance = Cast<USpartaGameInstance>(GameInstance);
						if (SpartaGameInstance) {
							ScoreText->SetText(FText::FromString(FString::Printf(TEXT("Score: %d"), SpartaGameInstance->TotalScore)));
							if (SpartaGameInstance->TotalScore >= TargetScore * (CurrentWaveIndex + 1)) {
								ScoreText->SetColorAndOpacity(FSlateColor(FLinearColor::Yellow));
							}
							else ScoreText->SetColorAndOpacity(FSlateColor(FLinearColor::White));
						}
					}
				}

				if (UTextBlock* LevelIndexText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("Level")))) {
					LevelIndexText->SetText(FText::FromString(FString::Printf(TEXT("Level: %d"), CurrentLevelIndex + 1)));
				}

				if (UTextBlock* LevelWaveText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("Wave")))) {
					LevelWaveText->SetText(FText::FromString(FString::Printf(TEXT("Wave: %d"), CurrentWaveIndex + 1)));
				}

				if (UProgressBar* HP_Bar = Cast<UProgressBar>(HUDWidget->GetWidgetFromName(TEXT("HP_Bar")))) {
					if (ASpartaCharacter* Player = Cast<ASpartaCharacter>(PlayerController->GetPawn())) {
						HP_Bar->SetPercent(Player->Health / Player->MaxHealth);
					}
				}

			}
		}
	}
}
