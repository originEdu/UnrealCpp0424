// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "BaseAnim.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCPP0424_API UBaseAnim : public UAnimInstance
{
	GENERATED_BODY()
public:
	UBaseAnim();
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Data")
	float Direction=0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Data")
	float Speed=0;

	FVector SmoothVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Data")
	float LeanAngle = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Data")
	float HeadScale = 1.0f;
};
