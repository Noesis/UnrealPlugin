////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Core includes
#include "CoreMinimal.h"

// Noesis includes
#include "NoesisSDK.h"

class FNoesisXamlProvider : public Noesis::XamlProvider
{
public:

	class UNoesisXaml* GetXaml(FString XamlProviderPath) const;

	// XamlProvider interface
	virtual Noesis::Ptr<Noesis::Stream> LoadXaml(const char* Filename) override;
	// End of XamlProvider interface
};

class FNoesisTextureProvider : public Noesis::TextureProvider
{
	class UTexture2D* GetTexture(FString TextureProviderPath) const;

	// TextureProvider interface
	virtual Noesis::TextureInfo GetTextureInfo(const char* Path) override;
	virtual Noesis::Ptr<Noesis::Texture> LoadTexture(const char* Path, Noesis::RenderDevice* RenderDevice) override;
	// End of TextureProvider interface
};

class FNoesisFontProvider : public Noesis::CachedFontProvider
{
public:
	void RegisterFont(const class UFontFace* Font);

private:

	// FontProvider interface
	virtual Noesis::FontSource MatchFont(const char* BaseUri, const char* FamilyName, Noesis::FontWeight& Weight,
		Noesis::FontStretch& Stretch, Noesis::FontStyle& Style) override;
	virtual bool FamilyExists(const char* BaseUri, const char* FamilyName) override;
	// End of FontProvider interface

	// CachedFontProvider interface
	virtual void ScanFolder(const char* Folder) override;
	virtual Noesis::Ptr<Noesis::Stream> OpenFont(const char* Folder, const char* Filename) const override;
	// End of CachedFontProvider interface
};
