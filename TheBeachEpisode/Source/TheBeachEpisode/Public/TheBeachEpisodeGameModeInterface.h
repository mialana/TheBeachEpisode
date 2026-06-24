// Copyright 2026, Amy Liu. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "TheBeachEpisodeGameModeInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable, BlueprintType)

class UTheBeachEpisodeGameModeInterface : public UInterface
{
    GENERATED_BODY()
};

/**
 * 
 */
class THEBEACHEPISODE_API ITheBeachEpisodeGameModeInterface
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Events")
    void OnGenerateNextGround();
};
