// Copyright 2026, Amy Liu. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "CoastalPlayerCameraManager.generated.h"

/**
 * 
 */
UCLASS()

class COASTAL_API ACoastalPlayerCameraManager : public APlayerCameraManager
{
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly)
    float CrouchBlendDuration = .2f;

    float CrouchBlendTime;

public:
    ACoastalPlayerCameraManager();

    virtual void UpdateViewTarget(FTViewTarget& OutVT, float DeltaTime) override;
};
