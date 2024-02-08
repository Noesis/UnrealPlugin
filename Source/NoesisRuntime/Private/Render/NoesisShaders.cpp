////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisShaders.h"

IMPLEMENT_GLOBAL_SHADER_PARAMETER_STRUCT(FNoesisVSConstants, "NoesisVSConstants");
IMPLEMENT_GLOBAL_SHADER_PARAMETER_STRUCT(FNoesisVSConstantsRightEye, "NoesisVSConstantsRightEye");
IMPLEMENT_GLOBAL_SHADER_PARAMETER_STRUCT(FNoesisTextureSize, "NoesisTextureSize");
IMPLEMENT_GLOBAL_SHADER_PARAMETER_STRUCT(FNoesisPSRgbaConstants, "NoesisPSRgbaConstants");
IMPLEMENT_GLOBAL_SHADER_PARAMETER_STRUCT(FNoesisPSOpacityConstants, "NoesisPSOpacityConstants");
IMPLEMENT_GLOBAL_SHADER_PARAMETER_STRUCT(FNoesisPSRadialGradConstants, "NoesisPSRadialGradConstants");
IMPLEMENT_GLOBAL_SHADER_PARAMETER_STRUCT(FNoesisBlurConstants, "NoesisBlurConstants");
IMPLEMENT_GLOBAL_SHADER_PARAMETER_STRUCT(FNoesisShadowConstants, "NoesisShadowConstants");

TGlobalResource<FNoesisPosVertexDeclaration> GNoesisPosVertexDeclaration;
TGlobalResource<FNoesisPosColorVertexDeclaration> GNoesisPosColorVertexDeclaration;
TGlobalResource<FNoesisPosTex0VertexDeclaration> GNoesisPosTex0VertexDeclaration;
TGlobalResource<FNoesisPosTex0RectVertexDeclaration> GNoesisPosTex0RectVertexDeclaration;
TGlobalResource<FNoesisPosTex0RectTileVertexDeclaration> GNoesisPosTex0RectTileVertexDeclaration;
TGlobalResource<FNoesisPosColorCoverageVertexDeclaration> GNoesisPosColorCoverageVertexDeclaration;
TGlobalResource<FNoesisPosTex0CoverageVertexDeclaration> GNoesisPosTex0CoverageVertexDeclaration;
TGlobalResource<FNoesisPosTex0CoverageRectVertexDeclaration> GNoesisPosTex0CoverageRectVertexDeclaration;
TGlobalResource<FNoesisPosTex0CoverageRectTileVertexDeclaration> GNoesisPosTex0CoverageRectTileVertexDeclaration;
TGlobalResource<FNoesisPosColorTex1VertexDeclaration> GNoesisPosColorTex1VertexDeclaration;
TGlobalResource<FNoesisPosTex0Tex1VertexDeclaration> GNoesisPosTex0Tex1VertexDeclaration;
TGlobalResource<FNoesisPosTex0Tex1RectVertexDeclaration> GNoesisPosTex0Tex1RectVertexDeclaration;
TGlobalResource<FNoesisPosTex0Tex1RectTileVertexDeclaration> GNoesisPosTex0Tex1RectTileVertexDeclaration;
TGlobalResource<FNoesisPosColorTex0Tex1VertexDeclaration> GNoesisPosColorTex0Tex1VertexDeclaration;
TGlobalResource<FNoesisPosColorTex1RectVertexDeclaration> GNoesisPosColorTex1RectVertexDeclaration;
TGlobalResource<FNoesisPosColorTex0RectImagePosVertexDeclaration> GNoesisPosColorTex0RectImagePosVertexDeclaration;

IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosColorVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosTex0VS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosTex0RectVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosTex0RectTileVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosColorCoverageVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosTex0CoverageVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosTex0CoverageRectVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosTex0CoverageRectTileVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosColorTex1SDFVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosTex0Tex1SDFVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosTex0Tex1RectSDFVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosTex0Tex1RectTileSDFVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosColorTex1VS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosTex0Tex1VS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosTex0Tex1RectVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosTex0Tex1RectTileVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosColorTex0Tex1VS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosTex0Tex1DownsampleVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosColorTex1RectVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosColorTex0RectImagePosVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosLinearColorVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosLinearColorCoverageVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosLinearColorTex1SDFVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosLinearColorTex1VS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosLinearColorTex0Tex1VS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosLinearColorTex1RectVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosLinearColorTex0RectImagePosVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosStereoVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosColorStereoVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosTex0StereoVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosTex0RectStereoVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosTex0RectTileStereoVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosColorCoverageStereoVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosTex0CoverageStereoVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosTex0CoverageRectStereoVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosTex0CoverageRectTileStereoVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosColorTex1SDFStereoVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosTex0Tex1SDFStereoVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosTex0Tex1RectSDFStereoVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosTex0Tex1RectTileSDFStereoVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosColorTex1StereoVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosTex0Tex1StereoVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosTex0Tex1RectStereoVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosTex0Tex1RectTileStereoVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosColorTex0Tex1StereoVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosTex0Tex1DownsampleStereoVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosColorTex1RectStereoVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosColorTex0RectImagePosStereoVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosLinearColorStereoVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosLinearColorCoverageStereoVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosLinearColorTex1SDFStereoVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosLinearColorTex1StereoVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosLinearColorTex0Tex1StereoVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosLinearColorTex1RectStereoVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosLinearColorTex0RectImagePosStereoVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisRgbaPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisMaskPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisClearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathSolidPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathRadialPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternClampPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternRepeatPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternMirrorUPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternMirrorVPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternMirrorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAASolidPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAALinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAARadialPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternClampPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternRepeatPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternMirrorUPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternMirrorVPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternMirrorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFSolidPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFRadialPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternClampPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternRepeatPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternMirrorUPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternMirrorVPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternMirrorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDSolidPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDRadialPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternClampPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternRepeatPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternMirrorUPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternMirrorVPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternMirrorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacitySolidPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityRadialPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternClampPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternRepeatPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternMirrorUPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternMirrorVPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternMirrorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisUpsamplePS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisDownsamplePS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisShadowPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisBlurPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

// Read the comment next to PATTERN_SRGB in FNoesisPS::ModifyCompilationEnvironment
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternSRGBPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternClampSRGBPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternRepeatSRGBPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternMirrorUSRGBPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternMirrorVSRGBPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternMirrorSRGBPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternSRGBPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternClampSRGBPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternRepeatSRGBPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternMirrorUSRGBPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternMirrorVSRGBPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternMirrorSRGBPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternSRGBPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternClampSRGBPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternRepeatSRGBPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternMirrorUSRGBPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternMirrorVSRGBPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternMirrorSRGBPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternSRGBPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternClampSRGBPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternRepeatSRGBPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternMirrorUSRGBPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternMirrorVSRGBPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternMirrorSRGBPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternSRGBPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternClampSRGBPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternRepeatSRGBPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternMirrorUSRGBPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternMirrorVSRGBPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternMirrorSRGBPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

// Read the comment next to PATTERN_LINEAR in FNoesisPS::ModifyCompilationEnvironment
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternClampLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternRepeatLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternMirrorULinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternMirrorVLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternMirrorLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternClampLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternRepeatLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternMirrorULinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternMirrorVLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternMirrorLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternClampLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternRepeatLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternMirrorULinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternMirrorVLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternMirrorLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternClampLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternRepeatLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternMirrorULinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternMirrorVLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternMirrorLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternClampLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternRepeatLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternMirrorULinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternMirrorVLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternMirrorLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisRgbaGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisMaskGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisClearGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathSolidGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathLinearGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathRadialGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternClampGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternRepeatGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternMirrorUGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternMirrorVGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternMirrorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAASolidGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAALinearGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAARadialGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternClampGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternRepeatGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternMirrorUGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternMirrorVGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternMirrorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFSolidGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLinearGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFRadialGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternClampGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternRepeatGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternMirrorUGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternMirrorVGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternMirrorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDSolidGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDLinearGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDRadialGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternClampGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternRepeatGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternMirrorUGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternMirrorVGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternMirrorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacitySolidGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityLinearGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityRadialGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternClampGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternRepeatGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternMirrorUGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternMirrorVGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternMirrorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisUpsampleGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisDownsampleGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisShadowGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisBlurGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

