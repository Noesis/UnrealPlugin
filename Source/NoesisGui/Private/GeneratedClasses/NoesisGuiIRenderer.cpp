////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiIRenderer.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiIRenderer::UNoesisGuiIRenderer(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiIRenderer::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::IRenderer* NoesisIRenderer = NsDynamicCast<Noesis::Gui::IRenderer*>(InNoesisInterface);
	check(NoesisIRenderer);

}

bool UNoesisGuiIRenderer::NeedsOffscreen()
{
	Noesis::Gui::IRenderer* NoesisIRenderer = NsDynamicCast<Noesis::Gui::IRenderer*>(NoesisInterface.GetPtr());
	check(NoesisIRenderer);
	return NoesisIRenderer->NeedsOffscreen();
}

void UNoesisGuiIRenderer::Render()
{
	Noesis::Gui::IRenderer* NoesisIRenderer = NsDynamicCast<Noesis::Gui::IRenderer*>(NoesisInterface.GetPtr());
	check(NoesisIRenderer);
	return NoesisIRenderer->Render();
}

void UNoesisGuiIRenderer::RenderOffscreen()
{
	Noesis::Gui::IRenderer* NoesisIRenderer = NsDynamicCast<Noesis::Gui::IRenderer*>(NoesisInterface.GetPtr());
	check(NoesisIRenderer);
	return NoesisIRenderer->RenderOffscreen();
}

void UNoesisGuiIRenderer::SetRenderRegion(float InX, float InY, float InWidth, float InHeight)
{
	Noesis::Gui::IRenderer* NoesisIRenderer = NsDynamicCast<Noesis::Gui::IRenderer*>(NoesisInterface.GetPtr());
	check(NoesisIRenderer);
	NsFloat32 NoesisInX = InX;
	NsFloat32 NoesisInY = InY;
	NsFloat32 NoesisInWidth = InWidth;
	NsFloat32 NoesisInHeight = InHeight;
	return NoesisIRenderer->SetRenderRegion(NoesisInX, NoesisInY, NoesisInWidth, NoesisInHeight);
}

void UNoesisGuiIRenderer::Shutdown()
{
	Noesis::Gui::IRenderer* NoesisIRenderer = NsDynamicCast<Noesis::Gui::IRenderer*>(NoesisInterface.GetPtr());
	check(NoesisIRenderer);
	return NoesisIRenderer->Shutdown();
}

bool UNoesisGuiIRenderer::UpdateRenderTree()
{
	Noesis::Gui::IRenderer* NoesisIRenderer = NsDynamicCast<Noesis::Gui::IRenderer*>(NoesisInterface.GetPtr());
	check(NoesisIRenderer);
	return NoesisIRenderer->UpdateRenderTree();
}

	void UNoesisGuiIRenderer::BeginDestroy()
{
	Noesis::Gui::IRenderer* NoesisIRenderer = NsDynamicCast<Noesis::Gui::IRenderer*>(NoesisInterface.GetPtr());
	if (!NoesisIRenderer)
		return Super::BeginDestroy();


	Super::BeginDestroy();
}

