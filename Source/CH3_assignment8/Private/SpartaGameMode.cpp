#include "SpartaGameMode.h"
#include "SpartaCharacter.h"
#include "SpartaPlayerController.h"
#include "SpartaGameState.h"



ASpartaGameMode::ASpartaGameMode()
{
    DefaultPawnClass = ASpartaCharacter::StaticClass();
    PlayerControllerClass = ASpartaPlayerController::StaticClass();
    GameStateClass = ASpartaGameState::StaticClass();
}

void ASpartaGameMode::BeginPlay()
{
    Super::BeginPlay();

    ASpartaGameState* SpartaGameState = GetWorld()->GetGameState<ASpartaGameState>();
    AMineItem* MineItem = GetWorld()->SpawnActor<AMineItem>();

    if (SpartaGameState && MineItem)
    {
        // 델리게이트 바인딩
        SpartaGameState->OnTriggered.AddUObject(SpartaGameState, &ASpartaGameState::AddMineCount);
    }
}
