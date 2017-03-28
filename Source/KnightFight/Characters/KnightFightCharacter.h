// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/Character.h"
#include "Animations/KnightAnimInstance.h"
#include "StateMachine/StateMachineKnight.h"
#include "BaseCharacter.h"
#include "KnightFightCharacter.generated.h"

UCLASS(config=Game)
class AKnightFightCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	AKnightFightCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void doMoveRight();
	void playMontage(UAnimMontage* montage, FName sectionName = NAME_None);
	void stopMontage(UAnimMontage* montage);


	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

	/** Called when the LightHit input is pressed */
	void LightHit();
	/** Called when the FrontKick input is pressed */
	void FrontKick();

	/** Called when the Block input is pressed */
	void StartBlock();
	/** Called when the Block input is released */
	void EndBlock();



private:

	UPROPERTY(EditAnywhere)
	UAnimMontage* combo1Montage;
	UPROPERTY(EditAnywhere)
	UAnimMontage* combo2Montage;
	UPROPERTY(EditAnywhere)
	UAnimMontage* frontKickMontage;
	UPROPERTY(EditAnywhere)
	UAnimMontage* blockMontage;

	UPROPERTY(EditAnywhere)
	AActor* lockTarget; 


	FVector lookAtDirection;
	float moveRightValue;
};

