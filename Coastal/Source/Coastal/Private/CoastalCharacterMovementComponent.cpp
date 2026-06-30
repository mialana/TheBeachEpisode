// Copyright 2026, Amy Liu. All rights reserved.

#include "CoastalCharacterMovementComponent.h"

#include "GameFramework/Character.h"

bool UCoastalCharacterMovementComponent::FSavedMove_Coastal::CanCombineWith(const FSavedMovePtr& NewMove,
                                                                            ACharacter* InCharacter,
                                                                            float MaxDelta) const
{
    FSavedMove_Coastal* NewCoastalMove = static_cast<FSavedMove_Coastal*>(NewMove.Get());

    if (Saved_bWantsToSkate != NewCoastalMove->Saved_bWantsToSkate)
    {
        return false;
    }

    // defer to super class
    return FSavedMove_Character::CanCombineWith(NewMove, InCharacter, MaxDelta);
}

void UCoastalCharacterMovementComponent::FSavedMove_Coastal::Clear()
{
    FSavedMove_Character::Clear();

    // reset flags
    Saved_bWantsToSkate = 0u;
}

uint8 UCoastalCharacterMovementComponent::FSavedMove_Coastal::GetCompressedFlags() const
{
    uint8 Result = FSavedMove_Character::GetCompressedFlags();

    if (Saved_bWantsToSkate)
    {
        Result |= FLAG_Custom_0;
    }

    return Result;
}

void UCoastalCharacterMovementComponent::FSavedMove_Coastal::SetMoveFor(
    ACharacter* C, float InDeltaTime, FVector const& NewAccel, FNetworkPredictionData_Client_Character& ClientData)
{
    FSavedMove_Character::SetMoveFor(C, InDeltaTime, NewAccel, ClientData);

    UCoastalCharacterMovementComponent* CharacterMovement = Cast<UCoastalCharacterMovementComponent>(
        C->GetCharacterMovement());

    Saved_bWantsToSkate = CharacterMovement->Safe_bWantsToSkate;
}

void UCoastalCharacterMovementComponent::FSavedMove_Coastal::PrepMoveFor(ACharacter* C)
{
    FSavedMove_Character::PrepMoveFor(C);

    UCoastalCharacterMovementComponent* CharacterMovement = Cast<UCoastalCharacterMovementComponent>(
        C->GetCharacterMovement());

    CharacterMovement->Safe_bWantsToSkate = Saved_bWantsToSkate;
}

UCoastalCharacterMovementComponent::FNetworkPredictionData_Client_Coastal::FNetworkPredictionData_Client_Coastal(
    const UCharacterMovementComponent& ClientMovement)
    : FNetworkPredictionData_Client_Character(ClientMovement)
{
}

FSavedMovePtr UCoastalCharacterMovementComponent::FNetworkPredictionData_Client_Coastal::AllocateNewMove()
{
    return FSavedMovePtr(new FSavedMove_Coastal());
}

UCoastalCharacterMovementComponent::UCoastalCharacterMovementComponent()
{
    NavAgentProps.bCanCrouch = true;
}

FNetworkPredictionData_Client* UCoastalCharacterMovementComponent::GetPredictionData_Client() const
{
    check(PawnOwner != nullptr);

    if (ClientPredictionData == nullptr)
    {
        UCoastalCharacterMovementComponent* MutableThis = const_cast<UCoastalCharacterMovementComponent*>(this);

        MutableThis->ClientPredictionData = new FNetworkPredictionData_Client_Coastal(*this);

        // parameters for prediction
        MutableThis->ClientPredictionData->MaxSmoothNetUpdateDist = 92.f;
        MutableThis->ClientPredictionData->NoSmoothNetUpdateDist = 140.f;
    }
    return ClientPredictionData;
}

void UCoastalCharacterMovementComponent::UpdateFromCompressedFlags(uint8 Flags)
{
    Super::UpdateFromCompressedFlags(Flags);

    Safe_bWantsToSkate = static_cast<bool>(Flags & FSavedMove_Character::FLAG_Custom_0);
}

void UCoastalCharacterMovementComponent::OnMovementUpdated(float DeltaSeconds, const FVector& OldLocation,
                                                           const FVector& OldVelocity)
{
    Super::OnMovementUpdated(DeltaSeconds, OldLocation, OldVelocity);

    if (MovementMode == MOVE_Walking)
    {
        if (Safe_bWantsToSkate)
        {
            MaxWalkSpeed = Skate_MaxWalkSpeed;
        }
        else
        {
            MaxWalkSpeed = Walk_MaxWalkSpeed;
        }
    }
}

void UCoastalCharacterMovementComponent::SkatePressed()
{
    Safe_bWantsToSkate = true;
}

void UCoastalCharacterMovementComponent::SkateReleased()
{
    Safe_bWantsToSkate = false;
}

void UCoastalCharacterMovementComponent::CrouchPressed()
{
    bWantsToCrouch = !bWantsToCrouch;
}
