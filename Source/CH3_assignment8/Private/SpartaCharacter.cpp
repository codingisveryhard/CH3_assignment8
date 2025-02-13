#include "SpartaCharacter.h"
#include "SpartaPlayerController.h"
#include "SpartaGameState.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/WidgetComponent.h"
#include "Components/TextBlock.h"

ASpartaCharacter::ASpartaCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->TargetArmLength = 300.0f;
	SpringArmComp->SocketOffset = FVector(0.0f, 0.0f, 0.0f);
	SpringArmComp->bUsePawnControlRotation = true;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);
	CameraComp->bUsePawnControlRotation = false;

	OverheadWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("OverheadWidget"));
	OverheadWidget->SetupAttachment(GetMesh());
	OverheadWidget->SetWidgetSpace(EWidgetSpace::Screen);

	NormalSpeed = 600.0f;
	SprintSpeedMultiplier = 1.7f;
	SprintSpeed = NormalSpeed * SprintSpeedMultiplier;

	GetCharacterMovement()->MaxWalkSpeed = NormalSpeed;

	JumpCount = 0;
	IsJumping = false;
	MouseSensitivity = 1.0f;

	MaxHealth = 100.0f;
	Health = MaxHealth;
}

void ASpartaCharacter::BeginPlay()
{
	Super::BeginPlay();

	UpdateOverheadHP();
}

void ASpartaCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpartaCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedeInput = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		if (ASpartaPlayerController* PlayerController = Cast<ASpartaPlayerController>(GetController())) {
			if (PlayerController->MoveAction) {
				EnhancedeInput->BindAction(
					PlayerController->MoveAction,
					ETriggerEvent::Triggered,
					this,
					&ASpartaCharacter::Move
				);
			}
		}
	}
	if (UEnhancedInputComponent* EnhancedeInput = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		if (ASpartaPlayerController* PlayerController = Cast<ASpartaPlayerController>(GetController())) {
			if (PlayerController->JumpAction) {
				EnhancedeInput->BindAction(
					PlayerController->JumpAction,
					ETriggerEvent::Triggered,
					this,
					&ASpartaCharacter::StartJump
				);

				EnhancedeInput->BindAction(
					PlayerController->JumpAction,
					ETriggerEvent::Completed,
					this,
					&ASpartaCharacter::StopJump
				);
			}
		}
	}

	if (UEnhancedInputComponent* EnhancedeInput = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		if (ASpartaPlayerController* PlayerController = Cast<ASpartaPlayerController>(GetController())) {
			if (PlayerController->LookAction) {
				EnhancedeInput->BindAction(
					PlayerController->LookAction,
					ETriggerEvent::Triggered,
					this,
					&ASpartaCharacter::Look
				);
			}
		}
	}
	if (UEnhancedInputComponent* EnhancedeInput = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		if (ASpartaPlayerController* PlayerController = Cast<ASpartaPlayerController>(GetController())) {
			if (PlayerController->SprintAction) {
				EnhancedeInput->BindAction(
					PlayerController->SprintAction,
					ETriggerEvent::Triggered,
					this,
					&ASpartaCharacter::StartSprint
				);

				EnhancedeInput->BindAction(
					PlayerController->SprintAction,
					ETriggerEvent::Completed,
					this,
					&ASpartaCharacter::StopSprint
				);
			}
		}
	}
	if (UEnhancedInputComponent* EnhancedeInput = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		if (ASpartaPlayerController* PlayerController = Cast<ASpartaPlayerController>(GetController())) {
			if (PlayerController->MenuOpen) {
				EnhancedeInput->BindAction(
					PlayerController->MenuOpen,
					ETriggerEvent::Completed,
					this,
					&ASpartaCharacter::OpenMenu
				);
			}
		}
	}
}

void ASpartaCharacter::Move(const FInputActionValue& Value)
{
	if (!Controller) return;

	const FVector2D MoveInput = Value.Get<FVector2D>();

	if (!FMath::IsNearlyZero(MoveInput.X)) {
		AddMovementInput(GetActorForwardVector(), MoveInput.X);
	}
	if (!FMath::IsNearlyZero(MoveInput.Y)) {
		AddMovementInput(GetActorRightVector(), MoveInput.Y);
	}
}
void ASpartaCharacter::StartJump(const FInputActionValue& Value)
{
	if (Value.Get<bool>() && !IsJumping) {
		Jump();
		JumpCount++;
		IsJumping = true;
		UE_LOG(LogTemp, Warning, TEXT("Start Jump!"));
		UE_LOG(LogTemp, Warning, TEXT("JumpCount : %d"), JumpCount);
	}
}
void ASpartaCharacter::StopJump(const FInputActionValue& Value)
{
	if (!Value.Get<bool>() && IsJumping) {
		StopJumping();
		IsJumping = false;
		UE_LOG(LogTemp, Warning, TEXT("Stop Jump!"));
	}
}
void ASpartaCharacter::Look(const FInputActionValue& Value)
{
	if (!Controller) return;
	FVector2D LookInput = Value.Get<FVector2D>();

	AddControllerYawInput(LookInput.X * MouseSensitivity);
	AddControllerPitchInput(LookInput.Y * MouseSensitivity);
}
void ASpartaCharacter::StartSprint(const FInputActionValue& Value)
{
	if (!Controller) return;

	if (GetCharacterMovement()) {
		GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
	}
}
void ASpartaCharacter::StopSprint(const FInputActionValue& Value)
{
	if (!Controller) return;

	if (GetCharacterMovement()) {
		GetCharacterMovement()->MaxWalkSpeed = NormalSpeed;
	}

}

float ASpartaCharacter::GetHealth() const
{
	return Health;
}

void ASpartaCharacter::AddHealth(float Amount)
{
	Health = FMath::Clamp(Health + Amount, 0.0f, MaxHealth);
	UpdateOverheadHP();
}

void ASpartaCharacter::AddMaxHealth(float Amount)
{
	MaxHealth += Amount;
}

void ASpartaCharacter::AddKey(FName ItemType)
{
	Keys.Add(ItemType);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow,
		FString::Printf(TEXT("Key added to inventory!")));
}

bool ASpartaCharacter::HasKey(FName ItemType)
{
	return Keys.Contains(ItemType);
}

float ASpartaCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float ActualDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	Health = FMath::Clamp(Health - DamageAmount, 0.0f, MaxHealth);
	UpdateOverheadHP();

	if (Health <= 0) {
		OnDeath();
	}

	return ActualDamage;
}

void ASpartaCharacter::OnDeath() {
	ASpartaGameState* SpartaGameState = GetWorld() ? GetWorld()->GetGameState<ASpartaGameState>() : nullptr;
	if (SpartaGameState) {
		SpartaGameState->OnGameOver();
	}
}

void ASpartaCharacter::OpenMenu(const FInputActionValue& value)
{
	ASpartaPlayerController* PlayerController = Cast<ASpartaPlayerController>(GetController());
	if (PlayerController) {
		PlayerController->ShowMainMenu(true);
	}
}

void ASpartaCharacter::UpdateOverheadHP()
{
	if (!OverheadWidget) return;

	UUserWidget* OverheadWidgetInstance = OverheadWidget->GetUserWidgetObject();
	if (!OverheadWidgetInstance) return;

	if (UTextBlock* HPText = Cast<UTextBlock>(OverheadWidgetInstance->GetWidgetFromName(TEXT("OverHeadHP")))) {
		HPText->SetText(FText::FromString(FString::Printf(TEXT("%.0f / %.0f"), Health, MaxHealth)));
	}
}
