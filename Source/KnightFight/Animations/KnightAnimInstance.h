// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Animation/AnimInstance.h"
#include "Equipements/Weapons/Weapon.h"
#include "KnightAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class KNIGHTFIGHT_API UKnightAnimInstance : public UAnimInstance
{
	GENERATED_BODY()


public:
	void timeForNewComboPhase();
	bool isTimeForNewComboPhase();
	bool comboFinished();
	void stopCombo();
	void startNewCombo();
	void timeToLoopBlock();
	bool isTimeToLoopBlock();
	bool blockFinished();
	void stopBlock();
	void toggleWeaponCanHit();
	bool canWeaponHit();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FootPlacement)
	float direction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FootPlacement)
	float speed;

private:
	bool canChangeComboPhase;
	bool shouldStopCombo;
	bool shouldLoopBlock;
	bool shouldStopBlock;
	bool weaponCanHit;
};



