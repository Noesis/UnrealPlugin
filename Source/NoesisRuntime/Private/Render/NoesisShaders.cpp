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

IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("main"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosColorVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("main"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosTex0VS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("main"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosColorCoverageVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("main"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosTex0CoverageVS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("main"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosColorTex1VS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("main"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPosTex0Tex1VS, TEXT("/Plugin/NoesisGUI/Private/NoesisVS.usf"), TEXT("main"), SF_Vertex)

IMPLEMENT_SHADER_TYPE(template<>, FNoesisRgbaPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("main"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisMaskPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("main"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathSolidPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("main"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("main"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathRadialPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("main"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("main"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAaSolidPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("main"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAaLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("main"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAaRadialPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("main"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAaPatternPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("main"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisImagePaintOpacitySolidPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("main"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisImagePaintOpacityLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("main"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisImagePaintOpacityRadialPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("main"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisImagePaintOpacityPatternPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("main"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisTextSolidPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("main"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisTextLinearPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("main"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisTextRadialPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("main"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisTextPatternPS, TEXT("/Plugin/NoesisGUI/Private/NoesisPS.usf"), TEXT("main"), SF_Pixel);
