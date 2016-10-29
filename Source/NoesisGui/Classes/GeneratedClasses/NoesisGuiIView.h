////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "NoesisGuiInterface.h"
#include "NoesisGuiIView.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiIView : public UNoesisGuiInterface
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisInterface(Noesis::Core::Interface* NoesisInterface) override;

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Char(int32 Ch);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiFrameworkElement* GetContent();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
FNoesisGuiDrawingSizei GetSize();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
class UNoesisGuiResourceDictionary* GetThemeResources();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void MouseMove(int32 X, int32 Y);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void MouseWheel(int32 X, int32 Y, int32 WheelRotation);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void ResetInputState();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void SetFlags(int32 Flags);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void SetSize(int32 Width, int32 Height);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void TouchDown(int32 X, int32 Y, int32 Id);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void TouchMove(int32 X, int32 Y, int32 Id);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void TouchUp(int32 X, int32 Y, int32 Id);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void Update(float TimeInSeconds);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

