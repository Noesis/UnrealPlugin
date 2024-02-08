////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Extensions/EnhancedInputActionTrigger.h"

#if WITH_ENHANCED_INPUT
// EnhancedInput includes
#include "InputAction.h"

// NoesisRuntime includes
#include "NoesisRuntimeModule.h"
#include "NoesisSupport.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
class UNoesisEnhancedInputDelegateHandler : public UObject
{
public:
    void ForwardAction(EnhancedInputActionTrigger* Trigger)
    {
        Trigger->OnInputAction();
    }
};


////////////////////////////////////////////////////////////////////////////////////////////////////
const Noesis::Uri& EnhancedInputActionTrigger::GetAction() const
{
    return GetValue<Noesis::Uri>(ActionProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void EnhancedInputActionTrigger::SetAction(const Noesis::Uri& Value)
{
    SetValue<Noesis::Uri>(ActionProperty, Value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
TriggerEvent EnhancedInputActionTrigger::GetTriggerEvent() const
{
    return GetValue<TriggerEvent>(TriggerEventProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void EnhancedInputActionTrigger::SetTriggerEvent(TriggerEvent Value)
{
    SetValue<TriggerEvent>(TriggerEventProperty, Value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
Noesis::Ptr<Noesis::Freezable> EnhancedInputActionTrigger::CreateInstanceCore() const
{
    return* new EnhancedInputActionTrigger();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void EnhancedInputActionTrigger::OnAttached()
{
    ParentClass::OnAttached();

    Noesis::FrameworkElement* Element = GetAssociatedObject();
    Element->Loaded() += Noesis::MakeDelegate(this, &EnhancedInputActionTrigger::OnLoaded);
    Element->Unloaded() += Noesis::MakeDelegate(this, &EnhancedInputActionTrigger::OnUnloaded);
    EnsureInstance(Element->GetView());
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void EnhancedInputActionTrigger::OnDetaching()
{
    Noesis::FrameworkElement* Element = GetAssociatedObject();
    Element->Loaded() -= Noesis::MakeDelegate(this, &EnhancedInputActionTrigger::OnLoaded);
    Element->Unloaded() -= Noesis::MakeDelegate(this, &EnhancedInputActionTrigger::OnUnloaded);
    UnregisterAction();

    ParentClass::OnDetaching();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void EnhancedInputActionTrigger::RegisterAction()
{
    if (mInstance != nullptr)
    {
        auto InputComponent = mInstance->GetInputComponent();

        if (auto EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
        {
            const Noesis::Uri& ActionUri = GetAction();
            FString ActionPath = NsProviderUriToAssetPath(ActionUri);
            UInputAction* Action = LoadObject<UInputAction>(nullptr, *ActionPath, nullptr, LOAD_NoWarn);
            ETriggerEvent TriggerEvent = (ETriggerEvent)GetTriggerEvent();
            if (Action == nullptr)
            {
                NS_LOG("InputAction %s not found (URI: %s)", *ActionPath, UTF8_TO_TCHAR(ActionUri.Str()));
                return;
            }

            InputBindingHandle = EnhancedInputComponent->BindAction(Action, TriggerEvent, GetMutableDefault<UNoesisEnhancedInputDelegateHandler>(), &UNoesisEnhancedInputDelegateHandler::ForwardAction, this).GetHandle();
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void EnhancedInputActionTrigger::UnregisterAction()
{
    if (mInstance != nullptr && InputBindingHandle != 0)
    {
        auto InputComponent = mInstance->GetInputComponent();

        if (auto EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
        {
            EnhancedInputComponent->RemoveBindingByHandle(InputBindingHandle);
            InputBindingHandle = 0;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void EnhancedInputActionTrigger::OnInputAction()
{
    InvokeActions(nullptr);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void EnhancedInputActionTrigger::OnLoaded(Noesis::BaseComponent* Sender, const Noesis::RoutedEventArgs&)
{
    EnsureInstance(GetAssociatedObject()->GetView());
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void EnhancedInputActionTrigger::OnUnloaded(Noesis::BaseComponent* Sender, const Noesis::RoutedEventArgs&)
{
    if (mInstance != nullptr)
    {
        UnregisterAction();
        mInstance = nullptr;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void EnhancedInputActionTrigger::EnsureInstance(Noesis::IView* View)
{
    if (View != nullptr && mInstance == nullptr)
    {
        mInstance = UNoesisInstance::FromView(View);
        RegisterAction();
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_IMPLEMENT_REFLECTION_ENUM(TriggerEvent, "NoesisGUIExtensions.TriggerEvent")
{
    NsVal("Triggered", TriggerEvent_Triggered);
    NsVal("Started", TriggerEvent_Started);
	NsVal("Ongoing", TriggerEvent_Ongoing);
	NsVal("Canceled", TriggerEvent_Canceled);
	NsVal("Completed", TriggerEvent_Completed);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_IMPLEMENT_REFLECTION(EnhancedInputActionTrigger, "NoesisGUIExtensions.EnhancedInputActionTrigger")
{
    auto OnActionChanged = [](Noesis::DependencyObject* Object, const Noesis::DependencyPropertyChangedEventArgs&)
    {
        EnhancedInputActionTrigger* Trigger = (EnhancedInputActionTrigger*)Object;
        Trigger->UnregisterAction();
        Trigger->RegisterAction();
    };

    auto OnTriggerEventChanged = [](Noesis::DependencyObject* Object, const Noesis::DependencyPropertyChangedEventArgs&)
    {
        EnhancedInputActionTrigger* Trigger = (EnhancedInputActionTrigger*)Object;
        Trigger->UnregisterAction();
        Trigger->RegisterAction();
    };

    Noesis::UIElementData* Data = NsMeta<Noesis::UIElementData>(Noesis::TypeOf<SelfClass>());
    Data->RegisterProperty<Noesis::Uri>(ActionProperty, "Action",
        Noesis::FrameworkPropertyMetadata::Create(Noesis::Uri(),
            Noesis::PropertyChangedCallback(OnActionChanged)));
    Data->RegisterProperty<TriggerEvent>(TriggerEventProperty, "TriggerEvent",
        Noesis::FrameworkPropertyMetadata::Create(TriggerEvent_Triggered,
            Noesis::PropertyChangedCallback(OnTriggerEventChanged)));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
const Noesis::DependencyProperty* EnhancedInputActionTrigger::ActionProperty;
const Noesis::DependencyProperty* EnhancedInputActionTrigger::TriggerEventProperty;

#endif
