////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisIRenderer.h"

using namespace Noesis;
using namespace Gui;

UNoesisIRenderer::UNoesisIRenderer(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisIRenderer::SetNoesisInterface(Noesis::Core::Interface* InNoesisInterface)
{
	Super::SetNoesisInterface(InNoesisInterface);

	Noesis::Gui::IRenderer* NoesisIRenderer = NsDynamicCast<Noesis::Gui::IRenderer*>(InNoesisInterface);
	check(NoesisIRenderer);
}

bool UNoesisIRenderer::NeedsOffscreen()
{
	Noesis::Gui::IRenderer* NoesisIRenderer = NsDynamicCast<Noesis::Gui::IRenderer*>(NoesisInterface.GetPtr());
	check(NoesisIRenderer);
	return NoesisIRenderer->NeedsOffscreen();
}

void UNoesisIRenderer::Render()
{
	Noesis::Gui::IRenderer* NoesisIRenderer = NsDynamicCast<Noesis::Gui::IRenderer*>(NoesisInterface.GetPtr());
	check(NoesisIRenderer);
	return NoesisIRenderer->Render();
}

void UNoesisIRenderer::RenderOffscreen()
{
	Noesis::Gui::IRenderer* NoesisIRenderer = NsDynamicCast<Noesis::Gui::IRenderer*>(NoesisInterface.GetPtr());
	check(NoesisIRenderer);
	return NoesisIRenderer->RenderOffscreen();
}

void UNoesisIRenderer::SetRenderRegion(float InX, float InY, float InWidth, float InHeight)
{
	Noesis::Gui::IRenderer* NoesisIRenderer = NsDynamicCast<Noesis::Gui::IRenderer*>(NoesisInterface.GetPtr());
	check(NoesisIRenderer);
	NsFloat32 NoesisInX = InX;
	NsFloat32 NoesisInY = InY;
	NsFloat32 NoesisInWidth = InWidth;
	NsFloat32 NoesisInHeight = InHeight;
	return NoesisIRenderer->SetRenderRegion(NoesisInX, NoesisInY, NoesisInWidth, NoesisInHeight);
}

void UNoesisIRenderer::Shutdown()
{
	Noesis::Gui::IRenderer* NoesisIRenderer = NsDynamicCast<Noesis::Gui::IRenderer*>(NoesisInterface.GetPtr());
	check(NoesisIRenderer);
	return NoesisIRenderer->Shutdown();
}

bool UNoesisIRenderer::UpdateRenderTree()
{
	Noesis::Gui::IRenderer* NoesisIRenderer = NsDynamicCast<Noesis::Gui::IRenderer*>(NoesisInterface.GetPtr());
	check(NoesisIRenderer);
	return NoesisIRenderer->UpdateRenderTree();
}

void UNoesisIRenderer::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::IRenderer* NoesisIRenderer = NsDynamicCast<Noesis::Gui::IRenderer*>(NoesisInterface.GetPtr());
	check(NoesisIRenderer)


}

void UNoesisIRenderer::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::IRenderer* NoesisIRenderer = NsDynamicCast<Noesis::Gui::IRenderer*>(NoesisInterface.GetPtr());
	check(NoesisIRenderer)


}

