// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabServerAPI.h"
#include "Core/PlayFabServerDataModels.h"
#include "Proxy/PlayFabServerBPDataModels.h"
#include "PFServerRedeemCoupon.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFServerRedeemCoupon : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPServerRedeemCouponResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPServerRedeemCouponResultDelegate OnFailure;
	
	// Adds the virtual goods associated with the coupon to the user's inventory. Coupons can be generated  via the Promotions->Coupons tab in the PlayFab Game Manager. See this post for more information on coupons:  https://playfab.com/blog/2015/06/18/using-stores-and-coupons-game-manager
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Server|Player Item Management")
	static UPFServerRedeemCoupon* RedeemCoupon(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InCouponCode, const FString& InPlayFabId, const FString& InCatalogVersion);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ServerModels::FRedeemCouponRequest Request;

	PlayFab::UPlayFabServerAPI::FRedeemCouponDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ServerModels::FRedeemCouponResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};