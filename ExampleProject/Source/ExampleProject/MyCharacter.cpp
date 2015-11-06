// Fill out your copyright notice in the Description page of Project Settings.

#include "ExampleProject.h"
#include "MyCharacter.h"

#include "PlayFab.h"
#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
    Super::SetupPlayerInputComponent(InputComponent);

}













/**
* Start flailing randomly and see if a unit test emerges
*/

//DEFINE_LATENT_AUTOMATION_COMMAND(PlayFabApiTests);
//
//bool PlayFabApiTests::Update()
//{
//    return GUnitTestManager == NULL || !GUnitTestManager->IsRunningUnitTests();
//}

#define ADD_TEST(Name) \
	TestFunctions.Add(&FPlayFabApiTests::Name); TestFunctionNames.Add(TEXT(#Name));

class FPlayFabApiTests : public FAutomationTestBase
{
public:
    typedef bool (FPlayFabApiTests::*TestFunc)();

    FPlayFabApiTests(const FString& InName)
        : FAutomationTestBase(InName, false)
    {
        ADD_TEST(Test_LoginOrRegister);
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
        if (!clientAPI.IsValid())
            return false;

        // find the matching test
        TestFunc TestFunction = nullptr;
        for (int32 i = 0; i < TestFunctionNames.Num(); ++i)
        {
            if (TestFunctionNames[i] == Parameters)
            {
                TestFunction = TestFunctions[i];
                break;
            }
        }
        if (TestFunction == nullptr)
            return false;

        return (this->*TestFunction)();
    }

    bool Test_LoginOrRegister()
    {
        PlayFab::ClientModels::FLoginWithEmailAddressRequest request;
        request.Email = TEXT("paul@playfab.com");
        request.Password = TEXT("testPassword");

        clientAPI->LoginWithEmailAddress(request
            , PlayFab::UPlayFabClientAPI::FLoginWithEmailAddressDelegate::CreateRaw(this, &FPlayFabApiTests::OnLoginSucess)
            , PlayFab::FPlayFabErrorDelegate::CreateRaw(this, &FPlayFabApiTests::OnLoginError)
        );

        return true;
    };

    void OnLoginSucess(const PlayFab::ClientModels::FLoginResult& Result)
    {
        // These don't currently affect the actual result, as I have to get the result back to Test_LoginOrRegister
        TestTrue(TEXT("Testing if you can fail from within a callback."), true);
    }

    void OnLoginError(const PlayFab::FPlayFabError& Error)
    {
        // These don't currently affect the actual result, as I have to get the result back to Test_LoginOrRegister
        TestTrue(TEXT("Callback failed."), false);
    }

    PlayFabClientPtr clientAPI;

    TArray<TestFunc> TestFunctions;
    TArray<FString> TestFunctionNames;
};

namespace
{
    FPlayFabApiTests FPlayFabApiTestsAutomationTestInstance(TEXT("FPlayFabApiTests"));
}

//IMPLEMENT_COMPLEX_AUTOMATION_TEST(PlayFabApiTests, "PlayFabApiTests", EAutomationTestFlags::ATF_Game)
