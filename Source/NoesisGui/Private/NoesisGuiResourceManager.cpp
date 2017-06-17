////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiResourceManager.h"

// NoesisGui includes
#include "NoesisBlueprintGeneratedClass.h"

Noesis::Ptr<Noesis::Core::Stream> FNoesisGuiResourceManager::LoadXaml(const NsChar* Filename)
{
	return Noesis::Ptr<Noesis::Core::Stream>(*new Noesis::Core::MemoryStream(NoesisXaml->XamlText.GetData(), (NsSize)NoesisXaml->XamlText.Num()));
}
