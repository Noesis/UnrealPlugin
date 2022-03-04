////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Core includes
#include "CoreMinimal.h"

// Noesis includes
#include "NoesisSDK.h"
#include "NoesisInstance.h"
#include "NsApp/TriggerBase.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
enum InputActionType
{
    InputActionType_Pressed     = 0,
    InputActionType_Released    = 1,
    InputActionType_Repeat      = 2,
    InputActionType_DoubleClick = 3,
    InputActionType_Axis        = 4
};

////////////////////////////////////////////////////////////////////////////////////////////////////
class NOESISRUNTIME_API InputActionTrigger : public NoesisApp::TriggerBaseT<Noesis::FrameworkElement>
{
public:
    /// Gets or sets Unreal's input action name
    //@{
    const char* GetAction() const;
    void SetAction(const char* value);
    //@}

    /// Gets or sets action type
    //@{
    InputActionType GetType() const;
    void SetType(InputActionType value);
    //@}

    /// Gets or sets a value that indicates if input event is consumed by this action trigger
    //@{
    bool GetConsume() const;
    void SetConsume(bool value);
    //@}

public:
    static const Noesis::DependencyProperty* ActionProperty;
    static const Noesis::DependencyProperty* TypeProperty;
    static const Noesis::DependencyProperty* ConsumeProperty;

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
    void RegisterAction(const char* action, InputActionType type, bool consume);
    void UnregisterAction(const char* action, InputActionType type);
    void OnInputAction();
    void OnLoaded(Noesis::BaseComponent* sender, const Noesis::RoutedEventArgs& e);
    void OnUnloaded(Noesis::BaseComponent* sender, const Noesis::RoutedEventArgs& e);
    void EnsureInstance(Noesis::IView* view);

private:
    UNoesisInstance* mInstance = nullptr;

    NS_DECLARE_REFLECTION(InputActionTrigger, NoesisApp::TriggerBaseT<Noesis::FrameworkElement>)
};

NS_DECLARE_REFLECTION_ENUM_EXPORT(NOESISRUNTIME_API, InputActionType)