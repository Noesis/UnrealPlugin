////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisSettings.h"

UNoesisSettings::UNoesisSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	OffscreenTextureSampleCount = ENoesisOffscreenSampleCount::One;
	GlyphTextureSize = ENoesisGlyphCacheDimensions::x1024;
	ApplicationResources = FSoftObjectPath("/NoesisGUI/Theme/NoesisTheme_DarkBlue.NoesisTheme_DarkBlue");
	DefaultFonts.Add(FSoftObjectPath("/NoesisGUI/Theme/Fonts/PT_Root_UI_Font.PT_Root_UI_Font"));
	DefaultFontSize = 15.f;
	DefaultFontWeight = ENoesisFontWeight::Normal;
	DefaultFontStretch = ENoesisFontStretch::Normal;
	DefaultFontStyle = ENoesisFontStyle::Normal;
}
