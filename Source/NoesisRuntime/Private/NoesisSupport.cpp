////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisSupport.h"

// NoesisRuntime includes
#include "Render/NoesisRenderDevice.h"

Noesis::Ptr<Noesis::Texture> NoesisCreateTexture(UTexture* Texture)
{
	return FNoesisRenderDevice::CreateTexture(Texture);
}

void CollectElements(Noesis::FrameworkElement* Element, TArray<Noesis::FrameworkElement*>& Elements)
{
	const char* ElementName = Element->GetName();
	Elements.Add(Element);
	uint32 ElementCount = Noesis::LogicalTreeHelper::GetChildrenCount(Element);
	for (uint32 ElementIndex = 0; ElementIndex != ElementCount; ++ElementIndex)
	{
		Noesis::FrameworkElement* ChildElement = NsDynamicCast<Noesis::FrameworkElement*>(Noesis::LogicalTreeHelper::GetChild(Element, ElementIndex));
		if (ChildElement)
		{
			CollectElements(ChildElement, Elements);
		}
	}
}
