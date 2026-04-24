// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BasePC.generated.h"

class UInputMappingContext;
/**
 * 
 */
UCLASS()
class UNREALCPP0424_API ABasePC : public APlayerController
{
	GENERATED_BODY()
public:
	ABasePC();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> IMC_Base;

	virtual void OnPossess(APawn* aPawn) override;
	virtual void OnUnPossess() override;
};
