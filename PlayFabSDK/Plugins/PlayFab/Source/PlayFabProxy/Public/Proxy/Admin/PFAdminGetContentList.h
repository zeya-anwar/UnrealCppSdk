// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminGetContentList.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFAdminGetContentList : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPAdminGetContentListResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPAdminGetContentListResultDelegate OnFailure;
	
	// List all contents of the title and get statistics such as size
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Admin|Content")
	static UPFAdminGetContentList* GetContentList(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InPrefix);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::AdminModels::FGetContentListRequest Request;

	PlayFab::UPlayFabAdminAPI::FGetContentListDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::AdminModels::FGetContentListResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
