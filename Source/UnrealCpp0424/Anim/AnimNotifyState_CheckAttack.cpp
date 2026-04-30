// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotifyState_CheckAttack.h"
#include "UnrealCpp0424/UnrealCpp0424.h"
//시작할 때
void UAnimNotifyState_CheckAttack::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);
	//UE_LOG(LogOrigin, Log, TEXT("Begin"));
}

//매 프레임마다
void UAnimNotifyState_CheckAttack::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyTick(MeshComp, Animation, FrameDeltaTime, EventReference);
	//UE_LOG(LogOrigin, Log, TEXT("Tick"));
}

//끝날 때
void UAnimNotifyState_CheckAttack::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);
	//UE_LOG(LogOrigin, Log, TEXT("End"));
}
