#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SpartaCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UWidgetComponent;
struct FInputActionValue;

UCLASS()
class CH3_ASSIGNMENT8_API ASpartaCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASpartaCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	USpringArmComponent* SpringArmComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* CameraComp;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
	UWidgetComponent* OverheadWidget;

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character| Health")
	float MaxHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character| Health")
	float Health;

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION()
	void Move(const FInputActionValue& value);
	UFUNCTION(BlueprintCallable, Category = "Character| Actions")
	void StartJump(const FInputActionValue& value);
	UFUNCTION(BlueprintCallable, Category = "Character| Actions")
	void StopJump(const FInputActionValue& value);
	UFUNCTION()
	void Look(const FInputActionValue& value);
	UFUNCTION(BlueprintCallable, Category = "Character| Actions")
	void StartSprint(const FInputActionValue& value);
	UFUNCTION(BlueprintCallable, Category = "Character| Actions")
	void StopSprint(const FInputActionValue& value);
	UFUNCTION(Blueprintpure, Category = "Character| Health")
	float GetHealth() const;
	UFUNCTION(BlueprintCallable, Category = "Character| Health")
	void AddHealth(float Amount);
	UFUNCTION(BlueprintCallable, Category = "Character| Health")
	void ChangeMaxHealth(float Amount);

	void OnDeath();

	void OpenMenu(const FInputActionValue& value);

	void UpdateOverheadHP();



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character| Ke")
	TArray<FName> Keys;

	UFUNCTION(BlueprintCallable, Category = "Character| Actions")
	void AddKey(FName ItemType);
	UFUNCTION(BlueprintCallable, Category = "Character| Actions")
	bool HasKey(FName ItemType);

public:
	float NormalSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character| Properities")
	float SprintSpeedMultiplier;
	float SprintSpeed;

	bool IsJumping;
	int32 JumpCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character| Properities")
	float MouseSensitivity;

	FTimerHandle OverHeadUpdateTimerHandle;
};

