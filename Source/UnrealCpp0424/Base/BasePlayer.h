// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BasePlayer.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputAction;
struct FInputActionValue;

UENUM(BlueprintType)
enum class EPoseState : uint8
{
	Stand = 0 UMETA(DisplayName="Stand"),
	Crouch = 10 UMETA(DisplayName = "Crouch"),
	Prone = 20 UMETA(DisplayName = "Prone"),
};

UCLASS()
class UNREALCPP0424_API ABasePlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABasePlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USpringArmComponent> SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UCameraComponent> Camera;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "input")
	TObjectPtr<UInputAction> IA_Look;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "input")
	TObjectPtr<UInputAction> IA_Move;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "input")
	TObjectPtr<UInputAction> IA_Lean;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "input")
	TObjectPtr<UInputAction> IA_Jump;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "input")
	TObjectPtr<UInputAction> IA_Attack;

	void Look(const FInputActionValue& Value);
	void Move(const FInputActionValue& Value);
	void Lean(const FInputActionValue& Value);
	void Attack(const FInputActionValue& Value);

	FRotator GetAimOffset() const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "data")
	float LeanAngle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "data")
	bool bIsBigHeadMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	EPoseState CurrentPoseState = EPoseState::Stand;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	uint8 bIsWeaponEqipped : 1 = false ;
};
