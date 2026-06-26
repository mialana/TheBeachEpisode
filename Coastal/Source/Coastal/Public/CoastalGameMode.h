// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CoastalGameModeInterface.h"
#include "CoastalGameMode.generated.h"

/**
 *  Simple GameMode for a third person game
 */
UCLASS(abstract)

class ACoastalGameMode : public AGameModeBase, public ICoastalGameModeInterface
{
    GENERATED_BODY()

public:
    /** Constructor */
    ACoastalGameMode();
};
