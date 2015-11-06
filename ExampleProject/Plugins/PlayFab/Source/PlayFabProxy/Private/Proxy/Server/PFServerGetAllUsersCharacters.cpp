// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFServerGetAllUsersCharacters.h"

UPFServerGetAllUsersCharacters::UPFServerGetAllUsersCharacters(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabServerAPI::FGetAllUsersCharactersDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFServerGetAllUsersCharacters* UPFServerGetAllUsersCharacters::GetAllUsersCharacters(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InPlayFabId)
{
	UPFServerGetAllUsersCharacters* Proxy = NewObject<UPFServerGetAllUsersCharacters>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.PlayFabId = InPlayFabId;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFServerGetAllUsersCharacters::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

	bool CallResult = false;

	if(ServerAPI.IsValid())
	{	
		CallResult = ServerAPI->GetAllUsersCharacters(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPServerListUsersCharactersResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFServerGetAllUsersCharacters::OnSuccessCallback(const PlayFab::ServerModels::FListUsersCharactersResult& Result)
{
	FBPServerListUsersCharactersResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFServerGetAllUsersCharacters::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPServerListUsersCharactersResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
