////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisShaders.h"

TGlobalResource<FNoesisRgbaSolidVertexDeclaration> GNoesisRgbaSolidVertexDeclaration;
TGlobalResource<FNoesisMaskSolidVertexDeclaration> GNoesisMaskSolidVertexDeclaration;
TGlobalResource<FNoesisPathSolidVertexDeclaration> GNoesisPathSolidVertexDeclaration;
TGlobalResource<FNoesisPathAaSolidVertexDeclaration> GNoesisPathAaSolidVertexDeclaration;
TGlobalResource<FNoesisImagePaintOpacitySolidVertexDeclaration> GNoesisImagePaintOpacitySolidVertexDeclaration;
TGlobalResource<FNoesisTextSolidVertexDeclaration> GNoesisTextSolidVertexDeclaration;

TGlobalResource<FNoesisRgbaLinearVertexDeclaration> GNoesisRgbaLinearVertexDeclaration;
TGlobalResource<FNoesisMaskLinearVertexDeclaration> GNoesisMaskLinearVertexDeclaration;
TGlobalResource<FNoesisPathLinearVertexDeclaration> GNoesisPathLinearVertexDeclaration;
TGlobalResource<FNoesisPathAaLinearVertexDeclaration> GNoesisPathAaLinearVertexDeclaration;
TGlobalResource<FNoesisImagePaintOpacityLinearVertexDeclaration> GNoesisImagePaintOpacityLinearVertexDeclaration;
TGlobalResource<FNoesisTextLinearVertexDeclaration> GNoesisTextLinearVertexDeclaration;

TGlobalResource<FNoesisRgbaRadialVertexDeclaration> GNoesisRgbaRadialVertexDeclaration;
TGlobalResource<FNoesisMaskRadialVertexDeclaration> GNoesisMaskRadialVertexDeclaration;
TGlobalResource<FNoesisPathRadialVertexDeclaration> GNoesisPathRadialVertexDeclaration;
TGlobalResource<FNoesisPathAaRadialVertexDeclaration> GNoesisPathAaRadialVertexDeclaration;
TGlobalResource<FNoesisImagePaintOpacityRadialVertexDeclaration> GNoesisImagePaintOpacityRadialVertexDeclaration;
TGlobalResource<FNoesisTextRadialVertexDeclaration> GNoesisTextRadialVertexDeclaration;

TGlobalResource<FNoesisRgbaPatternVertexDeclaration> GNoesisRgbaPatternVertexDeclaration;
TGlobalResource<FNoesisMaskPatternVertexDeclaration> GNoesisMaskPatternVertexDeclaration;
TGlobalResource<FNoesisPathPatternVertexDeclaration> GNoesisPathPatternVertexDeclaration;
TGlobalResource<FNoesisPathAaPatternVertexDeclaration> GNoesisPathAaPatternVertexDeclaration;
TGlobalResource<FNoesisImagePaintOpacityPatternVertexDeclaration> GNoesisImagePaintOpacityPatternVertexDeclaration;
TGlobalResource<FNoesisTextPatternVertexDeclaration> GNoesisTextPatternVertexDeclaration;

TGlobalResource<FNoesisRgbaNoneVertexDeclaration> GNoesisRgbaNoneVertexDeclaration;
TGlobalResource<FNoesisMaskNoneVertexDeclaration> GNoesisMaskNoneVertexDeclaration;
TGlobalResource<FNoesisPathNoneVertexDeclaration> GNoesisPathNoneVertexDeclaration;
TGlobalResource<FNoesisPathAaNoneVertexDeclaration> GNoesisPathAaNoneVertexDeclaration;
TGlobalResource<FNoesisImagePaintOpacityNoneVertexDeclaration> GNoesisImagePaintOpacityNoneVertexDeclaration;
TGlobalResource<FNoesisTextNoneVertexDeclaration> GNoesisTextNoneVertexDeclaration;

IMPLEMENT_SHADER_TYPE(template<>, FNoesisRgbaSolidVS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisMaskSolidVS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathSolidVS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAaSolidVS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisImagePaintOpacitySolidVS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisTextSolidVS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Vertex"), SF_Vertex);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisRgbaLinearVS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisMaskLinearVS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathLinearVS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAaLinearVS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisImagePaintOpacityLinearVS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisTextLinearVS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Vertex"), SF_Vertex);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisRgbaRadialVS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisMaskRadialVS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathRadialVS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAaRadialVS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisImagePaintOpacityRadialVS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisTextRadialVS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Vertex"), SF_Vertex);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisRgbaPatternVS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisMaskPatternVS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternVS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAaPatternVS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisImagePaintOpacityPatternVS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisTextPatternVS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Vertex"), SF_Vertex);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisRgbaNoneVS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisMaskNoneVS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathNoneVS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAaNoneVS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisImagePaintOpacityNoneVS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisTextNoneVS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Vertex"), SF_Vertex);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisRgbaSolidPS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisMaskSolidPS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathSolidPS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAaSolidPS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisImagePaintOpacitySolidPS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisTextSolidPS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Pixel"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisRgbaLinearPS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisMaskLinearPS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathLinearPS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAaLinearPS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisImagePaintOpacityLinearPS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisTextLinearPS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Pixel"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisRgbaRadialPS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisMaskRadialPS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathRadialPS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAaRadialPS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisImagePaintOpacityRadialPS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisTextRadialPS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Pixel"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisRgbaPatternPS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisMaskPatternPS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathPatternPS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAaPatternPS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisImagePaintOpacityPatternPS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisTextPatternPS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Pixel"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(template<>, FNoesisRgbaNonePS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisMaskNonePS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathNonePS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisPathAaNonePS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisImagePaintOpacityNonePS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(template<>, FNoesisTextNonePS, TEXT("/Plugin/NoesisGUI/Private/Noesis.usf"), TEXT("Pixel"), SF_Pixel);
