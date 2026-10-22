////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Core includes
#include "CoreMinimal.h"

// Noesis includes
#include "NoesisSDK.h"

class FNoesisStudioXamlProvider: public Noesis::XamlProvider
{
public:
	FNoesisStudioXamlProvider(const char* rootPath = "");

	// XamlProvider interface
	virtual Noesis::Ptr<Noesis::Stream> LoadXaml(const Noesis::Uri& Uri) override;
	// End of XamlProvider interface

private:
	Noesis::String mRootPath;
};

struct NoesisTextureData;

class FNoesisStudioTextureProvider: public Noesis::TextureProvider
{
public:
	FNoesisStudioTextureProvider(const char* rootPath = "");
	static void TextureChanged(class UTexture2D* Texture);
	void OnTextureChanged(class UTexture2D* Texture);

private:
	~FNoesisStudioTextureProvider();
	// TextureProvider interface
	virtual Noesis::TextureInfo GetTextureInfo(const Noesis::Uri& Uri) override;
	virtual Noesis::Ptr<Noesis::Texture> LoadTexture(const Noesis::Uri& Uri, Noesis::RenderDevice* RenderDevice) override;
	// End of TextureProvider interface

private:
	Noesis::String mRootPath;
	Noesis::Vector<NoesisTextureData> mCachedTextures;
	mutable TMap<class UTexture2D*, FString> NameMap;
};

class FNoesisStudioFontProvider: public Noesis::CachedFontProvider
{
public:
	FNoesisStudioFontProvider(const char* rootPath = "");
private:
	/// From CachedFontProvider
	//@{
	void ScanFolder(const Noesis::Uri& folder) override;
	Noesis::Ptr<Noesis::Stream> OpenFont(const Noesis::Uri& Folder, const char* Filename) const override;
	//@}

private:
	Noesis::String mRootPath;
};
