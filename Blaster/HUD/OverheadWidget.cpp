// Fill out your copyright notice in the Description page of Project Settings.


#include "OverheadWidget.h"
#include "Components/TextBlock.h"
#include "GameFramework/PlayerState.h"

void UOverheadWidget::SetDisplayText(FString TextToDisplay)
{
	if (DisplayText)
	{
		DisplayText->SetText(FText::FromString(TextToDisplay));
	}
}

void UOverheadWidget::ShowPlayerNetRole(APawn* InPawn)
{
	ENetRole LocalRole = InPawn->GetLocalRole();
	FString Role;
	switch (LocalRole)
	{
	case ENetRole::ROLE_Authority:
		Role = FString("Authority");
		break;
	case ENetRole::ROLE_AutonomousProxy:
		Role = FString("Autonomous Proxy");
			break;
	case ENetRole::ROLE_SimulatedProxy:
		Role = FString("Simulated Proxy");
			break;
	case ENetRole::ROLE_None:
		Role = FString("None");
			break;
	}
	
	FString LocalRoleString = FString::Printf(TEXT("Local Role: %s"), *Role);
	SetDisplayText(LocalRoleString);
	UE_LOG(LogTemp, Warning, TEXT("Reached ShowPlayerNetRole function"));
}

void UOverheadWidget::ShowPlayerName(APawn* InPawn)
{
	FString PlayerName{};
	
	if (InPawn)
	{
		AController* Controller = InPawn->GetController();
		if (Controller)
		{
			APlayerState* PlayerState = Cast<APlayerState>(Controller->PlayerState);
			if (PlayerState)
			{
				PlayerName = PlayerState->GetPlayerName();
			}
		}
	}

	FString PrintName = FString::Printf(TEXT("Player Name: %s"), *PlayerName);
	SetDisplayText(PrintName);
	UE_LOG(LogTemp, Warning, TEXT("Reached ShowPlayerName function"));
}

void UOverheadWidget::ShowPlayerAssBrain(APawn* InPawn)
{
	UE_LOG(LogTemp, Warning, TEXT("ASSBRAIN!"));
}

void UOverheadWidget::NativeDestruct()
{
	Super::NativeDestruct();
}
	