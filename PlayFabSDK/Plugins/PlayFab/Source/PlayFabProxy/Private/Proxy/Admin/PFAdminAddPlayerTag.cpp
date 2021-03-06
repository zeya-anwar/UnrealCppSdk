// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFAdminAddPlayerTag.h"

UPFAdminAddPlayerTag::UPFAdminAddPlayerTag(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabAdminAPI::FAddPlayerTagDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFAdminAddPlayerTag* UPFAdminAddPlayerTag::AddPlayerTag(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InPlayFabId, const FString& InTagName)
{
	UPFAdminAddPlayerTag* Proxy = NewObject<UPFAdminAddPlayerTag>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.PlayFabId = InPlayFabId;
	Proxy->Request.TagName = InTagName;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFAdminAddPlayerTag::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

	bool CallResult = false;

	if(AdminAPI.IsValid())
	{	
		CallResult = AdminAPI->AddPlayerTag(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		OnFailure.Broadcast();
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFAdminAddPlayerTag::OnSuccessCallback(const PlayFab::AdminModels::FAddPlayerTagResult& Result)
{
	OnSuccess.Broadcast();
}

void UPFAdminAddPlayerTag::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	OnFailure.Broadcast();	
}
