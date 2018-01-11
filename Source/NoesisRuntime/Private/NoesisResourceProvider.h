////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Core includes
#include "CoreMinimal.h"

// Noesis includes
#include "NoesisSDK.h"

class FNoesisResourceProvider : public Noesis::XamlProvider, public Noesis::TextureProvider, public Noesis::CachedFontProvider
{
public:

	class UNoesisXaml* GetXaml(FString XamlPath);
	class UTexture2D* GetTexture(FString TexturePath);

	// XamlProvider interface
	virtual Noesis::Ptr<Noesis::Stream> LoadXaml(const char* Filename) override;
	// End of XamlProvider interface

	// TextureProvider interface
	virtual Noesis::TextureInfo GetTextureInfo(const char* Path) override;
	virtual Noesis::Ptr<Noesis::Texture> LoadTexture(const char* Path, Noesis::RenderDevice* RenderDevice) override;
	// End of TextureProvider interface

	// CachedFontProvider interface
	virtual void ScanFolder(const char* Folder) override;
	virtual Noesis::Ptr<Noesis::Stream> OpenFont(const char* Folder, const char* Filename) const override;
	// End of CachedFontProvider interface
};
