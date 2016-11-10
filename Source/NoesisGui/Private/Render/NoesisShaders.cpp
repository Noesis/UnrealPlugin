////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
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

IMPLEMENT_SHADER_TYPE(, FNoesisRgbaSolidVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisMaskSolidVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisPathSolidVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisPathAaSolidVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisImagePaintOpacitySolidVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisTextSolidVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);

IMPLEMENT_SHADER_TYPE(, FNoesisRgbaLinearVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisMaskLinearVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisPathLinearVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisPathAaLinearVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisImagePaintOpacityLinearVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisTextLinearVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);

IMPLEMENT_SHADER_TYPE(, FNoesisRgbaRadialVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisMaskRadialVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisPathRadialVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisPathAaRadialVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisImagePaintOpacityRadialVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisTextRadialVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);

IMPLEMENT_SHADER_TYPE(, FNoesisRgbaPatternVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisMaskPatternVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisPathPatternVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisPathAaPatternVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisImagePaintOpacityPatternVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisTextPatternVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);

IMPLEMENT_SHADER_TYPE(, FNoesisRgbaNoneVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisMaskNoneVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisPathNoneVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisPathAaNoneVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisImagePaintOpacityNoneVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisTextNoneVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);

IMPLEMENT_SHADER_TYPE(, FNoesisRgbaSolidPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisMaskSolidPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisPathSolidPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisPathAaSolidPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisImagePaintOpacitySolidPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisTextSolidPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(, FNoesisRgbaLinearPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisMaskLinearPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisPathLinearPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisPathAaLinearPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisImagePaintOpacityLinearPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisTextLinearPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(, FNoesisRgbaRadialPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisMaskRadialPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisPathRadialPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisPathAaRadialPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisImagePaintOpacityRadialPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisTextRadialPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(, FNoesisRgbaPatternPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisMaskPatternPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisPathPatternPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisPathAaPatternPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisImagePaintOpacityPatternPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisTextPatternPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(, FNoesisRgbaNonePS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisMaskNonePS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisPathNonePS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisPathAaNonePS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisImagePaintOpacityNonePS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisTextNonePS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
