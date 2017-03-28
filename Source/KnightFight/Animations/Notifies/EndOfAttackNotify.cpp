// Fill out your copyright notice in the Description page of Project Settings.

#include "KnightFight.h"
#include "EndOfAttackNotify.h"
#include "../KnightAnimInstance.h"


void UEndOfAttackNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	UKnightAnimInstance* animInstance = Cast<UKnightAnimInstance>(MeshComp->GetAnimInstance());
	if (animInstance)
	{
		animInstance->stopCombo();
	}
}