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
class NOESISRUNTIME_API LocTextExtension : public Noesis::MarkupExtension
{
public:
    const char* GetNamespace() const;
    void SetNamespace(const char* value);
    const char* GetKey() const;
    void SetKey(const char* value);
    const char* GetSource() const;
    void SetSource(const char* value);

    /// From MarkupExtension
    //@{
    Noesis::Ptr<Noesis::BaseComponent> ProvideValue(const Noesis::ValueTargetProvider* provider) override;
    //@}

public:

    FString GetDisplayString(Noesis::DependencyObject* object);

public:

    static const Noesis::DependencyProperty* NamespaceProperty;

private:
    Noesis::String mNamespace;
    Noesis::String mKey;
    Noesis::String mSource;

    NS_DECLARE_REFLECTION(LocTextExtension, Noesis::MarkupExtension)
};
