﻿#pragma once
#include "FCTweenBPAction.h"
#include "FCTweenInstance.h"
#include "Kismet/BlueprintAsyncActionBase.h"

#include "FCTweenBPActionVector2D.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTweenUpdateVector2DOutputPin, FVector2D, Value);

UCLASS()
class FCTWEEN_API UFCTweenBPActionVector2D : public UFCTweenBPAction
{
	GENERATED_BODY()
public:
	FVector2D Start;
	FVector2D End;

	// Triggered every tween update. use "Value" to get the tweened float for this frame
	UPROPERTY(BlueprintAssignable)
	FTweenUpdateVector2DOutputPin ApplyEasing;

	/**
	 * @brief Tween a Vector parameter between the given values
	 * @param Start The starting value
	 * @param End The ending value
	 * @param DurationSecs The seconds to go from start to end
	 * @param EaseType The type of easing function to use for interpolation
	 * @param EaseParam1 Elastic: Amplitude (1.0) / Back: Overshoot (1.70158) / Stepped: Steps (10) / Smoothstep: x0 (0)
	 * @param EaseParam2 Elastic: Period (0.2) / Smoothstep: x1 (1)
	 * @param Delay Seconds before the tween starts interpolating, after being created
	 * @param Loops The number of loops to play. -1 for infinite
	 * @param LoopDelay Seconds to pause before starting each loop
	 * @param bYoyo Whether to "yoyo" the tween - once it reaches the end, it starts counting backwards
	 * @param YoyoDelay Seconds to pause before starting to yoyo
	 * @param bCanTickDuringPause Whether to play this tween while the game is paused. Useful for UI purposes, such as a pause menu
	 */
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", AdvancedDisplay = "4"), Category = "Tween")
	static UFCTweenBPActionVector2D* TweenVector2D(FVector2D Start = FVector2D::ZeroVector, FVector2D End = FVector2D::ZeroVector,
		float DurationSecs = 1.0f, EFCEase EaseType = EFCEase::InOutQuad, float EaseParam1 = 0, float EaseParam2 = 0,
		float Delay = 0, int Loops = 0, float LoopDelay = 0, bool bYoyo = false, float YoyoDelay = 0,
		bool bCanTickDuringPause = false);
	/**
	 * @brief Tween a float parameter between the given values
	 * @param Start The starting value
	 * @param End The ending value
	 * @param DurationSecs The seconds to go from start to end
	 * @param Curve The curve to interpolate with
	 * @param Delay Seconds before the tween starts interpolating, after being created
	 * @param Loops The number of loops to play. -1 for infinite
	 * @param LoopDelay Seconds to pause before starting each loop
	 * @param bYoyo Whether to "yoyo" the tween - once it reaches the end, it starts counting backwards
	 * @param YoyoDelay Seconds to pause before starting to yoyo
	 * @param bCanTickDuringPause Whether to play this tween while the game is paused. Useful for UI purposes, such as a pause menu
	 */
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", AdvancedDisplay = "4"), Category = "Tween|Custom Curve")
	static UFCTweenBPActionVector2D* TweenVector2DCustomCurve(FVector2D Start = FVector2D::ZeroVector,
		FVector2D End = FVector2D::ZeroVector, float DurationSecs = 1.0f, UCurveFloat* Curve = nullptr, float Delay = 0,
		int Loops = 0, float LoopDelay = 0, bool bYoyo = false, float YoyoDelay = 0, bool bCanTickDuringPause = false);

	virtual FCTweenInstance* CreateTween() override;
	virtual FCTweenInstance* CreateTweenCustomCurve() override;
};
