// Fill out your copyright notice in the Description page of Project Settings.

#include "KnightFight.h"
#include "StateKnightFrontKick.h"


#include "StateMachine/StateMachineComponent.h"
#include "Characters/KnightFightCharacter.h"



void UStateKnightFrontKick::leave()
{

}

void UStateKnightFrontKick::enter()
{
	character->playMontage(animMontage);
	animInstance->startNewCombo();
}

void UStateKnightFrontKick::update(float DeltaTime)
{
	if (animInstance->comboFinished())
		stateMachine->changeState(TEXT("Idle"));
}

void UStateKnightFrontKick::pressLightHit()
{
	shouldContinueCombo = true;
}

