// Copyright 2026, Amy Liu. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "CoastalCharacter.h"
#include "CoastalCharacterSkater.generated.h"

class USkeletalMeshComponent;

/**
 * 
 */
UCLASS()

class COASTAL_API ACoastalCharacterSkater : public ACoastalCharacter
{
    GENERATED_BODY()

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
    USkeletalMeshComponent* EquipmentMesh;

public:
    ACoastalCharacterSkater();

public:
    virtual void DoMove(float Right, float Forward) override;
};
