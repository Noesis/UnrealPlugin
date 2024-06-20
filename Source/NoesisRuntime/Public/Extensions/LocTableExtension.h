////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Core includes
#include "CoreMinimal.h"

// Noesis includes
#include "NoesisSDK.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
class NOESISRUNTIME_API LocTableExtension : public Noesis::MarkupExtension
{
public:
    const char* GetId() const;
    void SetId(const char* value);
    const char* GetKey() const;
    void SetKey(const char* value);
    const char* GetSource() const;
    void SetSource(const char* value);
    Noesis::IValueConverter* GetConverter() const;
    void SetConverter(Noesis::IValueConverter* value);
    BaseComponent* GetConverterParameter() const;
    void SetConverterParameter(BaseComponent* value);

    /// From MarkupExtension
    //@{
    Noesis::Ptr<Noesis::BaseComponent> ProvideValue(const Noesis::ValueTargetProvider* provider) override;
    //@}

public:

    FString GetDisplayString(Noesis::DependencyObject* object);

public:

    static const Noesis::DependencyProperty* IdProperty;

private:
    Noesis::String mId;
    Noesis::String mKey;
    Noesis::String mSource;
    Noesis::Ptr<Noesis::IValueConverter> mConverter;
    Noesis::Ptr<BaseComponent> mConverterParameter;

    NS_DECLARE_REFLECTION(LocTableExtension, Noesis::MarkupExtension)
};
