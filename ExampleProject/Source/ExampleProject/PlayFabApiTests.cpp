// Fill out your copyright notice in the Description page of Project Settings.

#include "ExampleProject.h"
#include "PlayFabApiTests.h"


PlayFabApiTest_LoginWithEmail::PlayFabApiTest_LoginWithEmail(bool successExpected, bool successMandatory, const FString& username, const FString& email, const FString& password)
{
    this->successExpected = successExpected;
    this->successMandatory = successMandatory;
    this->username = username;
    this->email = email;
    this->password = password;
}

bool PlayFabApiTest_LoginWithEmail::Update()
{
    // Initialize, setup the call, and wait for the result
    if (!clientAPI.IsValid())
    {
        clientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

        PlayFab::ClientModels::FLoginWithEmailAddressRequest request;
        request.Email = email;
        request.Password = password;

        clientAPI->LoginWithEmailAddress(request
            , PlayFab::UPlayFabClientAPI::FLoginWithEmailAddressDelegate::CreateRaw(this, &PlayFabApiTest_LoginWithEmail::OnSuccess)
            , PlayFab::FPlayFabErrorDelegate::CreateRaw(this, &PlayFabApiTest_LoginWithEmail::OnError)
            );
    }

    // Return when the api call is resolved
    return clientAPI->GetPendingCalls() == 0;
}

void PlayFabApiTest_LoginWithEmail::OnSuccess(const PlayFab::ClientModels::FLoginResult& Result)
{
    if (!successExpected)
    {
        UE_LOG(LogTemp, Error, TEXT("LoginWithEmailAddress Succeeded where it should have failed"));
    }
    else // Mandatory or not, the test succeeded
    {
        UE_LOG(LogTemp, Log, TEXT("LoginWithEmailAddress Success"));
    }
}

void PlayFabApiTest_LoginWithEmail::OnError(const PlayFab::FPlayFabError& ErrorResult)
{
    if (successExpected && successMandatory) // Check for success, or ...
    {
        UE_LOG(LogTemp, Error, TEXT("LoginWithEmailAddress Failed"));
    }
    else if (successExpected && !successMandatory)
    {
        ADD_LATENT_AUTOMATION_COMMAND(PlayFabApiTest_RegisterPlayFabUser(username, email, password));
    }
    else if (ErrorResult.ErrorMessage.Find(TEXT("password")) == -1) // Check that we correctly received a notice about invalid password
    {
        UE_LOG(LogTemp, Error, TEXT("Non-password error with login"));
    }
}

PlayFabApiTest_RegisterPlayFabUser::PlayFabApiTest_RegisterPlayFabUser(const FString& username, const FString& email, const FString& password)
{
    this->username = username;
    this->email = email;
    this->password = password;
}

bool PlayFabApiTest_RegisterPlayFabUser::Update()
{
    // Initialize, setup the call, and wait for the result
    if (!clientAPI.IsValid())
    {
        clientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

        PlayFab::ClientModels::FRegisterPlayFabUserRequest request;
        request.Email = email;
        request.Password = password;
        request.Username = username;

        clientAPI->RegisterPlayFabUser(request
            , PlayFab::UPlayFabClientAPI::FRegisterPlayFabUserDelegate::CreateRaw(this, &PlayFabApiTest_RegisterPlayFabUser::OnSuccess)
            , PlayFab::FPlayFabErrorDelegate::CreateRaw(this, &PlayFabApiTest_RegisterPlayFabUser::OnError)
            );
    }

    // Return when the api call is resolved
    return clientAPI->GetPendingCalls() == 0;
}

void PlayFabApiTest_RegisterPlayFabUser::OnSuccess(const PlayFab::ClientModels::FRegisterPlayFabUserResult& Result)
{
    UE_LOG(LogTemp, Log, TEXT("RegisterPlayFabUser Success"));
    ADD_LATENT_AUTOMATION_COMMAND(PlayFabApiTest_LoginWithEmail(true, true, username, email, password));
}

void PlayFabApiTest_RegisterPlayFabUser::OnError(const PlayFab::FPlayFabError& ErrorResult)
{
    UE_LOG(LogTemp, Error, TEXT("RegisterPlayFabUser Failed"));
}

PlayFabApiTest_GetUserData::PlayFabApiTest_GetUserData(const FString& TEST_DATA_KEY_1, int expectedValue = -1)
{
    this->TEST_DATA_KEY_1 = TEST_DATA_KEY_1;

    this->expectedValue = expectedValue;
}

bool PlayFabApiTest_GetUserData::Update()
{
    // Initialize, setup the call, and wait for the result
    if (!clientAPI.IsValid())
    {
        clientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

        PlayFab::ClientModels::FGetUserDataRequest request;

        clientAPI->GetUserData(request
            , PlayFab::UPlayFabClientAPI::FGetUserDataDelegate::CreateRaw(this, &PlayFabApiTest_GetUserData::OnSuccess)
            , PlayFab::FPlayFabErrorDelegate::CreateRaw(this, &PlayFabApiTest_GetUserData::OnError)
            );
    }

    // Return when the api call is resolved
    return clientAPI->GetPendingCalls() == 0;
}

void PlayFabApiTest_GetUserData::OnSuccess(const PlayFab::ClientModels::FGetUserDataResult& Result)
{
    int actualValue = -1;

    const PlayFab::ClientModels::FUserDataRecord* target = Result.Data.Find(TEST_DATA_KEY_1);
    if (target != NULL)
        actualValue = FCString::Atoi(*(target->Value));

    if (expectedValue != -1 && expectedValue == actualValue)
    {
        UE_LOG(LogTemp, Log, TEXT("GetUserData Success"));
    }
    else if (expectedValue == -1)
    {
        // Call Update with (actualValue + 1)
    }
}

void PlayFabApiTest_GetUserData::OnError(const PlayFab::FPlayFabError& ErrorResult)
{
    UE_LOG(LogTemp, Error, TEXT("RegisterPlayFabUser Failed"));
}
