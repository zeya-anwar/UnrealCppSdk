// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientRedeemCoupon.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFClientRedeemCoupon : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPClientRedeemCouponResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPClientRedeemCouponResultDelegate OnFailure;
	
	// Adds the virtual goods associated with the coupon to the user's inventory. Coupons can be generated  via the Promotions->Coupons tab in the PlayFab Game Manager. See this post for more information on coupons:  https://playfab.com/blog/2015/06/18/using-stores-and-coupons-game-manager
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Client|Player Item Management")
	static UPFClientRedeemCoupon* RedeemCoupon(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InCouponCode, const FString& InCatalogVersion);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ClientModels::FRedeemCouponRequest Request;

	PlayFab::UPlayFabClientAPI::FRedeemCouponDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ClientModels::FRedeemCouponResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
