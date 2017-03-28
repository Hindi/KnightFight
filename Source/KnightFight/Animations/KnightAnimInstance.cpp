// Fill out your copyright notice in the Description page of Project Settings.

#include "KnightFight.h"
#include "KnightAnimInstance.h"


void UKnightAnimInstance::startNewCombo()
{
	canChangeComboPhase = false;
	shouldStopCombo = false;
}

void UKnightAnimInstance::timeForNewComboPhase()
{
	canChangeComboPhase = true;
}

void UKnightAnimInstance::stopCombo()
{
	canChangeComboPhase = false;
	shouldStopCombo = true;
}

bool UKnightAnimInstance::isTimeForNewComboPhase()
{
	return canChangeComboPhase;
}

bool UKnightAnimInstance::comboFinished()
{
	return shouldStopCombo;
}

void UKnightAnimInstance::stopBlock()
{
	shouldLoopBlock = false;
	shouldStopBlock = true;
}

void UKnightAnimInstance::timeToLoopBlock()
{
	shouldLoopBlock = true;
}

bool UKnightAnimInstance::isTimeToLoopBlock()
{
	return shouldLoopBlock;
}

bool UKnightAnimInstance::blockFinished()
{
	return shouldStopBlock;
}

void UKnightAnimInstance::toggleWeaponCanHit()
{
	weaponCanHit = !weaponCanHit;
}

bool UKnightAnimInstance::canWeaponHit()
{
	return weaponCanHit;
}