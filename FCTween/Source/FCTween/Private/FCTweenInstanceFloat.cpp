
#include "FCTweenInstanceFloat.h"

void FCTweenInstanceFloat::Initialize(
	UObject* InOwner, FName InName, float InStart, float InEnd, TFunction<void(float)> InOnUpdate, float InDurationSecs, EFCEase InEaseType)
{
	this->Owner = InOwner;
	this->Name = InName;
	this->StartValue = InStart;
	this->EndValue = InEnd;
	this->OnUpdate = MoveTemp(InOnUpdate);
	this->InitializeSharedMembers(InDurationSecs, InEaseType);
}

void FCTweenInstanceFloat::ApplyEasing(float EasedPercent)
{
	OnUpdate(FMath::Lerp<float>(StartValue, EndValue, EasedPercent));
}
