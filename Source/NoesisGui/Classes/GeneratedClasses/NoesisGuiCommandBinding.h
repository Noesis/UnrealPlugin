////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "NoesisGuiBaseComponent.h"
#include "NoesisGuiCommandBinding.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiCommandBinding : public UNoesisGuiBaseComponent
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property Command
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	UNoesisGuiICommand* GetCommand();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetCommand(UNoesisGuiICommand* InCommand);

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiCanExecuteRoutedEventHandler CanExecute;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiExecutedRoutedEventHandler Executed;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiCanExecuteRoutedEventHandler PreviewCanExecute;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisGuiExecutedRoutedEventHandler PreviewExecuted;

	void CanExecute_Private(Noesis::Core::BaseComponent* InSender, const Noesis::CanExecuteRoutedEventArgs& InArgs);

	void Executed_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ExecutedRoutedEventArgs& InArgs);

	void PreviewCanExecute_Private(Noesis::Core::BaseComponent* InSender, const Noesis::CanExecuteRoutedEventArgs& InArgs);

	void PreviewExecuted_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ExecutedRoutedEventArgs& InArgs);

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::CanExecuteRoutedEventArgs& InArgs)> CanExecute_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::ExecutedRoutedEventArgs& InArgs)> Executed_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::CanExecuteRoutedEventArgs& InArgs)> PreviewCanExecute_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::ExecutedRoutedEventArgs& InArgs)> PreviewExecuted_Delegate;

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

