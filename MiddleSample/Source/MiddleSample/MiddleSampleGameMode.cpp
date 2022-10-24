// Copyright Epic Games, Inc. All Rights Reserved.

#include "MiddleSampleGameMode.h"
#include "MiddleSampleCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMiddleSampleGameMode::AMiddleSampleGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AMiddleSampleGameMode::BeginPlay()
{
	Super::BeginPlay();
    ChangeWidget(StartingWidgetClass);
}

void AMiddleSampleGameMode::ChangeWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
    if (CurrentWidget != nullptr)
    {
        CurrentWidget->RemoveFromViewport();
        CurrentWidget = nullptr;
    }
    if (NewWidgetClass != nullptr)
    {
        CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), NewWidgetClass);
        if (CurrentWidget != nullptr)
        {
            CurrentWidget->AddToViewport();
        }
    }
}