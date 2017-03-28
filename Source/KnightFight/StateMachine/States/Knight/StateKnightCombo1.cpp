// Fill out your copyright notice in the Description page of Project Settings.

#include "KnightFight.h"
#include "StateKnightCombo1.h"
#include "StateMachine/StateMachineComponent.h"
#include "Characters/KnightFightCharacter.h"


void UStateKnightCombo1::leave()
{

}

void UStateKnightCombo1::enter()
{
	character->playMontage(animMontage);
	animInstance->startNewCombo();
	shouldContinueCombo = false;
}

void UStateKnightCombo1::update(float DeltaTime)
{
	if (animInstance->isTimeForNewComboPhase() && shouldContinueCombo)
		stateMachine->changeState(TEXT("Combo2"));

	if(animInstance->comboFinished())
		stateMachine->changeState(TEXT("Idle"));

	if (animInstance->canWeaponHit())
	{
		FHitResult hit(ForceInit);
		if (weapon->tryHit(hit))
		{
			stateMachine->changeState(TEXT("Idle"));
		}
	}
}

void UStateKnightCombo1::useLightHit()
{
	shouldContinueCombo = true;
}