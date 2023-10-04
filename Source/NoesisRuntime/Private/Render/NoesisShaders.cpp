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

IMPLEMENT_MATERIAL_SHADER_TYPE(, FNoesisCustomEffectPS, TEXT("/Plugin/NoesisGUI/Private/NoesisCustomEffectPS.usf"), TEXT("NoesisPS"), SF_Pixel);
