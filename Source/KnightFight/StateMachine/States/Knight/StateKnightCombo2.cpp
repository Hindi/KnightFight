// Fill out your copyright notice in the Description page of Project Settings.

#include "KnightFight.h"
#include "StateKnightCombo2.h"

#include "StateMachine/StateMachineComponent.h"
#include "Characters/KnightFightCharacter.h"



void UStateKnightCombo2::leave()
{

}

void UStateKnightCombo2::enter()
{
	character->playMontage(animMontage, "Combo2");
}

void UStateKnightCombo2::update(float DeltaTime)
{
	/*if (animInstance->isTimeForNewComboPhase() && shouldContinueCombo)
		stateMachine->changeState(TEXT("Combo3"));*/

	if (animInstance->comboFinished())
		stateMachine->changeState(TEXT("Idle"));

	if (animInstance->canWeaponHit())
	{
		FHitResult hit(ForceInit);
		weapon->tryHit(hit);
	}
}

void UStateKnightCombo2::useLightHit()
{
	shouldContinueCombo = true;
}