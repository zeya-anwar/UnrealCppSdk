// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabServerAPI.h"
#include "Core/PlayFabServerDataModels.h"
#include "Proxy/PlayFabServerBPDataModels.h"
#include "PFServerDeregisterGame.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFServerDeregisterGame : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnSuccess; 

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnFailure; 
	
	// Inform the matchmaker that a Game Server Instance is removed.
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Server|Matchmaking APIs")
	static UPFServerDeregisterGame* DeregisterGame(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InLobbyId);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ServerModels::FDeregisterGameRequest Request;

	PlayFab::UPlayFabServerAPI::FDeregisterGameDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ServerModels::FDeregisterGameResponse& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
