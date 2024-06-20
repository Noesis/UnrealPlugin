////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Noesis includes
#include "NoesisSDK.h"

class FNoesisLangServerXamlProvider: public Noesis::XamlProvider
{
public:
	// XamlProvider interface
	virtual Noesis::Ptr<Noesis::Stream> LoadXaml(const Noesis::Uri& Uri) override;
	// End of XamlProvider interface
};

class FNoesisLangServerTextureProvider: public Noesis::TextureProvider
{
public:
	static void ClearShrinkTextures();

private:
	// TextureProvider interface
	virtual Noesis::TextureInfo GetTextureInfo(const Noesis::Uri& Uri) override;
	virtual Noesis::Ptr<Noesis::Texture> LoadTexture(const Noesis::Uri& Uri, Noesis::RenderDevice* RenderDevice) override;
	// End of TextureProvider interface
};

class FNoesisLangServerFontProvider: public Noesis::CachedFontProvider
{
private:
	/// From CachedFontProvider
	//@{
	void ScanFolder(const Noesis::Uri& folder) override;
	Noesis::Ptr<Noesis::Stream> OpenFont(const Noesis::Uri& folder, const char* filename) const override;
	//@}
};
