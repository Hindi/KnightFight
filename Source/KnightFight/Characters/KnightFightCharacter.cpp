// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "KnightFight.h"
#include "Kismet/HeadMountedDisplayFunctionLibrary.h"

#include "StateMachine/States/Knight/StateIdleKnight.h"
#include "StateMachine/States/Knight/StateKnightCombo1.h"
#include "StateMachine/States/Knight/StateKnightCombo2.h"
#include "StateMachine/States/Knight/StateKnightFrontKick.h"
#include "StateMachine/States/Knight/StateKnightBlock.h"

#include "Engine.h"

#include "KnightFightCharacter.h"

//////////////////////////////////////////////////////////////////////////
// AKnightFightCharacter

AKnightFightCharacter::AKnightFightCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm


	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)

}

void AKnightFightCharacter::BeginPlay()
{
	Super::BeginPlay();

	//We need animInstance for the states
	if (animationInstance)
	{

		UStateIdleKnight* idleState = NewObject<UStateIdleKnight>(stateMachine, UStateIdleKnight::StaticClass(), TEXT("IdleState"));
		UStateKnightCombo1* combo1State = NewObject<UStateKnightCombo1>(stateMachine, UStateKnightCombo1::StaticClass(), TEXT("Combo1State"));
		UStateKnightCombo2* combo2State = NewObject<UStateKnightCombo2>(stateMachine, UStateKnightCombo2::StaticClass(), TEXT("Combo2State"));
		UStateKnightFrontKick* frontKickState = NewObject<UStateKnightFrontKick>(stateMachine, UStateKnightFrontKick::StaticClass(), TEXT("FrontKickState"));
		UStateKnightBlock* blockState = NewObject<UStateKnightBlock>(stateMachine, UStateKnightBlock::StaticClass(), TEXT("BlockState"));

		idleState->initState(stateMachine, this, animationInstance);
		combo1State->initState(stateMachine, this, animationInstance, combo1Montage, primaryWeapon);
		combo2State->initState(stateMachine, this, animationInstance, combo2Montage, primaryWeapon);
		frontKickState->initState(stateMachine, this, animationInstance, frontKickMontage);
		blockState->initState(stateMachine, this, animationInstance, blockMontage);

		stateMachine->addState(TEXT("Idle"), idleState);
		stateMachine->addState(TEXT("Combo1"), combo1State);
		stateMachine->addState(TEXT("Combo2"), combo2State);
		stateMachine->addState(TEXT("FrontKick"), frontKickState);
		stateMachine->addState(TEXT("Block"), blockState);

		stateMachine->start(TEXT("Idle"));
	}
}

//////////////////////////////////////////////////////////////////////////
// Input

void AKnightFightCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("LightHit", IE_Pressed, this, &AKnightFightCharacter::LightHit);
	PlayerInputComponent->BindAction("FrontKick", IE_Pressed, this, &AKnightFightCharacter::FrontKick);
	PlayerInputComponent->BindAction("Block", IE_Pressed, this, &AKnightFightCharacter::StartBlock);
	PlayerInputComponent->BindAction("Block", IE_Released, this, &AKnightFightCharacter::EndBlock);

	PlayerInputComponent->BindAxis("MoveForward", this, &AKnightFightCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AKnightFightCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AKnightFightCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AKnightFightCharacter::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &AKnightFightCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AKnightFightCharacter::TouchStopped);

	// VR headset functionality
	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &AKnightFightCharacter::OnResetVR);
}

void AKnightFightCharacter::LightHit()
{
	Cast<UStateKnight>(stateMachine->getCurrentState())->pressLightHit();
}

void AKnightFightCharacter::FrontKick()
{
	Cast<UStateKnight>(stateMachine->getCurrentState())->pressFrontKick();
}

void AKnightFightCharacter::StartBlock()
{
	Cast<UStateKnight>(stateMachine->getCurrentState())->pressBlock();
}

void AKnightFightCharacter::EndBlock()
{
	Cast<UStateKnight>(stateMachine->getCurrentState())->releaseBlock();
}

void AKnightFightCharacter::stopMontage(UAnimMontage* montage)
{
	StopAnimMontage(montage);
}

void AKnightFightCharacter::playMontage(UAnimMontage* montage, FName sectionName)
{
	PlayAnimMontage(montage, 1, sectionName);
}

void AKnightFightCharacter::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void AKnightFightCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
		Jump();
}

void AKnightFightCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
		StopJumping();
}

void AKnightFightCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AKnightFightCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AKnightFightCharacter::Tick(float DeltaTime)
{
	FRotator NewRot = FRotationMatrix::MakeFromX(lockTarget->GetActorLocation() - this->GetActorLocation()).Rotator();
	NewRot.Pitch = 0;
	lookAtDirection = NewRot.Vector();

	SetActorRotation(NewRot);
	doMoveRight();
}

void AKnightFightCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = this->GetActorRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Rotation.Vector(), Value);
	}
	if(animationInstance)
	{
		animationInstance->speed = Value * 100;
	}
}

void AKnightFightCharacter::doMoveRight()
{
	if (moveRightValue != 0)
	{
		// find out which way is right
		const FRotator Rotation = GetActorForwardVector().Rotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, moveRightValue);
		moveRightValue = 0;
	}
}

void AKnightFightCharacter::MoveRight(float Value)
{
	moveRightValue = Value;
	if (animationInstance)
		animationInstance->direction = Value * 100;
}
