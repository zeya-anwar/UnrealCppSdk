// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFServerGetLeaderboardAroundCharacter.h"

UPFServerGetLeaderboardAroundCharacter::UPFServerGetLeaderboardAroundCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabServerAPI::FGetLeaderboardAroundCharacterDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFServerGetLeaderboardAroundCharacter* UPFServerGetLeaderboardAroundCharacter::GetLeaderboardAroundCharacter(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InStatisticName, const FString& InPlayFabId, const FString& InCharacterId, const FString& InCharacterType, const int32& InMaxResultsCount)
{
	UPFServerGetLeaderboardAroundCharacter* Proxy = NewObject<UPFServerGetLeaderboardAroundCharacter>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.StatisticName = InStatisticName;
	Proxy->Request.PlayFabId = InPlayFabId;
	Proxy->Request.CharacterId = InCharacterId;
	Proxy->Request.CharacterType = InCharacterType;
	Proxy->Request.MaxResultsCount = InMaxResultsCount;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFServerGetLeaderboardAroundCharacter::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

	bool CallResult = false;

	if(ServerAPI.IsValid())
	{	
		CallResult = ServerAPI->GetLeaderboardAroundCharacter(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPServerGetLeaderboardAroundCharacterResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFServerGetLeaderboardAroundCharacter::OnSuccessCallback(const PlayFab::ServerModels::FGetLeaderboardAroundCharacterResult& Result)
{
	FBPServerGetLeaderboardAroundCharacterResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFServerGetLeaderboardAroundCharacter::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPServerGetLeaderboardAroundCharacterResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
