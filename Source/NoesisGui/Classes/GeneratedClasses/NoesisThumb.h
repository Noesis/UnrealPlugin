////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisControl.h"
#include "NoesisThumb.generated.h"

UCLASS()
class NOESISGUI_API UNoesisThumb : public UNoesisControl
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property IsDragging
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	bool GetIsDragging();

	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
void CancelDrag();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisDragCompletedEventHandler DragCompleted;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisDragDeltaEventHandler DragDelta;

	UPROPERTY(BlueprintAssignable, Category="NoesisGui")
	FNoesisDragStartedEventHandler DragStarted;

	void DragCompleted_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DragCompletedEventArgs& InArgs);

	void DragDelta_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DragDeltaEventArgs& InArgs);

	void DragStarted_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DragStartedEventArgs& InArgs);

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::DragCompletedEventArgs& InArgs)> DragCompleted_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::DragDeltaEventArgs& InArgs)> DragDelta_Delegate;

	Noesis::Core::Delegate<void (Noesis::Core::BaseComponent* InSender, const Noesis::DragStartedEventArgs& InArgs)> DragStarted_Delegate;

};

