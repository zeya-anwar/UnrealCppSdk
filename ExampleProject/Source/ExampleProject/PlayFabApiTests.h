// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PlayFab.h"
#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Core/PlayFabClientDataModels.h"

#include "Misc/AutomationTest.h"
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

class PlayFabApiTest_LoginWithEmail : public IAutomationLatentCommand
{
public:
    PlayFabApiTest_LoginWithEmail(bool successExpected, bool successMandatory, const FString& username, const FString& email, const FString& password);

    bool Update();
private:
    void OnSuccess(const PlayFab::ClientModels::FLoginResult& Result);
    void OnError(const PlayFab::FPlayFabError& ErrorResult);

    FString username;
    FString email;
    FString password;
    bool successExpected = false;
    bool successMandatory = false;
    PlayFabClientPtr clientAPI = nullptr;
};

class PlayFabApiTest_RegisterPlayFabUser : public IAutomationLatentCommand
{
public:
    PlayFabApiTest_RegisterPlayFabUser(const FString& username, const FString& email, const FString& password);

    bool Update();
private:
    void OnSuccess(const PlayFab::ClientModels::FRegisterPlayFabUserResult& Result);
    void OnError(const PlayFab::FPlayFabError& ErrorResult);

    FString username;
    FString email;
    FString password;
    PlayFabClientPtr clientAPI = nullptr;
};

class PlayFabApiTest_GetUserData : public IAutomationLatentCommand
{
public:
    PlayFabApiTest_GetUserData(const FString& TEST_DATA_KEY_1, int expectedValue);

    bool Update();
private:
    void OnSuccess(const PlayFab::ClientModels::FGetUserDataResult& Result);
    void OnError(const PlayFab::FPlayFabError& ErrorResult);

    FString TEST_DATA_KEY_1;
    int expectedValue = -1;

    PlayFabClientPtr clientAPI = nullptr;
};


#define ADD_TEST(Name) TestFunctions.Add(&PlayFabApiTestSuite::Name); TestFunctionNames.Add(TEXT(#Name));
class PlayFabApiTestSuite : public FAutomationTestBase
{
    typedef bool (PlayFabApiTestSuite::*TestFunc)();

public:
    PlayFabApiTestSuite(const FString& InName)
        : FAutomationTestBase(InName, false)
    {
        ADD_TEST(InvalidLogin);
        ADD_TEST(LoginOrRegister);
        ADD_TEST(UserDataApi);
    }

    virtual uint32 GetTestFlags() const override { return EAutomationTestFlags::ATF_Editor; }
    virtual bool IsStressTest() const { return false; }
    virtual uint32 GetRequiredDeviceNum() const override { return 1; }

protected:
    virtual FString GetBeautifiedTestName() const override { return "PlayFabApiTests"; }
    virtual void GetTests(TArray<FString>& OutBeautifiedNames, TArray <FString>& OutTestCommands) const override
    {
        for (const FString& TestName : TestFunctionNames)
        {
            OutBeautifiedNames.Add(TestName);
            OutTestCommands.Add(TestName);
        }
    }

    bool RunTest(const FString& Parameters) override
    {
        clientAPI = IPlayFabModuleInterface::Get().GetClientAPI();
        TestTrue(TEXT("The ClientAPI reports itself as invalid."), clientAPI.IsValid());
        if (clientAPI.IsValid())
        {
            // find the matching test
            TestFunc TestFunction = nullptr;
            for (int32 i = 0; i < TestFunctionNames.Num(); ++i)
            {
                if (TestFunctionNames[i] == Parameters)
                {
                    TestFunction = TestFunctions[i];
                    return (this->*TestFunction)();
                }
            }
        }
        return false;
    }

    bool InvalidLogin()
    {
        ADD_LATENT_AUTOMATION_COMMAND(PlayFabApiTest_LoginWithEmail(false, false, TEXT("paul"), TEXT("paul@playfab.com"), TEXT("testPassword_INVALID")));

        return true;
    };

    bool LoginOrRegister()
    {
        ADD_LATENT_AUTOMATION_COMMAND(PlayFabApiTest_LoginWithEmail(true, false, TEXT("paul"), TEXT("paul@playfab.com"), TEXT("testPassword")));

        return true;
    };

    bool UserDataApi()
    {
        // TODO: TEXT("deleteCounter")
        ADD_LATENT_AUTOMATION_COMMAND(PlayFabApiTest_GetUserData(TEXT("testCounter"), -1));

        return true;
    };

    PlayFabClientPtr clientAPI;
    TArray<TestFunc> TestFunctions;
    TArray<FString> TestFunctionNames;
};

namespace
{
    PlayFabApiTestSuite FPlayFabApiTestsAutomationTestInstance(TEXT("FPlayFabApiTests"));
}
