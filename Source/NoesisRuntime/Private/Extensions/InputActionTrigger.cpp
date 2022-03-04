////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Extensions/InputActionTrigger.h"


////////////////////////////////////////////////////////////////////////////////////////////////////
const char* InputActionTrigger::GetAction() const
{
    return GetValue<Noesis::String>(ActionProperty).Str();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void InputActionTrigger::SetAction(const char* value)
{
    SetValue<Noesis::String>(ActionProperty, value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
InputActionType InputActionTrigger::GetType() const
{
    return GetValue<InputActionType>(TypeProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void InputActionTrigger::SetType(InputActionType value)
{
    SetValue<InputActionType>(TypeProperty, value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool InputActionTrigger::GetConsume() const
{
    return GetValue<bool>(ConsumeProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void InputActionTrigger::SetConsume(bool value)
{
    SetValue<bool>(ConsumeProperty, value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
Noesis::Ptr<Noesis::Freezable> InputActionTrigger::CreateInstanceCore() const
{
    return* new InputActionTrigger();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void InputActionTrigger::OnAttached()
{
    ParentClass::OnAttached();

    Noesis::FrameworkElement* element = GetAssociatedObject();
    element->Loaded() += Noesis::MakeDelegate(this, &InputActionTrigger::OnLoaded);
    element->Unloaded() += Noesis::MakeDelegate(this, &InputActionTrigger::OnUnloaded);
    EnsureInstance(element->GetView());
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void InputActionTrigger::OnDetaching()
{
    UnregisterAction(GetAction(), GetType());

    ParentClass::OnDetaching();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void InputActionTrigger::RegisterAction(const char* action, InputActionType type, bool consume)
{
    if (mInstance != nullptr && !Noesis::StrIsEmpty(action))
    {
        FInputActionBinding binding(UTF8_TO_TCHAR(action), (EInputEvent)type);
        binding.ActionDelegate.GetDelegateForManualSet().BindRaw(this, &InputActionTrigger::OnInputAction);
        mInstance->RegisterInputAction(binding);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void InputActionTrigger::UnregisterAction(const char* action, InputActionType type)
{
    if (mInstance != nullptr && !Noesis::StrIsEmpty(action))
    {
        FInputActionBinding binding(UTF8_TO_TCHAR(action), (EInputEvent)type);
        mInstance->UnregisterInputAction(binding);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void InputActionTrigger::OnInputAction()
{
    InvokeActions(nullptr);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void InputActionTrigger::OnLoaded(Noesis::BaseComponent* sender, const Noesis::RoutedEventArgs& e)
{
    EnsureInstance(GetAssociatedObject()->GetView());
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void InputActionTrigger::OnUnloaded(Noesis::BaseComponent* sender, const Noesis::RoutedEventArgs& e)
{
    if (mInstance != nullptr)
    {
        UnregisterAction(GetAction(), GetType());
        mInstance = nullptr;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void InputActionTrigger::EnsureInstance(Noesis::IView* view)
{
    if (view != nullptr && mInstance == nullptr)
    {
        mInstance = UNoesisInstance::FromView(view);
        RegisterAction(GetAction(), GetType(), GetConsume());
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_IMPLEMENT_REFLECTION_ENUM(InputActionType, "NoesisGUIExtensions.InputActionType")
{
    NsVal("Pressed", InputActionType_Pressed);
    NsVal("Released", InputActionType_Released);
    NsVal("Repeat", InputActionType_Repeat);
    NsVal("DoubleClick", InputActionType_DoubleClick);
    NsVal("Axis", InputActionType_Axis);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_IMPLEMENT_REFLECTION(InputActionTrigger, "NoesisGUIExtensions.InputActionTrigger")
{
    auto OnActionChanged = [](Noesis::DependencyObject* d, const Noesis::DependencyPropertyChangedEventArgs& e)
    {
        InputActionTrigger* trigger = (InputActionTrigger*)d;
        const char* oldAction = e.OldValue<Noesis::String>().Str();
        const char* newAction = e.NewValue<Noesis::String>().Str();
        InputActionType type = trigger->GetType();
        trigger->UnregisterAction(oldAction, type);
        trigger->RegisterAction(newAction, type, trigger->GetConsume());
    };

    auto OnTypeChanged = [](Noesis::DependencyObject* d, const Noesis::DependencyPropertyChangedEventArgs& e)
    {
        InputActionTrigger* trigger = (InputActionTrigger*)d;
        const char* action = trigger->GetAction();
        InputActionType oldType = e.OldValue<InputActionType>();
        InputActionType newType = e.NewValue<InputActionType>();
        trigger->UnregisterAction(action, oldType);
        trigger->RegisterAction(action, newType, trigger->GetConsume());
    };

    auto OnConsumeChanged = [](Noesis::DependencyObject* d, const Noesis::DependencyPropertyChangedEventArgs& e)
    {
        InputActionTrigger* trigger = (InputActionTrigger*)d;
        const char* action = trigger->GetAction();
        InputActionType type = trigger->GetType();
        trigger->UnregisterAction(action, type);
        trigger->RegisterAction(action, type, e.NewValue<bool>());
    };

    Noesis::UIElementData* data = NsMeta<Noesis::UIElementData>(Noesis::TypeOf<SelfClass>());
    data->RegisterProperty<Noesis::String>(ActionProperty, "Action",
        Noesis::FrameworkPropertyMetadata::Create(Noesis::String(),
            Noesis::PropertyChangedCallback(OnActionChanged)));
    data->RegisterProperty<InputActionType>(TypeProperty, "Type",
        Noesis::FrameworkPropertyMetadata::Create(InputActionType_Pressed,
            Noesis::PropertyChangedCallback(OnTypeChanged)));
    data->RegisterProperty<bool>(ConsumeProperty, "Consume",
        Noesis::FrameworkPropertyMetadata::Create(false,
            Noesis::PropertyChangedCallback(OnConsumeChanged)));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
const Noesis::DependencyProperty* InputActionTrigger::ActionProperty;
const Noesis::DependencyProperty* InputActionTrigger::TypeProperty;
const Noesis::DependencyProperty* InputActionTrigger::ConsumeProperty;
