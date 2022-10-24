// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Blueprint/UserWidget.h"
#include "GameFramework/GameModeBase.h"
#include "MiddleSampleGameMode.generated.h"

UCLASS(minimalapi)
class AMiddleSampleGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMiddleSampleGameMode();

    UFUNCTION(BlueprintCallable, Category = "UMG")
        void ChangeWidget(TSubclassOf<UUserWidget> NewWidgetClass);

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG")
        TSubclassOf<UUserWidget> StartingWidgetClass;

    UPROPERTY()
        UUserWidget* CurrentWidget;
};