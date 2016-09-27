////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisGuiResourceManager.h"

// NoesisGui includes
#include "NoesisGuiBlueprintGeneratedClass.h"

Noesis::Ptr<Noesis::Core::Stream> FNoesisGuiResourceManager::LoadXaml(const NsChar* Filename)
{
	return Noesis::Ptr<Noesis::Core::Stream>(*new Noesis::Core::MemoryStream(NoesisGuiXaml->XamlText.GetData(), (NsSize)NoesisGuiXaml->XamlText.Num()));
}
