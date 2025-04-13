
#include "Blueprints/FCTweenBlueprintLibrary.h"

#include "FCTween.h"

float UFCTweenBlueprintLibrary::Ease(float t, EFCEase EaseType)

{
	return FCEasing::Ease(t, EaseType);
}

float UFCTweenBlueprintLibrary::EaseWithParams(float t, EFCEase EaseType, float Param1, float Param2)
{
	return FCEasing::EaseWithParams(t, EaseType, Param1, Param2);
}

void UFCTweenBlueprintLibrary::EnsureTweenCapacity(
	int NumFloatTweens, int NumVectorTweens, int NumVector2DTweens, int NumQuatTweens)
{
	FCTween::EnsureCapacity(NumFloatTweens, NumVectorTweens, NumVector2DTweens, NumQuatTweens);
}

void UFCTweenBlueprintLibrary::TweenFloat(UObject* Owner, FName Name, float Start, float End, float Delay,
	float Duration, EFCEase EaseType, FFCTweenOnUpdateFloat OnUpdate, FFCTweenOnComplete OnComplete)
{
	TFunction<void(float)> OnUpdateFunc = [OnUpdate](float Value)
	{
		OnUpdate.ExecuteIfBound(Value);
	};
	TFunction<void()> OnCompleteFunc = [OnComplete]()
	{
		OnComplete.ExecuteIfBound();
	};
	FCTween::Play(Owner, Name, Start, End, OnUpdateFunc, Duration, EaseType)
	->SetDelay(Delay)
	->SetOnComplete(OnCompleteFunc);
}

void UFCTweenBlueprintLibrary::StopTween(UObject* Owner, FName Name)
{
	FCTween::Stop(Owner, Name);
}

void UFCTweenBlueprintLibrary::StopAllTweens(UObject* Owner)
{
	FCTween::Stop(Owner);
}

bool UFCTweenBlueprintLibrary::IsTweening(UObject* Owner, FName Name)
{
	return FCTween::IsPlaying(Owner, Name);
}
