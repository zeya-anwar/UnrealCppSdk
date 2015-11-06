// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientUpdateCharacterData.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFClientUpdateCharacterData : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPClientUpdateCharacterDataResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPClientUpdateCharacterDataResultDelegate OnFailure;
	
	// Creates and updates the title-specific custom data for the user's character which is readable  and writable by the client
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Client|Character Data")
	static UPFClientUpdateCharacterData* UpdateCharacterData(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InCharacterId, const FString& InData, const TArray<FString>& InKeysToRemove);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ClientModels::FUpdateCharacterDataRequest Request;

	PlayFab::UPlayFabClientAPI::FUpdateCharacterDataDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ClientModels::FUpdateCharacterDataResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
