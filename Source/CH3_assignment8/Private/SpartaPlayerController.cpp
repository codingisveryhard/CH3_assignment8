#include "SpartaPlayerController.h"
#include "SpartaGameState.h"
#include "SpartaGameInstance.h"
#include "EnhancedInputSubsystems.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Components/Widget.h"


ASpartaPlayerController::ASpartaPlayerController()
	: InputMappingContext(nullptr)
	, MoveAction(nullptr)
	, LookAction(nullptr)
	, SprintAction(nullptr)
	, JumpAction(nullptr)
	, InventoryMappingContext(nullptr)	// 인벤토리 오픈 시 작동할 맵핑
	, OpenInventoryAction(nullptr)		// 인벤토리를 열고 닫을 때 사용할 입력
	, IsInventory(false)				// 인벤토리가 열렸는지 확인
	, MenuOpen(nullptr)
	, HUDWidgetClass(nullptr)
	, HUDWidgetInstance(nullptr)
	, MainMenuWidgetClass(nullptr)
	, MainMenuWidgetInstance(nullptr)

{
}

void ASpartaPlayerController::ToggleInventory()
{
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	if (Subsystem)
	{

		if (!IsInventory)
		{
			// 인벤토리가 열리면 캐릭터 매핑을 제거하고 인벤토리 매핑을 추가한다.
			Subsystem->RemoveMappingContext(InputMappingContext);
			Subsystem->AddMappingContext(InventoryMappingContext, 1);	// 우선순위 1
		}
		else
		{
			// 인벤토리가 닫히면 inventory 매핑을 제거하고 다시 캐릭터 매핑을 추가한다.
			Subsystem->RemoveMappingContext(InventoryMappingContext);
			Subsystem->AddMappingContext(InputMappingContext, 0);		// 우선순위 0
		}
		// 인벤토리가 토글되면 참<=>거짓으로 전환한다.
		IsInventory = !IsInventory;
	}
}

void ASpartaPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (InputMappingContext)
			{
				Subsystem->AddMappingContext(InputMappingContext, 0);
			}
		}
	}

	FString CurrentMapName = GetWorld()->GetMapName();
	if (CurrentMapName.Contains("MainLevel")) {
		ShowMainMenu(false);
	}
}

UUserWidget* ASpartaPlayerController::GetHUdWidget() const
{
	return HUDWidgetInstance;
}

void ASpartaPlayerController::ShowGameHUD()
{
	if (HUDWidgetInstance) {
		HUDWidgetInstance->RemoveFromParent();
		HUDWidgetInstance = nullptr;
	}

	if (MainMenuWidgetInstance) {
		MainMenuWidgetInstance->RemoveFromParent();
		MainMenuWidgetInstance = nullptr;
	}

	if (HUDWidgetClass) {
		HUDWidgetInstance = CreateWidget<UUserWidget>(this, HUDWidgetClass);
		if (HUDWidgetInstance) {
			HUDWidgetInstance->AddToViewport();

			bShowMouseCursor = false;
			SetInputMode(FInputModeGameOnly());

			ASpartaGameState* SpartaGameState = GetWorld() ? GetWorld()->GetGameState<ASpartaGameState>() : nullptr;
			if (SpartaGameState) {
				SpartaGameState->UpdateHUD();
			}
		}
	}
}

void ASpartaPlayerController::ShowMainMenu(bool bIsRestart)
{
	UE_LOG(LogTemp, Warning, TEXT("IsMenu?"));
	if (HUDWidgetInstance) {
		HUDWidgetInstance->RemoveFromParent();
		HUDWidgetInstance = nullptr;
	}

	if (MainMenuWidgetInstance) {
		MainMenuWidgetInstance->RemoveFromParent();
		MainMenuWidgetInstance = nullptr;
	}

	if (MainMenuWidgetClass) {
		MainMenuWidgetInstance = CreateWidget<UUserWidget>(this, MainMenuWidgetClass);
		if (MainMenuWidgetInstance) {
			MainMenuWidgetInstance->AddToViewport();

			bShowMouseCursor = true;
			SetInputMode(FInputModeUIOnly());
		}

		UButton* StartButton = Cast<UButton>(MainMenuWidgetInstance->GetWidgetFromName(TEXT("StartButton")));
		UButton* RestartButton = Cast<UButton>(MainMenuWidgetInstance->GetWidgetFromName(TEXT("RestartButton")));
		if (StartButton && RestartButton) {
			if (bIsRestart) {
				StartButton->SetIsEnabled(false);
				RestartButton->SetIsEnabled(true);

			}
			else {
				StartButton->SetIsEnabled(true);
				RestartButton->SetIsEnabled(false);
			}
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("StartButton or RestartButton is nullptr"));
		}

		if (bIsRestart) {
			UFunction* PlayAnimFunc = MainMenuWidgetInstance->FindFunction(FName("PlayGameOverAnim"));
			if (PlayAnimFunc) {
				MainMenuWidgetInstance->ProcessEvent(PlayAnimFunc, nullptr);
			}

			if (UTextBlock* TotalScoreText = Cast<UTextBlock>(MainMenuWidgetInstance->GetWidgetFromName("TotalScoreText"))) {
				if (USpartaGameInstance* SpartaGameInstance = Cast<USpartaGameInstance>(UGameplayStatics::GetGameInstance(this))) {
					TotalScoreText->SetText(FText::FromString(FString::Printf(TEXT("Total Score: %d"), SpartaGameInstance->TotalScore)));
				}
			}
		}
	}
}

void ASpartaPlayerController::StartGame()
{
	if (USpartaGameInstance* SpartaGameInstance = Cast<USpartaGameInstance>(UGameplayStatics::GetGameInstance(this))) {
		SpartaGameInstance->CurrentLevelIndex = 0;
		SpartaGameInstance->TotalScore = 0;
	}

	UGameplayStatics::OpenLevel(GetWorld(), FName("BasicLevel"));
	SetPause(false);
}
