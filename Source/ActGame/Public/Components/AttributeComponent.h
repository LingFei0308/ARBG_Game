// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttributeComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ACTGAME_API UAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UAttributeComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
protected:
	virtual void BeginPlay() override;

private:
	//µ±Ç°½¡¿µ×´¿ö
	UPROPERTY(EditAnywhere,Category = "Actor Attributes")
	float Health = 100;

	UPROPERTY(EditAnywhere,CateGory = "Actor MaxHealth")
	float MaxHealth = 100;

public:
	void ReceiveDamage(float Damage);
	float GetHealthPercent();
	bool IsAlive();
};
