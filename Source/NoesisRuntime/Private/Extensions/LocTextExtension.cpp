////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Extensions/LocTextExtension.h"
#include "NsGui/ContentPropertyMetaData.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
class LocTextExpression : public Noesis::Expression
{
public:
    LocTextExpression(LocTextExtension* extension, Noesis::DependencyObject* targetObject, const Noesis::DependencyProperty* targetProperty)
        : mExtension(extension), mTargetObject(targetObject), mTargetProperty(targetProperty)
    {
        CultureChangedHandle = FTextLocalizationManager::Get().OnTextRevisionChangedEvent.AddRaw(this, &LocTextExpression::OnCultureChanged);
    }

    ~LocTextExpression()
    {
        FTextLocalizationManager::Get().OnTextRevisionChangedEvent.Remove(CultureChangedHandle);
    }

    Noesis::Ptr<Noesis::BaseComponent> Evaluate() const
    {
        FString DisplayString = mExtension->GetDisplayString(mTargetObject);
        return Noesis::Boxing::Box(TCHAR_TO_UTF8(*DisplayString));
    }

    Noesis::Ptr<Noesis::Expression> Reapply(Noesis::DependencyObject* targetObject, const Noesis::DependencyProperty* targetProperty) const
    {
        if (mTargetObject == targetObject && mTargetProperty == targetProperty)
        {
            return Noesis::Ptr<Noesis::Expression>((LocTextExpression*)this);
        }
        else
        {
            return *new LocTextExpression(mExtension, targetObject, targetProperty);
        }
    }

    Noesis::BeforeSetAction BeforeSet(Noesis::DependencyObject* obj, const Noesis::DependencyProperty* dp, const void* value, bool valueHasChanged)
    {
        return Noesis::BeforeSetAction_Default;
    }

    void AfterSet(Noesis::DependencyObject* obj, const Noesis::DependencyProperty* dp, const void* value, bool valueHasChanged)
    {
    }

    void OnCultureChanged()
    {
        mTargetObject->InvalidateProperty(mTargetProperty);
    }

private:
    Noesis::Ptr<LocTextExtension> mExtension;
    Noesis::DependencyObject* mTargetObject;
    const Noesis::DependencyProperty* mTargetProperty;
    FDelegateHandle CultureChangedHandle;

    NS_IMPLEMENT_INLINE_REFLECTION_(LocTextExpression, Noesis::Expression)
};

////////////////////////////////////////////////////////////////////////////////////////////////////
const char* LocTextExtension::GetNamespace() const
{
    return mNamespace.Str();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void LocTextExtension::SetNamespace(const char* value)
{
    mNamespace = value;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
const char* LocTextExtension::GetKey() const
{
    return mKey.Str();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void LocTextExtension::SetKey(const char* value)
{
    mKey = value;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
const char* LocTextExtension::GetSource() const
{
    return mSource.Str();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void LocTextExtension::SetSource(const char* value)
{
    mSource = value;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
FString LocTextExtension::GetDisplayString(Noesis::DependencyObject* object)
{
    const char* ns = GetNamespace();
    if (strlen(ns) == 0)
    {
        ns = object->GetValue<Noesis::String>(NamespaceProperty).Str();
    }
    FText Text;
    FString Source(UTF8_TO_TCHAR(GetSource()));
    FText::FindText(UTF8_TO_TCHAR(ns), UTF8_TO_TCHAR(GetKey()), Text, &Source);
    return Text.ToString();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
Noesis::Ptr<Noesis::BaseComponent> LocTextExtension::ProvideValue(const Noesis::ValueTargetProvider* provider)
{
    return *new LocTextExpression(this,
        Noesis::DynamicCast<Noesis::DependencyObject*>(provider->GetTargetObject()),
        provider->GetTargetProperty());
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_IMPLEMENT_REFLECTION(LocTextExtension, "NoesisGUIExtensions.LocText")
{
    NsMeta<Noesis::ContentPropertyMetaData>("Source");

    NsProp("Namespace", &LocTextExtension::GetNamespace, &LocTextExtension::SetNamespace);
    NsProp("Key", &LocTextExtension::GetKey, &LocTextExtension::SetKey);
    NsProp("Source", &LocTextExtension::GetSource, &LocTextExtension::SetSource);

    Noesis::UIElementData* data = NsMeta<Noesis::UIElementData>(Noesis::TypeOf<SelfClass>());
    data->RegisterProperty<Noesis::String>(NamespaceProperty, "Namespace",
        Noesis::FrameworkPropertyMetadata::Create(Noesis::String(), Noesis::FrameworkPropertyMetadataOptions_Inherits));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
const Noesis::DependencyProperty* LocTextExtension::NamespaceProperty;
