// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "InputAction.h"
#include "EnhancedInputComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "UnrealCpp0424/UnrealCpp0424.h"

// Sets default values
ABasePlayer::ABasePlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	GetMesh()->SetRelativeLocationAndRotation(
		FVector(0,0, -GetCapsuleComponent()->GetScaledCapsuleHalfHeight()),
		FRotator(0,-90,0)
	);

}

// Called when the game starts or when spawned
void ABasePlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABasePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (EIC)
	{
		EIC->BindAction(IA_Look, ETriggerEvent::Triggered, this, &ABasePlayer::Look);
		EIC->BindAction(IA_Move, ETriggerEvent::Triggered, this, &ABasePlayer::Move);
		EIC->BindAction(IA_Jump, ETriggerEvent::Started, this, &ABasePlayer::Jump);
		EIC->BindAction(IA_Jump, ETriggerEvent::Completed, this, &ABasePlayer::StopJumping);
		EIC->BindAction(IA_Lean, ETriggerEvent::Triggered, this, &ABasePlayer::Lean);
		EIC->BindAction(IA_Lean, ETriggerEvent::Completed, this, &ABasePlayer::Lean);
		EIC->BindAction(IA_Attack, ETriggerEvent::Completed, this, &ABasePlayer::Attack);
	}
}

void ABasePlayer::Look(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

	AddControllerPitchInput(-MovementVector.Y);
	AddControllerYawInput(MovementVector.X);
}
void ABasePlayer::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

	FRotator Rotation = Controller->GetControlRotation();
	FRotator YawRotation(0, Rotation.Yaw, 0);
	FVector ForwardDirection = UKismetMathLibrary::GetForwardVector(YawRotation);
	FVector RightDirection = UKismetMathLibrary::GetRightVector(YawRotation);
	AddMovementInput(ForwardDirection, MovementVector.X);
	AddMovementInput(RightDirection, MovementVector.Y);
}

void ABasePlayer::Lean(const FInputActionValue& Value)
{
	float InValue = Value.Get<float>();
	UE_LOG(LogOrigin, Log, TEXT("LeanAngle: %f"), LeanAngle);
	LeanAngle = 30.0f * InValue;
}

void ABasePlayer::Attack(const FInputActionValue& Value)
{
	
}

FRotator ABasePlayer::GetAimOffset() const
{
	//AimRotation은 World방향으로 준다
	//하지만 우리가 필요한건 Local 방향이 필요함
	//월드벡터에서 로컬벡터로 바꾸는거 월드가 가지고있다 -> 행렬계산임

	//World -> Local

	//로테이션을 벡터로 변환
	const FVector AimDirWorldSpace = GetBaseAimRotation().Vector();
	//월드벡터를 로컬벡터로 변환
	const FVector AimDirLocalSpace = ActorToWorld().InverseTransformVectorNoScale(AimDirWorldSpace);
	//로컬벡터를 로테이션으로 변환
	const FRotator AimRotLocalSpace = AimDirLocalSpace.Rotation();

	return AimRotLocalSpace;
}
