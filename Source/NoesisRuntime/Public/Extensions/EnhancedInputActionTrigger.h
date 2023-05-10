////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#if WITH_ENHANCED_INPUT
// Core includes
#include "CoreMinimal.h"

// EnhancedInput includes
#include "EnhancedInputComponent.h"

// Noesis includes
#include "NoesisSDK.h"
#include "NoesisInstance.h"
#include "NsApp/TriggerBase.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
enum TriggerEvent
{
    TriggerEvent_None = (int)ETriggerEvent::None,
    TriggerEvent_Triggered = (int)ETriggerEvent::Triggered,
    TriggerEvent_Started = (int)ETriggerEvent::Started,
    TriggerEvent_Ongoing = (int)ETriggerEvent::Ongoing,
    TriggerEvent_Canceled = (int)ETriggerEvent::Canceled,
    TriggerEvent_Completed = (int)ETriggerEvent::Completed
};

////////////////////////////////////////////////////////////////////////////////////////////////////
class NOESISRUNTIME_API EnhancedInputActionTrigger : public NoesisApp::TriggerBaseT<Noesis::FrameworkElement>
{
public:
    /// Gets or sets Unreal's input action name
    //@{
    const Noesis::Uri& GetAction() const;
    void SetAction(const Noesis::Uri& Value);
    //@}

    /// Gets or sets action type
    //@{
    TriggerEvent GetTriggerEvent() const;
    void SetTriggerEvent(TriggerEvent Value);
    //@}

public:
    static const Noesis::DependencyProperty* ActionProperty;
    static const Noesis::DependencyProperty* TriggerEventProperty;

protected:
    /// From Freezable
    //@{
    Noesis::Ptr<Noesis::Freezable> CreateInstanceCore() const override;
    //@}

    /// From AttachableObject
    //@{
    void OnAttached() override;
    void OnDetaching() override;
    //@}

private:
    void RegisterAction();
    void UnregisterAction();
    void OnInputAction();
    void OnLoaded(Noesis::BaseComponent* Sender, const Noesis::RoutedEventArgs& Args);
    void OnUnloaded(Noesis::BaseComponent* Sender, const Noesis::RoutedEventArgs& Args);
    void EnsureInstance(Noesis::IView* View);

private:
    UNoesisInstance* mInstance = nullptr;
    uint32 InputBindingHandle = 0;

    friend class UNoesisEnhancedInputDelegateHandler;

    NS_DECLARE_REFLECTION(EnhancedInputActionTrigger, NoesisApp::TriggerBaseT<Noesis::FrameworkElement>)
};

NS_DECLARE_REFLECTION_ENUM_EXPORT(NOESISRUNTIME_API, TriggerEvent)
#endif
