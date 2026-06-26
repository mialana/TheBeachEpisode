// Copyright 2026, Amy Liu. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CoastalGameModeInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable, BlueprintType)

class UCoastalGameModeInterface : public UInterface
{
    GENERATED_BODY()
};

/**
 * 
 */
class COASTAL_API ICoastalGameModeInterface
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Events")
    void OnGenerateNextGround();
};
