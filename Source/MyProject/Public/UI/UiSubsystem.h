// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "UiSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UUiSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable)
	UUserWidget* AddWidget(UClass* WidgetClass);

	UFUNCTION(BlueprintCallable)
	void CloseAllWidgets();

	UFUNCTION(BlueprintCallable)
	void CloseWidget();

	UFUNCTION(BlueprintCallable)
	UUserWidget* GetActiveWidget();

protected:

	virtual void Initialize(FSubsystemCollectionBase& Collection);
	virtual void Deinitialize();

	UFUNCTION()
	void OnLevelChanged(ULevel* Level, UWorld* World);

private:

	TQueue<UUserWidget*> Widgets;


};
