////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisStyle.h"

// Projects includes
#include "Interfaces/IPluginManager.h"

// Slate includes
#include "SlateOptMacros.h"

// SlateCore includes
#include "Styling/SlateStyle.h"
#include "Styling/SlateStyleRegistry.h"

#define IMAGE_PLUGIN_BRUSH( RelativePath, ... ) FSlateImageBrush( FNoesisStyle::InResources( RelativePath, ".png" ), __VA_ARGS__ )

FString FNoesisStyle::InResources(const FString& RelativePath, const ANSICHAR* Extension)
{
	static FString ResourcesDir = IPluginManager::Get().FindPlugin(TEXT("NoesisGUI"))->GetBaseDir() / TEXT("Resources");
	return (ResourcesDir / RelativePath) + Extension;
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
	const FVector2D Icon40x40(40.0f, 40.0f);
	const FVector2D Icon64x64(64.0f, 64.0f);

	StyleSet = MakeShareable(new FSlateStyleSet(GetStyleSetName()));
	StyleSet->SetContentRoot(FPaths::EngineContentDir() / TEXT("Editor/Slate"));
	StyleSet->SetCoreContentRoot(FPaths::EngineContentDir() / TEXT("Slate"));

	StyleSet->Set("ClassIcon.NoesisBlueprint", new IMAGE_PLUGIN_BRUSH("Blueprint_16x", Icon16x16));
	StyleSet->Set("ClassThumbnail.NoesisBlueprint", new IMAGE_PLUGIN_BRUSH("Blueprint_64x", Icon64x64));
	StyleSet->Set("ClassIcon.NoesisInstance", new IMAGE_PLUGIN_BRUSH("Blueprint_16x", Icon16x16));
	StyleSet->Set("ClassThumbnail.NoesisInstance", new IMAGE_PLUGIN_BRUSH("Blueprint_64x", Icon64x64));
	StyleSet->Set("ClassIcon.NoesisXaml", new IMAGE_PLUGIN_BRUSH("Xaml_16x", Icon16x16));
	StyleSet->Set("ClassThumbnail.NoesisXaml", new IMAGE_PLUGIN_BRUSH("Xaml_64x", Icon64x64));
	StyleSet->Set("NoesisBlueprintEditor.RestartPreview", new IMAGE_PLUGIN_BRUSH("RestartPreview_40x", Icon40x40));
	StyleSet->Set("NoesisEditor.About", new IMAGE_PLUGIN_BRUSH("About", FVector2D(300.0f, 60.0f)));

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
