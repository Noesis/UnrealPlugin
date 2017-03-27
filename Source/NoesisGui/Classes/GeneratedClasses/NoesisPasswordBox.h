////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisControl.h"
#include "NoesisPasswordBox.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisPasswordBox : public UNoesisControl
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property CaretBrush
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBrush* GetCaretBrush();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetCaretBrush(class UNoesisBrush* InCaretBrush);

	// Property MaxLength
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	int32 GetMaxLength();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetMaxLength(int32 InMaxLength);

	// Property Password
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetPassword();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetPassword(FString InPassword);

	// Property PasswordChar
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	int32 GetPasswordChar();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetPasswordChar(int32 InPasswordChar);

	// Property SelectionBrush
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBrush* GetSelectionBrush();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetSelectionBrush(class UNoesisBrush* InSelectionBrush);

	// Property SelectionOpacity
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetSelectionOpacity();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetSelectionOpacity(float InSelectionOpacity);

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SelectAll();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisRoutedEventHandler PasswordChanged;

	void PasswordChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs);

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)> PasswordChanged_Delegate;

};

