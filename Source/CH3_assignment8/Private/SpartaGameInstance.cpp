#include "SpartaGameInstance.h"
#include "SpartaCharacter.h"
#include "Kismet\GameplayStatics.h"

USpartaGameInstance::USpartaGameInstance()
{
	TotalScore = 0;
	RewardScore = 100;
	CurrentLevelIndex = 0;
	CurrentWaveIndex = 0;
	MaxHealth = 100;
}

void USpartaGameInstance::AddToScore(int32 Amount)
{
	TotalScore += Amount;
	UE_LOG(LogTemp, Warning, TEXT("Total Score Updateed: %d"), TotalScore);

	if (TotalScore >= RewardScore) {
		AddToHealth(20);
		UE_LOG(LogTemp, Error, TEXT("Congratulation! You have reached Reward Score: %d"), RewardScore);
		UE_LOG(LogTemp, Error, TEXT("Your character gain 20 bonus health!! Now your MaxHealth: %d"), MaxHealth);
		RewardScore += 100;
		if (GetWorld()) {
			if (ASpartaCharacter* Player = Cast<ASpartaCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0))) {
					Player->ChangeMaxHealth(MaxHealth);
			}
		}
	}
}

void USpartaGameInstance::AddToHealth(int32 Amount)
{
	MaxHealth += Amount;

}

