////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

class NOESISGUI_API FNoesisGuiResourceManager
{
public:
	void SetBaseXaml(class UNoesisGuiXaml* InNoesisGuiXaml)
	{
		NoesisGuiXaml = InNoesisGuiXaml;
	}

	Noesis::Ptr<Noesis::Core::Stream> LoadXaml(const NsChar* Filename);

	class UNoesisGuiXaml* NoesisGuiXaml;
};
