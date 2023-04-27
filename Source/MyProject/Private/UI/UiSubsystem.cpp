// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/UiSubsystem.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"


void UUiSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	FWorldDelegates::LevelRemovedFromWorld.AddUObject(this, &ThisClass::OnLevelChanged);
}

void UUiSubsystem::Deinitialize()
{
	FWorldDelegates::LevelRemovedFromWorld.RemoveAll(this);
}

void UUiSubsystem::OnLevelChanged(ULevel* Level, UWorld* World)
{
	CloseAllWidgets();
}

void UUiSubsystem::CloseAllWidgets()
{
	while (!Widgets.IsEmpty())
	{
		CloseWidget();
	}
}

void UUiSubsystem::CloseWidget()
{
	UUserWidget* Widget;
	Widgets.Dequeue(Widget);
	if (IsValid(Widget))
	{
		Widget->RemoveFromParent();
	}

	if (Widgets.IsEmpty())
	{
		if (auto* PC = UGameplayStatics::GetPlayerController(this, 0))
		{
			PC->SetShowMouseCursor(false);
			FInputModeGameOnly Mode;
			PC->SetInputMode(Mode);
		}
	}
	else
	{
		if (UUserWidget* ActiveWidget = *Widgets.Peek())
		{
			ActiveWidget->SetVisibility(ESlateVisibility::Visible);
		}
	}
}

UUserWidget* UUiSubsystem::AddWidget(UClass* WidgetClass)
{
	auto* NewWidget = CreateWidget<UUserWidget>(GetWorld(), WidgetClass);
	if (IsValid(NewWidget))
	{
		if (!Widgets.IsEmpty())
		{
			if (UUserWidget* ActiveWidget = *Widgets.Peek())
			{
				ActiveWidget->SetVisibility(ESlateVisibility::Collapsed);
			}
		}
		if (auto* PC = UGameplayStatics::GetPlayerController(this, 0))
		{
			Widgets.Enqueue(NewWidget);
			PC->SetShowMouseCursor(true);
			FInputModeGameAndUI Mode;
			Mode.SetLockMouseToViewportBehavior(EMouseLockMode::LockInFullscreen);
			Mode.SetHideCursorDuringCapture(false);
			PC->SetInputMode(Mode);
			NewWidget->AddToViewport();
		}
	}
	return NewWidget;
}

UUserWidget* UUiSubsystem::GetActiveWidget()
{
	return *Widgets.Peek();
}
