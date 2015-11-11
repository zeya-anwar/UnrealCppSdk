// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMisc.h"

#include "PlayFab.h"
#include "Core/PlayFabClientDataModels.h"
#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabServerDataModels.h"
#include "Core/PlayFabServerAPI.h"

#include "Misc/AutomationTest.h"


// forward declaration
namespace PlayFab
{
    namespace ClientModels
    {
        struct FLoginResult;
    }

    struct FPlayFabError;
}

/*
* ==== Login/Register ====
*/
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

/*
* ==== UserData ====
*/
class PlayFabApiTest_GetUserData : public IAutomationLatentCommand
{
public:
    PlayFabApiTest_GetUserData(const FString& TEST_DATA_KEY_1, const FString& TEST_DATA_KEY_2, int expectedValue);

    bool Update();
private:
    void OnSuccess(const PlayFab::ClientModels::FGetUserDataResult& Result);
    void OnError(const PlayFab::FPlayFabError& ErrorResult);

    FString TEST_DATA_KEY_1;
    FString TEST_DATA_KEY_2;
    int expectedValue = -1;

    PlayFabClientPtr clientAPI = nullptr;
};

class PlayFabApiTest_UpdateUserData : public IAutomationLatentCommand
{
public:
    PlayFabApiTest_UpdateUserData(const FString& TEST_DATA_KEY_1, const FString& TEST_DATA_KEY_2, int updateValue);

    bool Update();
private:
    void OnSuccess(const PlayFab::ClientModels::FUpdateUserDataResult& Result);
    void OnError(const PlayFab::FPlayFabError& ErrorResult);

    FString TEST_DATA_KEY_1;
    FString TEST_DATA_KEY_2;
    int updateValue = -1;

    PlayFabClientPtr clientAPI = nullptr;
};

/*
* ==== UserStatistics ====
*/
class PlayFabApiTest_GetUserStatistics : public IAutomationLatentCommand
{
public:
    PlayFabApiTest_GetUserStatistics(const FString& TEST_STAT_NAME, int expectedValue);

    bool Update();
private:
    void OnSuccess(const PlayFab::ClientModels::FGetUserStatisticsResult& Result);
    void OnError(const PlayFab::FPlayFabError& ErrorResult);

    FString TEST_STAT_NAME;
    int expectedValue = -1;

    PlayFabClientPtr clientAPI = nullptr;
};

class PlayFabApiTest_UpdateUserStatistics : public IAutomationLatentCommand
{
public:
    PlayFabApiTest_UpdateUserStatistics(const FString& TEST_STAT_NAME, int updateValue);

    bool Update();
private:
    void OnSuccess(const PlayFab::ClientModels::FUpdateUserStatisticsResult& Result);
    void OnError(const PlayFab::FPlayFabError& ErrorResult);

    FString TEST_STAT_NAME;
    int updateValue = -1;

    PlayFabClientPtr clientAPI = nullptr;
};

/*
* ==== GetLeaderboard ====
*/
class PlayFabApiTest_GetLeaderboardAroundCurrentUser : public IAutomationLatentCommand
{
public:
    PlayFabApiTest_GetLeaderboardAroundCurrentUser(const FString& TEST_STAT_NAME);

    bool Update();
private:
    void OnSuccess(const PlayFab::ClientModels::FGetLeaderboardAroundCurrentUserResult& Result);
    void OnError(const PlayFab::FPlayFabError& ErrorResult);

    FString TEST_STAT_NAME;
    bool expectSuccess = false;

    PlayFabClientPtr clientAPI = nullptr;
};

class PlayFabApiTest_GetLeaderboardAroundUser : public IAutomationLatentCommand
{
public:
    PlayFabApiTest_GetLeaderboardAroundUser(const FString& playFabId, const FString& TEST_STAT_NAME);

    bool Update();
private:
    void OnSuccess(const PlayFab::ServerModels::FGetLeaderboardAroundUserResult& Result);
    void OnError(const PlayFab::FPlayFabError& ErrorResult);

    FString playFabId;
    FString TEST_STAT_NAME;

    PlayFabServerPtr serverAPI = nullptr;
};

