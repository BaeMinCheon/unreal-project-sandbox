// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ProjectSandboxPlayerController.generated.h"

class UserInfo
{
public:
	UserInfo(int32 NewUserID, char* NewUserName)
		: UserID(NewUserID), UserName(NewUserName), bInitialized(false)
	{
		__debugbreak();

		bInitialized = true;
	}
	virtual ~UserInfo()
	{
		__debugbreak();

		if (UserName != nullptr)
		{
			delete[] UserName;
		}

		bInitialized = false;
	}

private:
	int32 UserID;
	char* UserName;
	bool bInitialized;
};

/**
 * 
 */
UCLASS()
class PROJECTSANDBOX_API AProjectSandboxPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	void ShowWelcomeText();
	void CreateUserInformation();
	void ReleaseUserInformation();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<class UUserWidget> WelcomeText;

	TUniquePtr<class UserInfo> UserInformation;
};
