// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Animation/AnimNotifies/AnimNotify.h"
#include "LoopBlockNotify.generated.h"

/**
 * 
 */
UCLASS()
class KNIGHTFIGHT_API ULoopBlockNotify : public UAnimNotify
{
	GENERATED_BODY()
	
		virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;

};
