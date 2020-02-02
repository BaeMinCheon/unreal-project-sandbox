// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectSandboxPlayerController.h"
#include "Blueprint/UserWidget.h"

void AProjectSandboxPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ShowWelcomeText();
}

void AProjectSandboxPlayerController::ShowWelcomeText()
{
	UUserWidget* Widget = CreateWidget<UUserWidget>(this, WelcomeText);
	if (Widget == nullptr)
	{
		return;
	}

	Widget->AddToViewport();
}
