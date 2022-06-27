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
	void OnXamlChanged(class UNoesisXaml* Xaml);

	class UNoesisXaml* GetXaml(FString XamlProviderPath) const;

	// XamlProvider interface
	virtual Noesis::Ptr<Noesis::Stream> LoadXaml(const Noesis::Uri& Uri) override;
	// End of XamlProvider interface

#if WITH_EDITOR
	mutable TMap<class UNoesisXaml*, TArray<FString>> NameMap;
#endif
};

class FNoesisTextureProvider : public Noesis::TextureProvider
{
public:
	void OnTextureChanged(class UTexture2D* Texture);

private:
	// TextureProvider interface
	virtual Noesis::TextureInfo GetTextureInfo(const Noesis::Uri& Uri) override;
	virtual Noesis::Ptr<Noesis::Texture> LoadTexture(const Noesis::Uri& Uri, Noesis::RenderDevice* RenderDevice) override;
	// End of TextureProvider interface

#if WITH_EDITOR
	mutable TMap<class UTexture2D*, FString> NameMap;
#endif
};

class FNoesisFontProvider : public Noesis::CachedFontProvider
{
public:
	void RegisterFont(const class UFontFace* Font);

private:
	// FontProvider interface
	virtual Noesis::FontSource MatchFont(const Noesis::Uri& BaseUri, const char* FamilyName, Noesis::FontWeight& Weight,
		Noesis::FontStretch& Stretch, Noesis::FontStyle& Style) override;
	virtual bool FamilyExists(const Noesis::Uri& BaseUri, const char* FamilyName) override;
	// End of FontProvider interface

	// CachedFontProvider interface
	virtual void ScanFolder(const Noesis::Uri& Folder) override;
	virtual Noesis::Ptr<Noesis::Stream> OpenFont(const Noesis::Uri& Folder, const char* Filename) const override;
	// End of CachedFontProvider interface
};
