////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisGuiShaders.h"

TGlobalResource<FNoesisGuiRgbaSolidVertexDeclaration> GNoesisGuiRgbaSolidVertexDeclaration;
TGlobalResource<FNoesisGuiMaskSolidVertexDeclaration> GNoesisGuiMaskSolidVertexDeclaration;
TGlobalResource<FNoesisGuiPathSolidVertexDeclaration> GNoesisGuiPathSolidVertexDeclaration;
TGlobalResource<FNoesisGuiPathAaSolidVertexDeclaration> GNoesisGuiPathAaSolidVertexDeclaration;
TGlobalResource<FNoesisGuiImagePaintOpacitySolidVertexDeclaration> GNoesisGuiImagePaintOpacitySolidVertexDeclaration;
TGlobalResource<FNoesisGuiTextSolidVertexDeclaration> GNoesisGuiTextSolidVertexDeclaration;

TGlobalResource<FNoesisGuiRgbaLinearVertexDeclaration> GNoesisGuiRgbaLinearVertexDeclaration;
TGlobalResource<FNoesisGuiMaskLinearVertexDeclaration> GNoesisGuiMaskLinearVertexDeclaration;
TGlobalResource<FNoesisGuiPathLinearVertexDeclaration> GNoesisGuiPathLinearVertexDeclaration;
TGlobalResource<FNoesisGuiPathAaLinearVertexDeclaration> GNoesisGuiPathAaLinearVertexDeclaration;
TGlobalResource<FNoesisGuiImagePaintOpacityLinearVertexDeclaration> GNoesisGuiImagePaintOpacityLinearVertexDeclaration;
TGlobalResource<FNoesisGuiTextLinearVertexDeclaration> GNoesisGuiTextLinearVertexDeclaration;

TGlobalResource<FNoesisGuiRgbaRadialVertexDeclaration> GNoesisGuiRgbaRadialVertexDeclaration;
TGlobalResource<FNoesisGuiMaskRadialVertexDeclaration> GNoesisGuiMaskRadialVertexDeclaration;
TGlobalResource<FNoesisGuiPathRadialVertexDeclaration> GNoesisGuiPathRadialVertexDeclaration;
TGlobalResource<FNoesisGuiPathAaRadialVertexDeclaration> GNoesisGuiPathAaRadialVertexDeclaration;
TGlobalResource<FNoesisGuiImagePaintOpacityRadialVertexDeclaration> GNoesisGuiImagePaintOpacityRadialVertexDeclaration;
TGlobalResource<FNoesisGuiTextRadialVertexDeclaration> GNoesisGuiTextRadialVertexDeclaration;

TGlobalResource<FNoesisGuiRgbaPatternVertexDeclaration> GNoesisGuiRgbaPatternVertexDeclaration;
TGlobalResource<FNoesisGuiMaskPatternVertexDeclaration> GNoesisGuiMaskPatternVertexDeclaration;
TGlobalResource<FNoesisGuiPathPatternVertexDeclaration> GNoesisGuiPathPatternVertexDeclaration;
TGlobalResource<FNoesisGuiPathAaPatternVertexDeclaration> GNoesisGuiPathAaPatternVertexDeclaration;
TGlobalResource<FNoesisGuiImagePaintOpacityPatternVertexDeclaration> GNoesisGuiImagePaintOpacityPatternVertexDeclaration;
TGlobalResource<FNoesisGuiTextPatternVertexDeclaration> GNoesisGuiTextPatternVertexDeclaration;

TGlobalResource<FNoesisGuiRgbaNoneVertexDeclaration> GNoesisGuiRgbaNoneVertexDeclaration;
TGlobalResource<FNoesisGuiMaskNoneVertexDeclaration> GNoesisGuiMaskNoneVertexDeclaration;
TGlobalResource<FNoesisGuiPathNoneVertexDeclaration> GNoesisGuiPathNoneVertexDeclaration;
TGlobalResource<FNoesisGuiPathAaNoneVertexDeclaration> GNoesisGuiPathAaNoneVertexDeclaration;
TGlobalResource<FNoesisGuiImagePaintOpacityNoneVertexDeclaration> GNoesisGuiImagePaintOpacityNoneVertexDeclaration;
TGlobalResource<FNoesisGuiTextNoneVertexDeclaration> GNoesisGuiTextNoneVertexDeclaration;

IMPLEMENT_SHADER_TYPE(, FNoesisGuiRgbaSolidVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiMaskSolidVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiPathSolidVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiPathAaSolidVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiImagePaintOpacitySolidVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiTextSolidVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);

IMPLEMENT_SHADER_TYPE(, FNoesisGuiRgbaLinearVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiMaskLinearVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiPathLinearVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiPathAaLinearVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiImagePaintOpacityLinearVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiTextLinearVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);

IMPLEMENT_SHADER_TYPE(, FNoesisGuiRgbaRadialVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiMaskRadialVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiPathRadialVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiPathAaRadialVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiImagePaintOpacityRadialVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiTextRadialVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);

IMPLEMENT_SHADER_TYPE(, FNoesisGuiRgbaPatternVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiMaskPatternVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiPathPatternVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiPathAaPatternVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiImagePaintOpacityPatternVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiTextPatternVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);

IMPLEMENT_SHADER_TYPE(, FNoesisGuiRgbaNoneVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiMaskNoneVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiPathNoneVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiPathAaNoneVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiImagePaintOpacityNoneVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiTextNoneVS, TEXT("NoesisGui"), TEXT("Vertex"), SF_Vertex);

IMPLEMENT_SHADER_TYPE(, FNoesisGuiRgbaSolidPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiMaskSolidPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiPathSolidPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiPathAaSolidPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiImagePaintOpacitySolidPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiTextSolidPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(, FNoesisGuiRgbaLinearPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiMaskLinearPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiPathLinearPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiPathAaLinearPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiImagePaintOpacityLinearPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiTextLinearPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(, FNoesisGuiRgbaRadialPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiMaskRadialPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiPathRadialPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiPathAaRadialPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiImagePaintOpacityRadialPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiTextRadialPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(, FNoesisGuiRgbaPatternPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiMaskPatternPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiPathPatternPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiPathAaPatternPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiImagePaintOpacityPatternPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiTextPatternPS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(, FNoesisGuiRgbaNonePS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiMaskNonePS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiPathNonePS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiPathAaNonePS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiImagePaintOpacityNonePS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
IMPLEMENT_SHADER_TYPE(, FNoesisGuiTextNonePS, TEXT("NoesisGui"), TEXT("Pixel"), SF_Pixel);
