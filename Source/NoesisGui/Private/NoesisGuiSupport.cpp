////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisGuiSupport.h"

Noesis::Ptr<Noesis::Render::Texture> NoesisGuiCreateTexture(UTexture2D* Texture)
{
	return FNoesisGuiRenderDevice::CreateTexture(Texture);
}

void CollectElements(Noesis::FrameworkElement* Element, TArray<Noesis::FrameworkElement*>& Elements)
{
	const NsChar* ElementName = Element->GetName();
	Elements.Add(Element);
	NsSize ElementCount = Noesis::LogicalTreeHelper::GetChildrenCount(Element);
	for (NsSize ElementIndex = 0; ElementIndex != ElementCount; ++ElementIndex)
	{
		Noesis::FrameworkElement* ChildElement = NsDynamicCast<Noesis::FrameworkElement*>(Noesis::LogicalTreeHelper::GetChild(Element, ElementIndex));
		if (ChildElement)
		{
			CollectElements(ChildElement, Elements);
		}
	}
}
