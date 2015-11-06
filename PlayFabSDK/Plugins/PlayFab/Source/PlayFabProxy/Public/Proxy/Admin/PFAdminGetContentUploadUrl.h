// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminGetContentUploadUrl.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFAdminGetContentUploadUrl : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPAdminGetContentUploadUrlResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPAdminGetContentUploadUrlResultDelegate OnFailure;
	
	// Retrieves the pre-signed URL for uploading a content file. A subsequent HTTP PUT to the returned URL uploads the content.
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Admin|Content")
	static UPFAdminGetContentUploadUrl* GetContentUploadUrl(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InKey, const FString& InContentType);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::AdminModels::FGetContentUploadUrlRequest Request;

	PlayFab::UPlayFabAdminAPI::FGetContentUploadUrlDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::AdminModels::FGetContentUploadUrlResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