/*
* ==== GetAllUsersCharacters ====
*/
class PlayFabApiTest_GetAllUsersCharacters : public IAutomationLatentCommand
{
public:
    PlayFabApiTest_GetAllUsersCharacters(const FString& playFabId, const FString& CHAR_NAME, const FString& CHAR_TEST_TYPE, bool expectSuccess);

    bool Update();
private:
    void OnSuccess(const PlayFab::ClientModels::FListUsersCharactersResult& Result);
    void OnError(const PlayFab::FPlayFabError& ErrorResult);

    FString playFabId;
    FString CHAR_NAME;
    FString CHAR_TEST_TYPE;
    bool expectSuccess = false;

    PlayFabClientPtr clientAPI = nullptr;
};

class PlayFabApiTest_GrantCharacterToUser : public IAutomationLatentCommand
{
public:
    PlayFabApiTest_GrantCharacterToUser(const FString& playFabId, const FString& CHAR_NAME, const FString& CHAR_TEST_TYPE);

    bool Update();
private:
    void OnSuccess(const PlayFab::ServerModels::FGrantCharacterToUserResult& Result);
    void OnError(const PlayFab::FPlayFabError& ErrorResult);

    FString playFabId;
    FString CHAR_NAME;
    FString CHAR_TEST_TYPE;

    PlayFabServerPtr serverAPI = nullptr;
};

/*
* ==== GetAccountInfo ====
*/
class PlayFabApiTest_GetAccountInfo : public IAutomationLatentCommand
{
public:
    PlayFabApiTest_GetAccountInfo();

    bool Update();
private:
    void OnSuccess(const PlayFab::ClientModels::FGetAccountInfoResult& Result);
    void OnError(const PlayFab::FPlayFabError& ErrorResult);

    PlayFabClientPtr clientAPI = nullptr;
};

/*
* ==== CloudScript ====
*/
class PlayFabApiTest_GetCloudScriptUrl : public IAutomationLatentCommand
{
public:
    PlayFabApiTest_GetCloudScriptUrl(const FString& actionId);

    bool Update();
private:
    void OnSuccess(const PlayFab::ClientModels::FGetCloudScriptUrlResult& Result);
    void OnError(const PlayFab::FPlayFabError& ErrorResult);

    FString actionId;

    PlayFabClientPtr clientAPI = nullptr;
};

class PlayFabApiTest_RunCloudScript : public IAutomationLatentCommand
{
public:
    PlayFabApiTest_RunCloudScript(const FString& actionId);

    bool Update();
private:
    void OnSuccess(const PlayFab::ClientModels::FRunCloudScriptResult& Result);
    void OnError(const PlayFab::FPlayFabError& ErrorResult);

    FString actionId;

    PlayFabClientPtr clientAPI = nullptr;
};


/*
* ==== Test Suite ====
*/
struct TestTitleData
{
public:
    FString titleId = TEXT("Your titleID");
    FString developerSecretKey = TEXT("For the security of your title, keep your secret key private!");
    FString userName = TEXT("your userName");
    FString userEmail = TEXT("valid email for userName");
    FString userPassword = TEXT("valid password for userName");
    FString characterName = TEXT("arbitrary character name");
};

#define ADD_TEST(Name) TestFunctions.Add(&PlayFabApiTestSuite::Name); TestFunctionNames.Add(TEXT(#Name));
class PlayFabApiTestSuite : public FAutomationTestBase
{
    typedef bool (PlayFabApiTestSuite::*TestFunc)();

public:
    static FString playFabId; // Set by PlayFabApiTest_LoginWithEmail upon successful login
    static FString characterId; // Set by PlayFabApiTest_GetAllUsersCharacters upon successfully finding target character

    // TEST CONSTANTS
    FString TEST_DATA_KEY_1 = TEXT("testCounter");
    FString TEST_DATA_KEY_2 = TEXT("deleteCounter");
    FString TEST_STAT_NAME = TEXT("str");
    FString INVALID_PASSWORD = TEXT("INVALID_PASSWORD");
    FString CHAR_TEST_TYPE = TEXT("Test");
    FString CLOUD_ACTION_ID = TEXT("helloWorld");

