// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Core/PlayFabClientAPI.h"

#include "Misc/AutomationTest.h"

#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"


// forward declaration
namespace PlayFab
{
    namespace ClientModels
    {
        struct FLoginResult;
    }

    struct FPlayFabError;
}

UCLASS()
class EXAMPLEPROJECT_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

    void OnLoginSucess(const PlayFab::ClientModels::FLoginResult& Result);

    void OnLoginError(const PlayFab::FPlayFabError& Error);
};

