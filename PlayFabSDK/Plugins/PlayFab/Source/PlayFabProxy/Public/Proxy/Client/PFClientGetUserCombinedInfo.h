// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientGetUserCombinedInfo.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFClientGetUserCombinedInfo : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPClientGetUserCombinedInfoResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPClientGetUserCombinedInfoResultDelegate OnFailure;
	
	// NOTE: This call will be deprecated soon. For fetching the data for a given user  use GetPlayerCombinedInfo. For looking up users from the client api, we are in the process of adding a new api call. Once that call is ready, this one will be deprecated.  Retrieves all requested data for a user in one unified request. By default, this API returns all  data for the locally signed-in user. The input parameters may be used to limit the data retrieved to any subset of the available data, as well as retrieve the available data for a different user. Note that certain data, including inventory, virtual currency balances, and personally identifying information, may only be retrieved for the locally signed-in user. In the example below, a request is made for the account details, virtual currency balances, and specified user data for the locally signed-in user.
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Client|Account Management")
	static UPFClientGetUserCombinedInfo* GetUserCombinedInfo(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InPlayFabId, const FString& InUsername, const FString& InEmail, const FString& InTitleDisplayName, const bool& InGetAccountInfo, const bool& InGetInventory, const bool& InGetVirtualCurrency, const bool& InGetUserData, const TArray<FString>& InUserDataKeys, const bool& InGetReadOnlyData, const TArray<FString>& InReadOnlyDataKeys);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ClientModels::FGetUserCombinedInfoRequest Request;

	PlayFab::UPlayFabClientAPI::FGetUserCombinedInfoDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ClientModels::FGetUserCombinedInfoResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
