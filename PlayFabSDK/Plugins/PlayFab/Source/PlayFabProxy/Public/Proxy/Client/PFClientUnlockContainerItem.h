// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientUnlockContainerItem.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFClientUnlockContainerItem : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPClientUnlockContainerItemResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPClientUnlockContainerItemResultDelegate OnFailure;
	
	// Unlocks a container item in the user's inventory and consumes a key item of the type indicated by the container item
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Client|Player Item Management")
	static UPFClientUnlockContainerItem* UnlockContainerItem(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InContainerItemId, const FString& InCatalogVersion, const FString& InCharacterId);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ClientModels::FUnlockContainerItemRequest Request;

	PlayFab::UPlayFabClientAPI::FUnlockContainerItemDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ClientModels::FUnlockContainerItemResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
