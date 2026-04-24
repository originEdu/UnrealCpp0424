// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePC.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

ABasePC::ABasePC()
{
}

void ABasePC::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

    if (ULocalPlayer* LP = GetLocalPlayer())
    {
        if (auto* Subsystem = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
        {
            Subsystem->AddMappingContext(IMC_Base, 0);
        }
    }
}

void ABasePC::OnUnPossess()
{
	Super::OnUnPossess();

    if (ULocalPlayer* LP = GetLocalPlayer())
    {
        if (auto* Subsystem = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
        {
            Subsystem->ClearAllMappings();
        }
    }
}
