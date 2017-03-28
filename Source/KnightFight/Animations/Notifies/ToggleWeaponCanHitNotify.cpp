// Fill out your copyright notice in the Description page of Project Settings.

#include "KnightFight.h"
#include "ToggleWeaponCanHitNotify.h"
#include "../KnightAnimInstance.h"



void UToggleWeaponCanHitNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	UKnightAnimInstance* animInstance = Cast<UKnightAnimInstance>(MeshComp->GetAnimInstance());
	if (animInstance)
	{
		animInstance->toggleWeaponCanHit();
	}
}