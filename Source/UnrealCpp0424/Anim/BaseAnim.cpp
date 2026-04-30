// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAnim.h"
#include "KismetAnimationLibrary.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "../Base/BasePlayer.h"

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
	ABasePlayer* Player = Cast<ABasePlayer>(TryGetPawnOwner());
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
		
		LeanAngle = FMath::FInterpTo(LeanAngle,Player->LeanAngle, DeltaSeconds, InterpSpeed);

		//빅헤드모드
		if (Player->bIsBigHeadMode)
		{
			HeadScale = FMath::FInterpTo(HeadScale, 5.0f, DeltaSeconds, InterpSpeed);
		}
		else
		{
			HeadScale = FMath::FInterpTo(HeadScale, 1.0f, DeltaSeconds, InterpSpeed);
		}

		AimPitch = Player->GetAimOffset().Pitch;
		AimYaw = Player->GetAimOffset().Yaw;

		CurrentPoseState = Player->CurrentPoseState;
		bIsWeaponEqipped = Player->bIsWeaponEqipped;
	}

}

void UBaseAnim::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
}

void UBaseAnim::AnimNotify_CheckCombo_CPP()
{
}
