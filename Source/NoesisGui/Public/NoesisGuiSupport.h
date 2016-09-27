////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

inline FString NsStringToFString(const NsChar* String)
{
	return FString(StringCast<TCHAR>(String).Get());
}

inline FName NsStringToFName(const NsChar* String)
{
	return FName(String);
}

Noesis::Ptr<Noesis::Render::Texture> NoesisGuiCreateTexture(UTexture2D* Texture);

NOESISGUI_API void CollectElements(Noesis::FrameworkElement* Element, TArray<Noesis::FrameworkElement*>& Elements);
