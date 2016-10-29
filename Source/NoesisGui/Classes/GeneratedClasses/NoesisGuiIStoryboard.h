////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "NoesisGuiInterface.h"
#include "NoesisGuiIStoryboard.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiIStoryboard : public UNoesisGuiInterface
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisInterface(Noesis::Core::Interface* NoesisInterface) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Begin();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool IsPaused();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
bool IsPlaying();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Pause();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Remove();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Resume();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Stop();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

