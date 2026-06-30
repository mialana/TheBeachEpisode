// Copyright 2026, Amy Liu. All rights reserved.

#include "CoastalPlayerCameraManager.h"

#include "Components/CapsuleComponent.h"

#include "CoastalCharacter.h"
#include "CoastalCharacterMovementComponent.h"

ACoastalPlayerCameraManager::ACoastalPlayerCameraManager() {}

void ACoastalPlayerCameraManager::UpdateViewTarget(FTViewTarget& OutVT, float DeltaTime)
{
    Super::UpdateViewTarget(OutVT, DeltaTime);

    // Lerp position of view target using a computed
    if (ACoastalCharacter* CoastalCharacter = Cast<ACoastalCharacter>(GetOwningPlayerController()->GetPawn()))
    {
        UCoastalCharacterMovementComponent* CMC = CoastalCharacter->GetCoastalCharacterMovementComponent();

        static FVector sTargetCrouchOffset = FVector(0, 0,
                                                     CMC->GetCrouchedHalfHeight()
                                                         - CoastalCharacter->GetClass()
                                                               ->GetDefaultObject<ACharacter>()
                                                               ->GetCapsuleComponent()
                                                               ->GetScaledCapsuleHalfHeight());

        FVector Offset = FMath::Lerp(FVector::ZeroVector, sTargetCrouchOffset,
                                     FMath::Clamp(CrouchBlendTime / CrouchBlendDuration, 0.f, 1.f));

        if (CMC->IsCrouching())
        {
            CrouchBlendTime = FMath::Clamp(CrouchBlendTime + DeltaTime, 0.f, CrouchBlendDuration);
            Offset -= sTargetCrouchOffset;
        }
        else
        {
            CrouchBlendTime = FMath::Clamp(CrouchBlendTime - DeltaTime, 0.f, CrouchBlendDuration);
        }

        OutVT.POV.Location += Offset;
    }
}
