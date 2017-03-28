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

void UStateKnight::useLightHit()
{
	//Do nothing by default
}

void UStateKnight::useFrontKick()
{
	//Do nothing by default
}

void UStateKnight::useBlock()
{
	//Do nothing by default
}

void UStateKnight::releaseBlock()
{
	//Do nothing by default
}