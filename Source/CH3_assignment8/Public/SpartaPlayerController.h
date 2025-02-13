#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SpartaPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class CH3_ASSIGNMENT8_API ASpartaPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ASpartaPlayerController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputMappingContext* InputMappingContext;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* MoveAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* JumpAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* LookAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* SprintAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputMappingContext* InventoryMappingContext;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* OpenInventoryAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* MenuOpen;



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	bool IsInventory;		// 인벤토리가 열려있는지 확인하는 변수

	UFUNCTION(BlueprintCallable, Category = "Input|Actions")
	void ToggleInventory(); // 인벤토리로 전환하는 함수

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
	TSubclassOf<UUserWidget> HUDWidgetClass;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "HUD")
	UUserWidget* HUDWidgetInstance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Menu")
	TSubclassOf<UUserWidget> MainMenuWidgetClass;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Menu")
	UUserWidget* MainMenuWidgetInstance;

	bool IsMenuOpen;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Menu")
	bool bIsStarted;

	UFUNCTION(BlueprintPure, Category = "HUD")
	UUserWidget* GetHUdWidget() const;

	UFUNCTION(BlueprintCallable, Category = "HUD")
	void ShowGameHUD();
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void ShowMainMenu(bool bIsStart = false, bool bIsEnd = false);
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void StartGame();
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void ResumeGame();
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void EndGame();

protected:
	virtual void BeginPlay() override;
};
