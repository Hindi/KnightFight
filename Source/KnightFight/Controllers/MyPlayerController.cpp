// Fill out your copyright notice in the Description page of Project Settings.

#include "KnightFight.h"
#include "Characters/PlayerCharacter.h"
#include "MyPlayerController.h"



void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	controlledCharacter = Cast<APlayerCharacter>(GetControlledPawn());
}


void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Jump", IE_Pressed, this, &AMyPlayerController::jump);
	InputComponent->BindAction("Jump", IE_Released, this, &AMyPlayerController::stopJumping);

	InputComponent->BindAction("LightHit", IE_Pressed, this, &AMyPlayerController::lightHit);
	InputComponent->BindAction("FrontKick", IE_Pressed, this, &AMyPlayerController::frontKick);
	InputComponent->BindAction("Block", IE_Pressed, this, &AMyPlayerController::startBlock);
	InputComponent->BindAction("Block", IE_Released, this, &AMyPlayerController::endBlock);

	InputComponent->BindAxis("MoveForward", this, &AMyPlayerController::moveForward);
	InputComponent->BindAxis("MoveRight", this, &AMyPlayerController::moveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	InputComponent->BindAxis("Turn", this, &AMyPlayerController::turn);
	InputComponent->BindAxis("TurnRate", this, &AMyPlayerController::turnAtRate);
	InputComponent->BindAxis("LookUp", this, &AMyPlayerController::lookUp);
	InputComponent->BindAxis("LookUpRate", this, &AMyPlayerController::lookUpAtRate);

	// handle touch devices
	InputComponent->BindTouch(IE_Pressed, this, &AMyPlayerController::touchStarted);
	InputComponent->BindTouch(IE_Released, this, &AMyPlayerController::touchStopped);

	// VR headset functionality
	InputComponent->BindAction("ResetVR", IE_Pressed, this, &AMyPlayerController::onResetVR);
}

void AMyPlayerController::jump()
{
	controlledCharacter->Jump();
}

void AMyPlayerController::stopJumping()
{
	controlledCharacter->StopJumping();
}

void AMyPlayerController::onResetVR()
{
	controlledCharacter->OnResetVR();
}

void AMyPlayerController::moveForward(float Value)
{
	controlledCharacter->MoveForward(Value);
}

void AMyPlayerController::moveRight(float Value)
{
	controlledCharacter->MoveRight(Value);
}

void AMyPlayerController::turnAtRate(float Rate)
{
	controlledCharacter->TurnAtRate(Rate);
}

void AMyPlayerController::turn(float Rate)
{
	controlledCharacter->AddControllerYawInput(Rate);
}

void AMyPlayerController::lookUpAtRate(float Rate)
{
	controlledCharacter->LookUpAtRate(Rate);
}

void AMyPlayerController::lookUp(float Rate)
{
	controlledCharacter->AddControllerPitchInput(Rate);
}

void AMyPlayerController::touchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
	controlledCharacter->TouchStarted(FingerIndex, Location);
}

void AMyPlayerController::touchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
	controlledCharacter->TouchStopped(FingerIndex, Location);
}

void AMyPlayerController::lightHit()
{
	controlledCharacter->LightHit();
}

void AMyPlayerController::frontKick()
{
	controlledCharacter->FrontKick();
}

void AMyPlayerController::startBlock()
{
	controlledCharacter->StartBlock();
}

void AMyPlayerController::endBlock()
{
	controlledCharacter->EndBlock();
}