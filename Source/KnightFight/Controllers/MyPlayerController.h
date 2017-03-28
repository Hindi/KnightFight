// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class KNIGHTFIGHT_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;

	
protected:
	void SetupInputComponent() override;

	/** Resets HMD orientation in VR. */
	void onResetVR();

	/** Called for forwards/backward input */
	void moveForward(float Value);

	/** Called for side to side input */
	void moveRight(float Value);

	void jump();
	void stopJumping();

	/**
	* Called via input to turn at a given rate.
	* @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	*/
	void turnAtRate(float Rate);
	void turn(float Rate);

	/**
	* Called via input to turn look up/down at a given rate.
	* @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	*/
	void lookUpAtRate(float Rate);
	void lookUp(float Rate);

	/** Handler for when a touch input begins. */
	void touchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void touchStopped(ETouchIndex::Type FingerIndex, FVector Location);

	/** Called when the LightHit input is pressed */
	void lightHit();

	/** Called when the FrontKick input is pressed */
	void frontKick();

	/** Called when the Block input is pressed */
	void startBlock();

	/** Called when the Block input is released */
	void endBlock();

private:
	APlayerCharacter* controlledCharacter;
};
