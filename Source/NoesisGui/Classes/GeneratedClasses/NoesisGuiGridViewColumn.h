////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiDependencyObject.h"
#include "NoesisGuiGridViewColumn.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiGridViewColumn : public UNoesisGuiDependencyObject
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property ActualWidth
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	float GetActualWidth();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetActualWidth(float InActualWidth);

	// Property DisplayMemberBinding
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisGuiBaseBindingExpression* GetDisplayMemberBinding();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetDisplayMemberBinding(class UNoesisGuiBaseBindingExpression* InDisplayMemberBinding);

	// UObject interface
	virtual void BeginDestroy() override;
	// End of UObject interface
};

