// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFAdminModifyServerBuild.h"

UPFAdminModifyServerBuild::UPFAdminModifyServerBuild(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabAdminAPI::FModifyServerBuildDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFAdminModifyServerBuild* UPFAdminModifyServerBuild::ModifyServerBuild(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InBuildId, const FDateTime& InTimestamp, const int32& InMaxGamesPerHost, const FString& InCommandLineTemplate, const FString& InExecutablePath, const FString& InComment)
{
	UPFAdminModifyServerBuild* Proxy = NewObject<UPFAdminModifyServerBuild>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.BuildId = InBuildId;
	
	
	Proxy->Request.MaxGamesPerHost = InMaxGamesPerHost;
	Proxy->Request.CommandLineTemplate = InCommandLineTemplate;
	Proxy->Request.ExecutablePath = InExecutablePath;
	Proxy->Request.Comment = InComment;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFAdminModifyServerBuild::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

	bool CallResult = false;

	if(AdminAPI.IsValid())
	{	
		CallResult = AdminAPI->ModifyServerBuild(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPAdminModifyServerBuildResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFAdminModifyServerBuild::OnSuccessCallback(const PlayFab::AdminModels::FModifyServerBuildResult& Result)
{
	FBPAdminModifyServerBuildResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFAdminModifyServerBuild::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPAdminModifyServerBuildResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
