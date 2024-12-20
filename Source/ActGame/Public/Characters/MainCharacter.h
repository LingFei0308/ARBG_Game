// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "CharacterTypes.h"
#include "MainCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class AItem;
class UAnimMontage;


UCLASS()
class ACTGAME_API AMainCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:

	AMainCharacter();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void GetHit_Implementation(const FVector& ImpactPoint) override;

protected:
	virtual void BeginPlay() override;

	/*
	* Callbacks for input
	*/
	void MoveForward(float Value);
	void MoveRight(float Value);
	void StartSprinting();
	void StoptSprinting();
	void Turn(float Value);
	void LookUp(float Value);
	void EKeyPressed();
	virtual void Attack() override;
	void BangAttack();

	/*
	* Combo attacks
	*/

	UFUNCTION(BlueprintCallable)
	void ComboAttack();

	/*
	* Play Montage functions
	*/
	void PlayBangAttackMontage();

	virtual void AttackEnd() override;

	void EquipWeapon(AWeapon* Weapon);

	virtual bool CanAttack() override;

	void PlayEquipMontage(const FName& SectionName);
	bool CanDisarm();
	bool CanArm();
	void Disarm();
	void Arm();
	bool IsSprinting;

	UFUNCTION(BlueprintCallable)
	void AttachWeaponToBack();

	UFUNCTION(BlueprintCallable)
	void AttachWeaponToHand();

	UFUNCTION(BlueprintCallable)
	void FinishEquipping();

private:
	ECharacterState CharacterState = ECharacterState::ECS_Unequipped;

	int8 AttackCount = 1;
	ECanComboAttack CanComboAttack = ECanComboAttack::ECCA_NoComboAttack;

	UPROPERTY(BlueprintReadWrite,meta = (AllowPrivateAccess = "true"))
	EActionState ActionState = EActionState::EAS_Unoccupied;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* ViewCamera;

	UPROPERTY(VisibleInstanceOnly)
	AItem* OverlappingItem;





	UPROPERTY(EditDefaultsOnly, Category = Montages)
	UAnimMontage* EquipMontage;

	UPROPERTY(EditDefaultsOnly, Category = Montages)
	UAnimMontage* BangAttackMontage;

public:
	FORCEINLINE void SetOverlappingItem(AItem* Item) { OverlappingItem = Item; }
	FORCEINLINE ECharacterState GetCharacterState() const { return CharacterState; }
	FORCEINLINE bool GetIsSprinting() const { return IsSprinting; }
};
