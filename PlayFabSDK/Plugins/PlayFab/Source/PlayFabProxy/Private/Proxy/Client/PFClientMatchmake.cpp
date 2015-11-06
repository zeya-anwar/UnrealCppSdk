// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFClientMatchmake.h"

UPFClientMatchmake::UPFClientMatchmake(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FMatchmakeDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientMatchmake* UPFClientMatchmake::Matchmake(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InBuildVersion, const FString& InGameMode, const FString& InLobbyId, const FString& InStatisticName, const FString& InCharacterId, const bool& InEnableQueue)
{
	UPFClientMatchmake* Proxy = NewObject<UPFClientMatchmake>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.BuildVersion = InBuildVersion;
	
	Proxy->Request.GameMode = InGameMode;
	Proxy->Request.LobbyId = InLobbyId;
	Proxy->Request.StatisticName = InStatisticName;
	Proxy->Request.CharacterId = InCharacterId;
	Proxy->Request.EnableQueue = InEnableQueue;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientMatchmake::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->Matchmake(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPClientMatchmakeResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientMatchmake::OnSuccessCallback(const PlayFab::ClientModels::FMatchmakeResult& Result)
{
	FBPClientMatchmakeResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFClientMatchmake::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPClientMatchmakeResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
