// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "UnrealCpp0424/UnrealCpp0424.h"
#include "AnimNotify_CheckCombo.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCPP0424_API UAnimNotify_CheckCombo : public UAnimNotify
{
	GENERATED_BODY()
public:
	FORCEINLINE FString GetNotifyName_Implementation() const
	{
		return TEXT("");
	};
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
};
