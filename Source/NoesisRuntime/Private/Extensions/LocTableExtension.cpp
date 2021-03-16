////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Extensions/LocTableExtension.h"
#include "NsGui/ContentPropertyMetaData.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
class LocTableExpression : public Noesis::Expression
{
public:
    LocTableExpression(LocTableExtension* extension, Noesis::DependencyObject* targetObject, const Noesis::DependencyProperty* targetProperty)
        : mExtension(extension), mTargetObject(targetObject), mTargetProperty(targetProperty)
    {
        CultureChangedHandle = FTextLocalizationManager::Get().OnTextRevisionChangedEvent.AddRaw(this, &LocTableExpression::OnCultureChanged);
    }

    ~LocTableExpression()
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
            return Noesis::Ptr<Noesis::Expression>((LocTableExpression*)this);
        }
        else
        {
            return *new LocTableExpression(mExtension, targetObject, targetProperty);
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
    Noesis::Ptr<LocTableExtension> mExtension;
    Noesis::DependencyObject* mTargetObject;
    const Noesis::DependencyProperty* mTargetProperty;
    FDelegateHandle CultureChangedHandle;

    NS_IMPLEMENT_INLINE_REFLECTION_(LocTableExpression, Noesis::Expression)
};

////////////////////////////////////////////////////////////////////////////////////////////////////
const char* LocTableExtension::GetId() const
{
    return mId.Str();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void LocTableExtension::SetId(const char* value)
{
    mId = value;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
const char* LocTableExtension::GetKey() const
{
    return mKey.Str();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void LocTableExtension::SetKey(const char* value)
{
    mKey = value;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
const char* LocTableExtension::GetSource() const
{
    return mSource.Str();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void LocTableExtension::SetSource(const char* value)
{
    mSource = value;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
FString LocTableExtension::GetDisplayString(Noesis::DependencyObject* object)
{
    const char* id = GetId();
    if (strlen(id) == 0)
    {
        id = object->GetValue<Noesis::String>(IdProperty).Str();
    }
    return FText::FromStringTable(UTF8_TO_TCHAR(id), UTF8_TO_TCHAR(GetKey()), EStringTableLoadingPolicy::FindOrLoad).ToString();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
Noesis::Ptr<Noesis::BaseComponent> LocTableExtension::ProvideValue(const Noesis::ValueTargetProvider* provider)
{
    return *new LocTableExpression(this,
        Noesis::DynamicCast<Noesis::DependencyObject*>(provider->GetTargetObject()),
        provider->GetTargetProperty());
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_IMPLEMENT_REFLECTION(LocTableExtension, "NoesisGUIExtensions.LocTable")
{
    NsMeta<Noesis::ContentPropertyMetaData>("Source");

    NsProp("Id", &LocTableExtension::GetId, &LocTableExtension::SetId);
    NsProp("Key", &LocTableExtension::GetKey, &LocTableExtension::SetKey);
    NsProp("Source", &LocTableExtension::GetSource, &LocTableExtension::SetSource);

    Noesis::UIElementData* data = NsMeta<Noesis::UIElementData>(Noesis::TypeOf<SelfClass>());
    data->RegisterProperty<Noesis::String>(IdProperty, "Id",
        Noesis::FrameworkPropertyMetadata::Create(Noesis::String(), Noesis::FrameworkPropertyMetadataOptions_Inherits));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
const Noesis::DependencyProperty* LocTableExtension::IdProperty;
