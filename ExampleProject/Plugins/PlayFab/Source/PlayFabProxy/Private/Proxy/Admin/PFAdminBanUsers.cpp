// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFAdminBanUsers.h"

UPFAdminBanUsers::UPFAdminBanUsers(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabAdminAPI::FBanUsersDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFAdminBanUsers* UPFAdminBanUsers::BanUsers(UObject* WorldContextObject, class APlayerController* PlayerController , const TArray<FBPAdminBanRequest>& InBans)
{
	UPFAdminBanUsers* Proxy = NewObject<UPFAdminBanUsers>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	for (const FBPAdminBanRequest& elem : InBans)
    {
        Proxy->Request.Bans.Add(elem.Data);
    }

	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFAdminBanUsers::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

	bool CallResult = false;

	if(AdminAPI.IsValid())
	{	
		CallResult = AdminAPI->BanUsers(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPAdminBanUsersResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFAdminBanUsers::OnSuccessCallback(const PlayFab::AdminModels::FBanUsersResult& Result)
{
	FBPAdminBanUsersResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFAdminBanUsers::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPAdminBanUsersResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
