// Fill out your copyright notice in the Description page of Project Settings.

#include "KnightFight.h"

#include "../KnightAnimInstance.h"
#include "EndOfBlockNotify.h"


void UEndOfBlockNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	UKnightAnimInstance* animInstance = Cast<UKnightAnimInstance>(MeshComp->GetAnimInstance());
	if (animInstance)
	{
		animInstance->stopBlock();
	}
}




