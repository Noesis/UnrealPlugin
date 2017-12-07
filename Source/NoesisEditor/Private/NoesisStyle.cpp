////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisStyle.h"

#define IMAGE_PLUGIN_BRUSH( RelativePath, ... ) FSlateImageBrush( FNoesisStyle::InContent( RelativePath, ".png" ), __VA_ARGS__ )

FString FNoesisStyle::InContent(const FString& RelativePath, const ANSICHAR* Extension)
{
	static FString ContentDir = IPluginManager::Get().FindPlugin(TEXT("NoesisGUI"))->GetContentDir();
	return (ContentDir / RelativePath) + Extension;
}

TSharedPtr< FSlateStyleSet > FNoesisStyle::StyleSet = nullptr;
TSharedPtr< class ISlateStyle > FNoesisStyle::Get() { return StyleSet; }

FName FNoesisStyle::GetStyleSetName()
{
	static FName NoesisStyleName(TEXT("NoesisStyle"));
	return NoesisStyleName;
}

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void FNoesisStyle::Initialize()
{
	// Const icon sizes
	const FVector2D Icon16x16(16.0f, 16.0f);
	const FVector2D Icon64x64(64.0f, 64.0f);

	StyleSet = MakeShareable(new FSlateStyleSet(GetStyleSetName()));
	StyleSet->SetContentRoot(FPaths::EngineContentDir() / TEXT("Editor/Slate"));
	StyleSet->SetCoreContentRoot(FPaths::EngineContentDir() / TEXT("Slate"));

	StyleSet->Set("ClassIcon.NoesisBlueprint", new IMAGE_PLUGIN_BRUSH("Icons/AssetIcons/NoesisBlueprint_16x", Icon16x16));
	StyleSet->Set("ClassThumbnail.NoesisBlueprint", new IMAGE_PLUGIN_BRUSH("Icons/AssetIcons/NoesisBlueprint_64x", Icon64x64));
	StyleSet->Set("ClassIcon.NoesisXaml", new IMAGE_PLUGIN_BRUSH("Icons/AssetIcons/NoesisXaml_16x", Icon16x16));
	StyleSet->Set("ClassThumbnail.NoesisXaml", new IMAGE_PLUGIN_BRUSH("Icons/AssetIcons/NoesisXaml_64x", Icon64x64));

	FSlateStyleRegistry::RegisterSlateStyle(*StyleSet.Get());
};

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

#undef IMAGE_PLUGIN_BRUSH

void FNoesisStyle::Shutdown()
{
	if (StyleSet.IsValid())
	{
		FSlateStyleRegistry::UnRegisterSlateStyle(*StyleSet.Get());
		ensure(StyleSet.IsUnique());
		StyleSet.Reset();
	}
}
