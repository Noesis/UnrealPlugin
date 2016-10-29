////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiFrameworkElement.h"
#include "NoesisGuiControl.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiControl : public UNoesisGuiFrameworkElement
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiMouseButtonEventHandler MouseDoubleClick;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiMouseButtonEventHandler PreviewMouseDoubleClick;

	void MouseDoubleClick_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs);

	void PreviewMouseDoubleClick_Private(Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs);

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)> MouseDoubleClick_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::MouseButtonEventArgs& InArgs)> PreviewMouseDoubleClick_Delegate;

};

