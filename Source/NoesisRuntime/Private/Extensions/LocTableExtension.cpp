////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Extensions/LocTableExtension.h"
#include "NsGui/ContentPropertyMetaData.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
static void DynamicConvert(const Noesis::Type* targetType, Noesis::Ptr<Noesis::BaseComponent>& sourceVal)
{
    NS_ASSERT(sourceVal != nullptr);
    const Noesis::Type* sourceType = sourceVal->GetClassType();
    if (!targetType->IsAssignableFrom(sourceType))
    {
        Noesis::BoxedValue* boxed = Noesis::DynamicCast<Noesis::BoxedValue*>(sourceVal.GetPtr());
        if (boxed != nullptr)
        {
            sourceType = boxed->GetValueType();
        }

        if (!targetType->IsAssignableFrom(sourceType))
        {
            Noesis::TypeConverter* converter = Noesis::TypeConverter::Get(targetType);
            if (converter != nullptr && converter->CanConvertFrom(sourceType))
            {
                converter->TryConvertFrom(sourceVal, sourceVal);
            }
            else
            {
                converter = Noesis::TypeConverter::Get(sourceType);
                if (converter != nullptr && converter->CanConvertTo(targetType))
                {
                    converter->TryConvertTo(sourceVal, targetType, sourceVal);
                }
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
class LocTableExpression : public Noesis::Expression
{
public:
    LocTableExpression(LocTableExtension* extension, Noesis::DependencyObject* targetObject, const Noesis::DependencyProperty* targetProperty,
        Noesis::Ptr<Noesis::IValueConverter> converter, Noesis::Ptr<BaseComponent> converterParameter)
        : mExtension(extension), mTargetObject(targetObject), mTargetProperty(targetProperty),
        mConverter(converter), mConverterParameter(converterParameter)
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

        Noesis::String(TCHAR_TO_UTF8(*DisplayString));

        Noesis::Ptr<Noesis::BaseComponent> sourceVal = Noesis::Boxing::Box(TCHAR_TO_UTF8(*DisplayString));

        Noesis::Ptr<BaseComponent> convertedVal;
        if (mConverter && mConverter->TryConvert(sourceVal, mTargetProperty->GetType(),
            mConverterParameter, convertedVal))
        {
            sourceVal = convertedVal;
        }

        DynamicConvert(mTargetProperty->GetType(), sourceVal);

        return sourceVal;
    }

    Noesis::Ptr<Noesis::Expression> Reapply(Noesis::DependencyObject* targetObject, const Noesis::DependencyProperty* targetProperty) const
    {
        if (mTargetObject == targetObject && mTargetProperty == targetProperty)
        {
            return Noesis::Ptr<Noesis::Expression>((LocTableExpression*)this);
        }
        else
        {
            return *new LocTableExpression(mExtension, targetObject, targetProperty, nullptr, nullptr);
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
    Noesis::Ptr<Noesis::IValueConverter> mConverter;
    Noesis::Ptr<BaseComponent> mConverterParameter;
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
Noesis::IValueConverter* LocTableExtension::GetConverter() const
{
    return mConverter;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void LocTableExtension::SetConverter(Noesis::IValueConverter* value)
{
    mConverter.Reset(value);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
Noesis::BaseComponent* LocTableExtension::GetConverterParameter() const
{
    return mConverterParameter;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void LocTableExtension::SetConverterParameter(BaseComponent* value)
{
    mConverterParameter.Reset(value);
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
        provider->GetTargetProperty(), mConverter, mConverterParameter);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_IMPLEMENT_REFLECTION(LocTableExtension, "NoesisGUIExtensions.LocTable")
{
    NsMeta<Noesis::ContentPropertyMetaData>("Source");

    NsProp("Id", &LocTableExtension::GetId, &LocTableExtension::SetId);
    NsProp("Key", &LocTableExtension::GetKey, &LocTableExtension::SetKey);
    NsProp("Source", &LocTableExtension::GetSource, &LocTableExtension::SetSource);
    NsProp("Converter", &LocTableExtension::GetConverter,
        &LocTableExtension::SetConverter);
    NsProp("ConverterParameter", &LocTableExtension::GetConverterParameter,
        &LocTableExtension::SetConverterParameter);

    Noesis::UIElementData* data = NsMeta<Noesis::UIElementData>(Noesis::TypeOf<SelfClass>());
    data->RegisterProperty<Noesis::String>(IdProperty, "Id",
        Noesis::FrameworkPropertyMetadata::Create(Noesis::String(), Noesis::FrameworkPropertyMetadataOptions_Inherits));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
const Noesis::DependencyProperty* LocTableExtension::IdProperty;
