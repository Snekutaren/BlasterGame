// Copyright Epic Games, Inc. All Rights Reserved.

#include "Blaster.h"
#include "Modules/ModuleManager.h"


#include "DrawDebugHelpers.h"
#include "GameFramework/PlayerState.h"
#include "Components/TextBlock.h"


IMPLEMENT_PRIMARY_GAME_MODULE(FDefaultGameModuleImpl, Blaster, "Blaster");

void LogMessage(const FString& message) {
	UE_LOG(LogTemp, Log, TEXT("%s"), *message);
}


// Log to Screen
void PrintToScreen()
{
	FString PlayerName{};

	APawn* Pawn{};

	if (Pawn)
	{
		AController* Controller = Pawn->GetController();
		if (Controller)
		{
			APlayerState* PlayerState = Cast<APlayerState>(Controller->PlayerState);
			if (PlayerState)
			{
				PlayerName = PlayerState->GetPlayerName();
			}
		}
	}

	//FString Message = FString::Printf(TEXT("Player: %f"), PlayerName);
	GEngine->AddOnScreenDebugMessage(3, 60.f, FColor::White, PlayerName);
	UE_LOG(LogTemp, Log, TEXT("Reached this pont %s"));

	if (GEngine)
	{
		
	}
}