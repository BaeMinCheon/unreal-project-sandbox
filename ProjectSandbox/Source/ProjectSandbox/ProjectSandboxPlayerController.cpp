// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectSandboxPlayerController.h"
#include "Blueprint/UserWidget.h"

void AProjectSandboxPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ShowWelcomeText();
	CreateUserInformation();
}

void AProjectSandboxPlayerController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	ReleaseUserInformation();
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

void AProjectSandboxPlayerController::CreateUserInformation()
{
	char* String = new char[100];
	strcpy(String, "baemincheon");
	UserInformation = MakeUnique<UserInfo>(0, String);

	TUniquePtr<UserInfo> AnotherPtr(MoveTemp(UserInformation));
}

void AProjectSandboxPlayerController::ReleaseUserInformation()
{
	UserInformation = nullptr;
}