// Read the comment next to PATTERN_SRGB in FNoesisPS::ModifyCompilationEnvironment
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternSRGBGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternClampSRGBGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternRepeatSRGBGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternMirrorUSRGBGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternMirrorVSRGBGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternMirrorSRGBGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternSRGBGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternClampSRGBGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternRepeatSRGBGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternMirrorUSRGBGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternMirrorVSRGBGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternMirrorSRGBGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternSRGBGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternClampSRGBGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternRepeatSRGBGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternMirrorUSRGBGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternMirrorVSRGBGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternMirrorSRGBGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternSRGBGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternClampSRGBGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternRepeatSRGBGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternMirrorUSRGBGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternMirrorVSRGBGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternMirrorSRGBGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternSRGBGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternClampSRGBGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternRepeatSRGBGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternMirrorUSRGBGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternMirrorVSRGBGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternMirrorSRGBGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

// Read the comment next to PATTERN_LINEAR in FNoesisPS::ModifyCompilationEnvironment
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternLinearGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternClampLinearGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternRepeatLinearGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternMirrorULinearGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternMirrorVLinearGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternMirrorLinearGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternLinearGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternClampLinearGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternRepeatLinearGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternMirrorULinearGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternMirrorVLinearGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternMirrorLinearGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternLinearGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternClampLinearGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternRepeatLinearGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternMirrorULinearGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternMirrorVLinearGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternMirrorLinearGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternLinearGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternClampLinearGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternRepeatLinearGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternMirrorULinearGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternMirrorVLinearGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternMirrorLinearGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternLinearGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternClampLinearGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternRepeatLinearGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternMirrorULinearGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternMirrorVLinearGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternMirrorLinearGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisRgbaLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisMaskLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisClearLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathSolidLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathLinearLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathRadialLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternClampLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternRepeatLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternMirrorULinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternMirrorVLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternMirrorLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAASolidLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAALinearLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAARadialLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternClampLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternRepeatLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternMirrorULinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternMirrorVLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternMirrorLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFSolidLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLinearLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFRadialLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternClampLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternRepeatLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternMirrorULinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternMirrorVLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternMirrorLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDSolidLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDLinearLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDRadialLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternClampLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternRepeatLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternMirrorULinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternMirrorVLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternMirrorLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacitySolidLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityLinearLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityRadialLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternClampLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternRepeatLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternMirrorULinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternMirrorVLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternMirrorLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisUpsampleLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisDownsampleLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisShadowLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisBlurLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

// Read the comment next to PATTERN_SRGB in FNoesisPS::ModifyCompilationEnvironment
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternSRGBLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternClampSRGBLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternRepeatSRGBLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternMirrorUSRGBLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternMirrorVSRGBLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternMirrorSRGBLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternSRGBLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternClampSRGBLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternRepeatSRGBLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternMirrorUSRGBLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternMirrorVSRGBLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternMirrorSRGBLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternSRGBLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternClampSRGBLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternRepeatSRGBLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternMirrorUSRGBLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternMirrorVSRGBLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternMirrorSRGBLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternSRGBLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternClampSRGBLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternRepeatSRGBLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternMirrorUSRGBLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternMirrorVSRGBLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternMirrorSRGBLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternSRGBLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternClampSRGBLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternRepeatSRGBLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternMirrorUSRGBLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternMirrorVSRGBLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternMirrorSRGBLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

