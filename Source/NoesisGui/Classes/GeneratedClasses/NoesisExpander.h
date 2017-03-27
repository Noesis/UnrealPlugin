////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisHeaderedContentControl.h"
#include "NoesisExpander.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisExpander : public UNoesisHeaderedContentControl
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property ExpandDirection
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	ENoesisExpandDirection GetExpandDirection();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetExpandDirection(ENoesisExpandDirection InExpandDirection);

	// Property IsExpanded
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsExpanded();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetIsExpanded(bool InIsExpanded);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisRoutedEventHandler Collapsed;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisRoutedEventHandler Expanded;

	void Collapsed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs);

	void Expanded_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs);

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)> Collapsed_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)> Expanded_Delegate;

};

