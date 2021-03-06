// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabServerAPI.h"
#include "Core/PlayFabServerDataModels.h"
#include "Proxy/PlayFabServerBPDataModels.h"
#include "PFServerRedeemMatchmakerTicket.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFServerRedeemMatchmakerTicket : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPServerRedeemMatchmakerTicketResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPServerRedeemMatchmakerTicketResultDelegate OnFailure;
	
	// Validates a Game Server session ticket and returns details about the user
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Server|Matchmaking APIs")
	static UPFServerRedeemMatchmakerTicket* RedeemMatchmakerTicket(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InTicket, const FString& InLobbyId);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ServerModels::FRedeemMatchmakerTicketRequest Request;

	PlayFab::UPlayFabServerAPI::FRedeemMatchmakerTicketDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ServerModels::FRedeemMatchmakerTicketResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
