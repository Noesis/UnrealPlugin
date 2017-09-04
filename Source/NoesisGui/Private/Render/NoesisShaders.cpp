////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
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

IMPLEMENT_SHADER_TYPE(, FNoesisRgbaSolidVS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisMaskSolidVS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisPathSolidVS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisPathAaSolidVS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisImagePaintOpacitySolidVS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisTextSolidVS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Vertex"), SF_Vertex);

IMPLEMENT_SHADER_TYPE(, FNoesisRgbaLinearVS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisMaskLinearVS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisPathLinearVS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisPathAaLinearVS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisImagePaintOpacityLinearVS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisTextLinearVS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Vertex"), SF_Vertex);

IMPLEMENT_SHADER_TYPE(, FNoesisRgbaRadialVS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisMaskRadialVS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisPathRadialVS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisPathAaRadialVS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisImagePaintOpacityRadialVS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisTextRadialVS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Vertex"), SF_Vertex);

IMPLEMENT_SHADER_TYPE(, FNoesisRgbaPatternVS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisMaskPatternVS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisPathPatternVS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisPathAaPatternVS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisImagePaintOpacityPatternVS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisTextPatternVS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Vertex"), SF_Vertex);

IMPLEMENT_SHADER_TYPE(, FNoesisRgbaNoneVS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisMaskNoneVS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisPathNoneVS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisPathAaNoneVS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisImagePaintOpacityNoneVS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisTextNoneVS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Vertex"), SF_Vertex);

IMPLEMENT_SHADER_TYPE(, FNoesisRgbaSolidPS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisMaskSolidPS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisPathSolidPS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisPathAaSolidPS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisImagePaintOpacitySolidPS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisTextSolidPS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Pixel"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(, FNoesisRgbaLinearPS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisMaskLinearPS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisPathLinearPS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisPathAaLinearPS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisImagePaintOpacityLinearPS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisTextLinearPS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Pixel"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(, FNoesisRgbaRadialPS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisMaskRadialPS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisPathRadialPS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisPathAaRadialPS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisImagePaintOpacityRadialPS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisTextRadialPS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Pixel"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(, FNoesisRgbaPatternPS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisMaskPatternPS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisPathPatternPS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisPathAaPatternPS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisImagePaintOpacityPatternPS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisTextPatternPS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Pixel"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(, FNoesisRgbaNonePS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisMaskNonePS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisPathNonePS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisPathAaNonePS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisImagePaintOpacityNonePS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisTextNonePS, TEXT("/Plugin/NoesisGui/Private/NoesisGui.usf"), TEXT("Pixel"), SF_Pixel);
