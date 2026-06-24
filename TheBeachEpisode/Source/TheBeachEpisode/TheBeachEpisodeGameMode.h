// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "TheBeachEpisodeGameModeInterface.h"
#include "TheBeachEpisodeGameMode.generated.h"

/**
 *  Simple GameMode for a third person game
 */
UCLASS(abstract)

class ATheBeachEpisodeGameMode : public AGameModeBase, public ITheBeachEpisodeGameModeInterface
{
    GENERATED_BODY()

public:
    /** Constructor */
    ATheBeachEpisodeGameMode();
};
