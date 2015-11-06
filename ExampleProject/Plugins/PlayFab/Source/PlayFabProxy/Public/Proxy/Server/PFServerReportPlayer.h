// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabServerAPI.h"
#include "Core/PlayFabServerDataModels.h"
#include "Proxy/PlayFabServerBPDataModels.h"
#include "PFServerReportPlayer.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFServerReportPlayer : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPServerReportPlayerServerResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPServerReportPlayerServerResultDelegate OnFailure;
	
	// Submit a report about a player (due to bad bahavior, etc.) on behalf of another player, so that customer service representatives for the title can take action concerning potentially poxic players.
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Server|Player Item Management")
	static UPFServerReportPlayer* ReportPlayer(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InReporterId, const FString& InReporteeId, const FString& InTitleId, const FString& InComment);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ServerModels::FReportPlayerServerRequest Request;

	PlayFab::UPlayFabServerAPI::FReportPlayerDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ServerModels::FReportPlayerServerResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
