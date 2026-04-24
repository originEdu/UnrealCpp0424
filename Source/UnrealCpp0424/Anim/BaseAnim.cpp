// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAnim.h"
#include "KismetAnimationLibrary.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

UBaseAnim::UBaseAnim()
{
}

void UBaseAnim::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
}

void UBaseAnim::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	ACharacter* Player = Cast<ACharacter>(TryGetPawnOwner());
	if (Player)
	{
		FVector CurrentAccel = Player->GetCharacterMovement()->GetCurrentAcceleration();
		float InterpSpeed = 6.0f;
		SmoothVelocity = FMath::VInterpTo(SmoothVelocity, CurrentAccel, DeltaSeconds, InterpSpeed);
		Speed = SmoothVelocity.Size2D();
		if (!FMath::IsNearlyZero(Speed))
		{
			Direction = UKismetAnimationLibrary::CalculateDirection(SmoothVelocity, Player->GetActorRotation());
		}
	}
}

void UBaseAnim::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
}
