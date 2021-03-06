// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFClientAttributeInstall.h"

UPFClientAttributeInstall::UPFClientAttributeInstall(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FAttributeInstallDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientAttributeInstall* UPFClientAttributeInstall::AttributeInstall(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InIdfa, const FString& InAndroid_Id, const FString& InAdid)
{
	UPFClientAttributeInstall* Proxy = NewObject<UPFClientAttributeInstall>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.Idfa = InIdfa;
	Proxy->Request.Android_Id = InAndroid_Id;
	Proxy->Request.Adid = InAdid;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientAttributeInstall::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->AttributeInstall(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		OnFailure.Broadcast();
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientAttributeInstall::OnSuccessCallback(const PlayFab::ClientModels::FAttributeInstallResult& Result)
{
	OnSuccess.Broadcast();
}

void UPFClientAttributeInstall::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	OnFailure.Broadcast();	
}
