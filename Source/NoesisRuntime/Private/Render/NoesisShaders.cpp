////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisShaders.h"

TGlobalResource<FNoesisPosVertexDeclaration> GNoesisPosVertexDeclaration;
TGlobalResource<FNoesisPosColorVertexDeclaration> GNoesisPosColorVertexDeclaration;
TGlobalResource<FNoesisPosTex0VertexDeclaration> GNoesisPosTex0VertexDeclaration;
TGlobalResource<FNoesisPosColorCoverageVertexDeclaration> GNoesisPosColorCoverageVertexDeclaration;
TGlobalResource<FNoesisPosTex0CoverageVertexDeclaration> GNoesisPosTex0CoverageVertexDeclaration;
TGlobalResource<FNoesisPosColorTex1VertexDeclaration> GNoesisPosColorTex1VertexDeclaration;
TGlobalResource<FNoesisPosTex0Tex1VertexDeclaration> GNoesisPosTex0Tex1VertexDeclaration;
TGlobalResource<FNoesisPosColorTex1Tex2VertexDeclaration> GNoesisPosColorTex1Tex2VertexDeclaration;
TGlobalResource<FNoesisPosTex0Tex1Tex2VertexDeclaration> GNoesisPosTex0Tex1Tex2VertexDeclaration;

IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosColorVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosTex0VS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosColorCoverageVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosTex0CoverageVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosColorTex1VS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosTex0Tex1VS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex)
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosColorTex1SDFVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosTex0Tex1SDFVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex)
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosColorTex1Tex2VS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosTex0Tex1Tex2VS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("NoesisVS"), SF_Vertex)

IMPLEMENT_SHADER_TYPE(template<>, FNoesisRgbaPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisMaskPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathSolidPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathRadialPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAaSolidPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAaLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAaRadialPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAaPatternPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFSolidPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFRadialPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFPatternPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDSolidPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDRadialPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisSDFLCDPatternPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisImageOpacitySolidPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisImageOpacityLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisImageOpacityRadialPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisImageOpacityPatternPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisImageShadow35VPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisImageShadow63VPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisImageShadow127VPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisImageShadow35HSolidPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisImageShadow35HLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisImageShadow35HRadialPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisImageShadow35HPatternPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisImageShadow63HSolidPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisImageShadow63HLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisImageShadow63HRadialPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisImageShadow63HPatternPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisImageShadow127HSolidPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisImageShadow127HLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisImageShadow127HRadialPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisImageShadow127HPatternPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisImageBlur35VPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisImageBlur63VPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisImageBlur127VPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisImageBlur35HSolidPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisImageBlur35HLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisImageBlur35HRadialPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisImageBlur35HPatternPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisImageBlur63HSolidPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisImageBlur63HLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisImageBlur63HRadialPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisImageBlur63HPatternPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisImageBlur127HSolidPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisImageBlur127HLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisImageBlur127HRadialPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisImageBlur127HPatternPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("NoesisPS"), SF_Pixel);
