// Copyright 2026, Amy Liu. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "CoastalCharacterMovementComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))

class COASTAL_API UCoastalCharacterMovementComponent : public UCharacterMovementComponent
{
    GENERATED_BODY()

    class FSavedMove_Coastal : public FSavedMove_Character
    {
    public:
        uint8 Saved_bWantsToSkate : 1u;

        // dictate whether new move is the same and does not need to be sent separately
        virtual bool CanCombineWith(const FSavedMovePtr& NewMove, ACharacter* InCharacter,
                                    float MaxDelta) const override;
        virtual void Clear() override;
        virtual uint8 GetCompressedFlags() const override;
        virtual void SetMoveFor(ACharacter* C, float InDeltaTime, FVector const& NewAccel,
                                FNetworkPredictionData_Client_Character& ClientData) override;
        virtual void PrepMoveFor(ACharacter* C) override;
    };

    class FNetworkPredictionData_Client_Coastal : public FNetworkPredictionData_Client_Character
    {
    public:
        FNetworkPredictionData_Client_Coastal(const UCharacterMovementComponent& ClientMovement);

        virtual FSavedMovePtr AllocateNewMove() override;
    };

    UPROPERTY(EditDefaultsOnly)
    float Skate_MaxWalkSpeed;

    UPROPERTY(EditDefaultsOnly)
    float Walk_MaxWalkSpeed;

    bool Safe_bWantsToSkate;

public:
    UCoastalCharacterMovementComponent();

    virtual FNetworkPredictionData_Client* GetPredictionData_Client() const override;

protected:
    virtual void UpdateFromCompressedFlags(uint8 Flags) override;

    virtual void OnMovementUpdated(float DeltaSeconds, const FVector& OldLocation, const FVector& OldVelocity) override;

public:
    UFUNCTION(BlueprintCallable, Category = CoastalCharacterMovementComponent)
    void SkatePressed();

    UFUNCTION(BlueprintCallable, Category = CoastalCharacterMovementComponent)
    void SkateReleased();

    UFUNCTION(BlueprintCallable, Category = CoastalCharacterMovementComponent)
    void CrouchPressed();
};
