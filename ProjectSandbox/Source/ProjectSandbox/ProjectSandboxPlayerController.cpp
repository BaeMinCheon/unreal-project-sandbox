// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectSandboxPlayerController.h"

void AProjectSandboxPlayerController::BeginPlay()
{
	Super::BeginPlay();

	NotifyTestFunc();
}