    // Input from TestTitleData.json
    TestTitleData testTitleData;

    PlayFabApiTestSuite(const FString& InName)
        : FAutomationTestBase(InName, false)
    {
        LoadTitleData();
        // IPlayFabModuleInterface::Get().SetTitleInformationFromJson(//todo);

        ADD_TEST(InvalidLogin);
        ADD_TEST(LoginOrRegister);
        ADD_TEST(UserDataApi);
        ADD_TEST(UserStatisticsApi);
        ADD_TEST(UserCharacter);
        ADD_TEST(LeaderBoard);
        ADD_TEST(AccountInfo);
        ADD_TEST(CloudScript);
    }

    virtual uint32 GetTestFlags() const override { return EAutomationTestFlags::ATF_Editor; }
    virtual bool IsStressTest() const { return false; }
    virtual uint32 GetRequiredDeviceNum() const override { return 1; }

protected:
    bool LoadTitleData()
    {
        bool success = true;

        FString jsonInput;
        TCHAR* filename = TEXT("C:\\depot\\pf-main\\tools\\SDKBuildScripts\\testTitleData.json");
        success &= FFileHelper::LoadFileToString(jsonInput, filename);

        TSharedPtr<FJsonObject> jsonParsed = nullptr;
        if (success)
        {
            TSharedRef<TJsonReader<>> jsonReader = TJsonReaderFactory<>::Create(jsonInput);
            success &= FJsonSerializer::Deserialize(jsonReader, jsonParsed);
        }

        if (success) success &= jsonParsed->TryGetStringField("titleId", testTitleData.titleId);
        if (success) success &= jsonParsed->TryGetStringField("developerSecretKey", testTitleData.developerSecretKey);
        if (success) success &= jsonParsed->TryGetStringField("userName", testTitleData.userName);
        if (success) success &= jsonParsed->TryGetStringField("userEmail", testTitleData.userEmail);
        if (success) success &= jsonParsed->TryGetStringField("userPassword", testTitleData.userPassword);
        if (success) success &= jsonParsed->TryGetStringField("characterName", testTitleData.characterName);

        return success;
    }

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
        ADD_LATENT_AUTOMATION_COMMAND(PlayFabApiTest_LoginWithEmail(false, false, testTitleData.userName, testTitleData.userEmail, INVALID_PASSWORD));

        return true;
    };

    bool LoginOrRegister()
    {
        ADD_LATENT_AUTOMATION_COMMAND(PlayFabApiTest_LoginWithEmail(true, false, testTitleData.userName, testTitleData.userEmail, testTitleData.userPassword));

        return true;
    };

    bool UserDataApi()
    {
        ADD_LATENT_AUTOMATION_COMMAND(PlayFabApiTest_GetUserData(TEST_DATA_KEY_1, TEST_DATA_KEY_2, -1));

        return true;
    };

    bool UserStatisticsApi()
    {
        ADD_LATENT_AUTOMATION_COMMAND(PlayFabApiTest_UpdateUserStatistics(TEST_STAT_NAME, -1));

        return true;
    };

    bool UserCharacter()
    {
        ADD_LATENT_AUTOMATION_COMMAND(PlayFabApiTest_GetAllUsersCharacters(PlayFabApiTestSuite::playFabId, testTitleData.characterName, CHAR_TEST_TYPE, false));

        return true;
    };

    bool LeaderBoard()
    {
        // These are both read-only, and don't interfere, so they can be run in parallel
        ADD_LATENT_AUTOMATION_COMMAND(PlayFabApiTest_GetLeaderboardAroundCurrentUser(TEST_STAT_NAME));
        ADD_LATENT_AUTOMATION_COMMAND(PlayFabApiTest_GetLeaderboardAroundUser(PlayFabApiTestSuite::playFabId, TEST_STAT_NAME));

        return true;
    };

    bool AccountInfo()
    {
        ADD_LATENT_AUTOMATION_COMMAND(PlayFabApiTest_GetAccountInfo());

        return true;
    };

    bool CloudScript()
    {
        ADD_LATENT_AUTOMATION_COMMAND(PlayFabApiTest_GetCloudScriptUrl(CLOUD_ACTION_ID));

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
