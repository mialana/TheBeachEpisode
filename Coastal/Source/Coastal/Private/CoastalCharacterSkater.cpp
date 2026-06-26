// Copyright 2026, Amy Liu. All rights reserved.

#include "CoastalCharacterSkater.h"

#include "Components/SkeletalMeshComponent.h"

ACoastalCharacterSkater::ACoastalCharacterSkater()
{
    // Create the equipment mesh
    EquipmentMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("EquipmentMesh"));
    EquipmentMesh->SetupAttachment(RootComponent);
}

void ACoastalCharacterSkater::DoMove(float Right, float Forward)
{
    if (GetController() != nullptr)
    {
        // get forward vector based on whether the character is using the equipment
        const FVector ForwardDirection = EquipmentMesh->GetForwardVector();

        // get right vector of equipment
        const FVector RightDirection = EquipmentMesh->GetRightVector();

        // add movement
        AddMovementInput(ForwardDirection, Forward);
        AddMovementInput(RightDirection, Right);
    }
}
