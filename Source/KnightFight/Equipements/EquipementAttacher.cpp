// Fill out your copyright notice in the Description page of Project Settings.

#include "KnightFight.h"
#include "EquipementAttacher.h"


// Sets default values for this component's properties
UEquipementAttacher::UEquipementAttacher()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

}


// Called when the game starts
void UEquipementAttacher::BeginPlay()
{
	Super::BeginPlay();

	if (equipement)
	{
		equipement->AttachRootComponentTo(skeletalMesh, *socketName, EAttachLocation::SnapToTarget, true);
	}
}
