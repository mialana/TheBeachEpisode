// Copyright 2026, Amy Liu. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "TheBeachEpisodeCharacter.h"
#include "TheBeachEpisodeCharacterSkater.generated.h"

class USkeletalMeshComponent;

/**
 * 
 */
UCLASS()

class THEBEACHEPISODE_API ATheBeachEpisodeCharacterSkater : public ATheBeachEpisodeCharacter
{
    GENERATED_BODY()

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
    USkeletalMeshComponent* EquipmentMesh;

public:
    ATheBeachEpisodeCharacterSkater();

public:
    virtual void DoMove(float Right, float Forward) override;
};
