// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientGetSharedGroupData.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFClientGetSharedGroupData : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPClientGetSharedGroupDataResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPClientGetSharedGroupDataResultDelegate OnFailure;
	
	// Retrieves data stored in a shared group object, as well as the list of members in the group. Non-members of the group may use this to retrieve group data, including membership, but they will not receive data for keys marked as private.
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Client|Shared Group Data")
	static UPFClientGetSharedGroupData* GetSharedGroupData(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InSharedGroupId, const TArray<FString>& InKeys, const bool& InGetMembers);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ClientModels::FGetSharedGroupDataRequest Request;

	PlayFab::UPlayFabClientAPI::FGetSharedGroupDataDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ClientModels::FGetSharedGroupDataResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