// Read the comment next to PATTERN_LINEAR in FNoesisPS::ModifyCompilationEnvironment
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternLinearLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternClampLinearLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternRepeatLinearLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternMirrorULinearLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternMirrorVLinearLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternMirrorLinearLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternLinearLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternClampLinearLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternRepeatLinearLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternMirrorULinearLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternMirrorVLinearLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAAPatternMirrorLinearLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternLinearLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternClampLinearLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternRepeatLinearLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternMirrorULinearLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternMirrorVLinearLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternMirrorLinearLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternLinearLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternClampLinearLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternRepeatLinearLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternMirrorULinearLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternMirrorVLinearLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternMirrorLinearLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternLinearLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternClampLinearLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternRepeatLinearLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternMirrorULinearLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternMirrorVLinearLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisOpacityPatternMirrorLinearLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathMaterialPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathMaterialClampPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathMaterialRepeatPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathMaterialMirrorUPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathMaterialMirrorVPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathMaterialMirrorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathAAMaterialPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathAAMaterialClampPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathAAMaterialRepeatPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathAAMaterialMirrorUPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathAAMaterialMirrorVPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathAAMaterialMirrorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFMaterialPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFMaterialClampPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFMaterialRepeatPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFMaterialMirrorUPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFMaterialMirrorVPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFMaterialMirrorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFLCDMaterialPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFLCDMaterialClampPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFLCDMaterialRepeatPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFLCDMaterialMirrorUPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFLCDMaterialMirrorVPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFLCDMaterialMirrorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisOpacityMaterialPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisOpacityMaterialClampPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisOpacityMaterialRepeatPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisOpacityMaterialMirrorUPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisOpacityMaterialMirrorVPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisOpacityMaterialMirrorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathMaterialLinearColorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathMaterialClampLinearColorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathMaterialRepeatLinearColorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathMaterialMirrorULinearColorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathMaterialMirrorVLinearColorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathMaterialMirrorLinearColorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathAAMaterialLinearColorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathAAMaterialClampLinearColorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathAAMaterialRepeatLinearColorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathAAMaterialMirrorULinearColorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathAAMaterialMirrorVLinearColorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathAAMaterialMirrorLinearColorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFMaterialLinearColorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFMaterialClampLinearColorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFMaterialRepeatLinearColorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFMaterialMirrorULinearColorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFMaterialMirrorVLinearColorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFMaterialMirrorLinearColorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFLCDMaterialLinearColorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFLCDMaterialClampLinearColorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFLCDMaterialRepeatLinearColorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFLCDMaterialMirrorULinearColorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFLCDMaterialMirrorVLinearColorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFLCDMaterialMirrorLinearColorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisOpacityMaterialLinearColorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisOpacityMaterialClampLinearColorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisOpacityMaterialRepeatLinearColorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisOpacityMaterialMirrorULinearColorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisOpacityMaterialMirrorVLinearColorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisOpacityMaterialMirrorLinearColorPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathMaterialGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathMaterialClampGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathMaterialRepeatGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathMaterialMirrorUGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathMaterialMirrorVGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathMaterialMirrorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathAAMaterialGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathAAMaterialClampGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathAAMaterialRepeatGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathAAMaterialMirrorUGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathAAMaterialMirrorVGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathAAMaterialMirrorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFMaterialGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFMaterialClampGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFMaterialRepeatGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFMaterialMirrorUGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFMaterialMirrorVGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFMaterialMirrorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFLCDMaterialGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFLCDMaterialClampGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFLCDMaterialRepeatGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFLCDMaterialMirrorUGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFLCDMaterialMirrorVGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFLCDMaterialMirrorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisOpacityMaterialGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisOpacityMaterialClampGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisOpacityMaterialRepeatGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisOpacityMaterialMirrorUGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisOpacityMaterialMirrorVGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisOpacityMaterialMirrorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathMaterialLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathMaterialClampLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathMaterialRepeatLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathMaterialMirrorULinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathMaterialMirrorVLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathMaterialMirrorLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathAAMaterialLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathAAMaterialClampLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathAAMaterialRepeatLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathAAMaterialMirrorULinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathAAMaterialMirrorVLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisPathAAMaterialMirrorLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFMaterialLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFMaterialClampLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFMaterialRepeatLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFMaterialMirrorULinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFMaterialMirrorVLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFMaterialMirrorLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFLCDMaterialLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFLCDMaterialClampLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFLCDMaterialRepeatLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFLCDMaterialMirrorULinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFLCDMaterialMirrorVLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisSDFLCDMaterialMirrorLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisOpacityMaterialLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisOpacityMaterialClampLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisOpacityMaterialRepeatLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisOpacityMaterialMirrorULinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisOpacityMaterialMirrorVLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(template<>, FNoesisOpacityMaterialMirrorLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisMaterialPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_MATERIAL_SHADER_TYPE(, FNoesisCustomEffectPS, TEXT("/Plugin/NoesisGUI/Private/NoesisCustomEffectPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(, FNoesisCustomEffectGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisCustomEffectPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_MATERIAL_SHADER_TYPE(, FNoesisCustomEffectLinearColorGammaCorrectionPS, TEXT("/Plugin/NoesisGUI/Private/NoesisCustomEffectPS.usf"), TEXT("NoesisPS"), SF_Pixel);
