////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "NoesisBaseComponent.h"
#include "NoesisCommandBinding.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisCommandBinding : public UNoesisBaseComponent
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Command
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisICommand* GetCommand();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetCommand(class UNoesisICommand* InCommand);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisCanExecuteRoutedEventHandler CanExecute;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisExecutedRoutedEventHandler Executed;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisCanExecuteRoutedEventHandler PreviewCanExecute;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisExecutedRoutedEventHandler PreviewExecuted;

	void CanExecute_Private(Noesis::Core::BaseComponent* InSender, const Noesis::CanExecuteRoutedEventArgs& InArgs);

	void Executed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ExecutedRoutedEventArgs& InArgs);

	void PreviewCanExecute_Private(Noesis::Core::BaseComponent* InSender, const Noesis::CanExecuteRoutedEventArgs& InArgs);

	void PreviewExecuted_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ExecutedRoutedEventArgs& InArgs);

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::CanExecuteRoutedEventArgs& InArgs)> CanExecute_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::ExecutedRoutedEventArgs& InArgs)> Executed_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::CanExecuteRoutedEventArgs& InArgs)> PreviewCanExecute_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::ExecutedRoutedEventArgs& InArgs)> PreviewExecuted_Delegate;

};

