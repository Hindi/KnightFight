// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "StateMachine/StateComponent.h"
#include "Animations/KnightAnimInstance.h"
#include "Equipements/Weapons/Weapon.h"
#include "StateKnight.generated.h"

//~~~~~ Forward Declarations~~~~~
class UStateMachineComponent;
class AKnightFightCharacter;
/**
 * 
 */
UCLASS(abstract)
class KNIGHTFIGHT_API UStateKnight : public UStateComponent
{
	GENERATED_BODY()
	
public:
	void initState(UStateMachineComponent* machine, AKnightFightCharacter* myCharacter, 
		UKnightAnimInstance* myAnimInstance, UAnimMontage* myAnimMontage = nullptr,
		AWeapon* myWeapon = nullptr);
	virtual void pressLightHit();
	virtual void pressFrontKick();
	virtual void pressBlock();
	virtual void releaseBlock();
	
protected:
	AKnightFightCharacter* character;
	UKnightAnimInstance* animInstance;
	UAnimMontage* animMontage;
	AWeapon* weapon;
};
