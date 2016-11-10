////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisContentControl.h"
#include "NoesisBaseButton.generated.h"

UCLASS()
class NOESISGUI_API UNoesisBaseButton : public UNoesisContentControl
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property ClickMode
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisClickMode GetClickMode();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetClickMode(ENoesisClickMode InClickMode);

	// Property Command
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisICommand* GetCommand();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetCommand(class UNoesisICommand* InCommand);

	// Property CommandParameter
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseComponent* GetCommandParameter();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetCommandParameter(class UNoesisBaseComponent* InCommandParameter);

	// Property CommandTarget
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisUIElement* GetCommandTarget();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetCommandTarget(class UNoesisUIElement* InCommandTarget);

	// Property IsPressed
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsPressed();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisRoutedEventHandler Click;

	void Click_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs);

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)> Click_Delegate;

};

