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