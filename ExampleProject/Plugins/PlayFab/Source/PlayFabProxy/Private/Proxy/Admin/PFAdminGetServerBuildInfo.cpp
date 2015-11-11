// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFAdminGetServerBuildInfo.h"

UPFAdminGetServerBuildInfo::UPFAdminGetServerBuildInfo(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabAdminAPI::FGetServerBuildInfoDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFAdminGetServerBuildInfo* UPFAdminGetServerBuildInfo::GetServerBuildInfo(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InBuildId)
{
	UPFAdminGetServerBuildInfo* Proxy = NewObject<UPFAdminGetServerBuildInfo>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.BuildId = InBuildId;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFAdminGetServerBuildInfo::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

	bool CallResult = false;

	if(AdminAPI.IsValid())
	{	
		CallResult = AdminAPI->GetServerBuildInfo(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPAdminGetServerBuildInfoResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFAdminGetServerBuildInfo::OnSuccessCallback(const PlayFab::AdminModels::FGetServerBuildInfoResult& Result)
{
	FBPAdminGetServerBuildInfoResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFAdminGetServerBuildInfo::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPAdminGetServerBuildInfoResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}