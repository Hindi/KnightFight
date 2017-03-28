// Fill out your copyright notice in the Description page of Project Settings.

#include "KnightFight.h"
#include "Characters/KnightFightCharacter.h"
#include "StateMachine/StateMachineComponent.h"
#include "StateKnight.h"


void UStateKnight::initState(UStateMachineComponent* machine, AKnightFightCharacter* myCharacter, 
	UKnightAnimInstance* myAnimInstance, UAnimMontage* myAnimMontage, AWeapon* myWeapon)
{
	Super::init(machine);
	character = myCharacter;
	animInstance = myAnimInstance;
	animMontage = myAnimMontage;
	weapon = myWeapon;
}

void UStateKnight::pressLightHit()
{
	//Do nothing by default
}

void UStateKnight::pressFrontKick()
{
	//Do nothing by default
}

void UStateKnight::pressBlock()
{
	//Do nothing by default
}

void UStateKnight::releaseBlock()
{
	//Do nothing by default
}