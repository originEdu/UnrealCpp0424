// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotify_CheckCombo.h"

void UAnimNotify_CheckCombo::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	//캐릭터 주먹 체크
	UE_LOG(LogOrigin, Log, TEXT("NotifyOn"));
}
