// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/ActGameAnimInstance.h"
#include "Characters/MainCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UActGameAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	MainCharacter = Cast<AMainCharacter>(TryGetPawnOwner());
	if (MainCharacter)
	{
		MainCharacterMovement = MainCharacter->GetCharacterMovement();
	}
}

void UActGameAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);
	if (MainCharacterMovement)
	{
		GroundSpeed = UKismetMathLibrary::VSizeXY(MainCharacterMovement->Velocity);
		IsFalling = MainCharacterMovement->IsFalling();
		CharacterState = MainCharacter->GetCharacterState();
		IsSprinting = MainCharacter->GetIsSprinting();
	}

}
