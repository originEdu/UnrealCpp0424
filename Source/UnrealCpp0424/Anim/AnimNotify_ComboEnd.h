// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AnimNotify_ComboEnd.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCPP0424_API UAnimNotify_ComboEnd : public UAnimNotify
{
	GENERATED_BODY()
public:
	FORCEINLINE FString GetNotifyName_Implementation() const
	{
		return TEXT("ComboEnd");
	};
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;

};
