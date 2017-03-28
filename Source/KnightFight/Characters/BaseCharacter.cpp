// Fill out your copyright notice in the Description page of Project Settings.

#include "KnightFight.h"
#include "BaseCharacter.h"


// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = false; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	//Create the statemachine in the constructor so that it calls Super::BeginPlay in time and has its Tick function register in the engine.
	stateMachine = CreateDefaultSubobject<UStateMachineKnight>(TEXT("StateMachine"));
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	//AnimInstance is only available at BeginPlay time
	animationInstance = Cast<UKnightAnimInstance>(GetMesh()->GetAnimInstance());

	if (primaryWeaponMeshAsset)
	{
		primaryWeapon = GetWorld()->SpawnActor<AWeapon>(AWeapon::StaticClass(), GetActorLocation(), FRotator::ZeroRotator);
		if (primaryWeapon)
		{
			primaryWeapon->init(primaryWeaponMeshAsset);
			primaryWeapon->AttachRootComponentTo(GetMesh(), "PrimaryWeaponSocket", EAttachLocation::SnapToTarget, true);
		}
	}
	if (secondaryWeaponMeshAsset)
	{
		secondaryWeapon = GetWorld()->SpawnActor<AWeapon>(AWeapon::StaticClass(), GetActorLocation(), FRotator::ZeroRotator);
		if (secondaryWeapon)
		{
			secondaryWeapon->init(secondaryWeaponMeshAsset);
			secondaryWeapon->AttachRootComponentTo(GetMesh(), "SecondaryWeaponSocket"	, EAttachLocation::SnapToTarget, true);
		}
	}
	/*if (secondaryWeaponReference != FString("") && secondaryWeaponSocketName != FString(""))
	{
		uClassSecondaryWeapon = StaticLoadClass(UObject::StaticClass(), nullptr, *secondaryWeaponReference);
		if (uClassSecondaryWeapon)
		{
			secondaryWeapon = GetWorld()->SpawnActor<AWeapon>(uClassSecondaryWeapon, FVector(), FRotator());
			secondaryWeapon->AttachRootComponentTo(GetMesh(), *secondaryWeaponSocketName, EAttachLocation::SnapToTarget, true);
		}
	}*/
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

