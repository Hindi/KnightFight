// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Equipements/Weapons/Weapon.h"
#include "StateMachine/StateMachineKnight.h"
#include "Animations/KnightAnimInstance.h"
#include "BaseCharacter.generated.h"

UCLASS()
class KNIGHTFIGHT_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UClass* uClassPrimaryWeapon;
	AWeapon* primaryWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Assets")
	USkeletalMesh* primaryWeaponMeshAsset;

	UClass* uClassSecondaryWeapon;
	AWeapon* secondaryWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Assets")
	USkeletalMesh* secondaryWeaponMeshAsset;

	UPROPERTY(EditAnywhere)
	UStateMachineKnight* stateMachine;

	UPROPERTY()
	UKnightAnimInstance * animationInstance;
};
