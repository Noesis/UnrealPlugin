////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisSupport.h"

// RHI includes
#include "RHI.h"

// Engine includes
#include "Engine/GameViewportClient.h"

// SlateCore includes
#include "Application/SlateApplicationBase.h"
#include "Layout/WidgetPath.h"

// UMG includes
#include "Slate/SObjectWidget.h"

// NoesisRuntime includes
#include "Render/NoesisRenderDevice.h"
#include "NoesisInstance.h"

Noesis::Ptr<Noesis::Texture> NoesisCreateTexture(UTexture* Texture)
{
	return FNoesisRenderDevice::CreateTexture(Texture);
}

void* NoesisCreateMaterial(UMaterialInterface* Material)
{
	return FNoesisRenderDevice::CreateMaterial(Material);
}

void NoesisDestroyMaterial(void* Material)
{
	FNoesisRenderDevice::DestroyMaterial(Material);
}

void CollectElements(Noesis::FrameworkElement* Element, TArray<Noesis::FrameworkElement*>& Elements)
{
	const char* ElementName = Element->GetName();
	Elements.Add(Element);
	uint32 ElementCount = Noesis::LogicalTreeHelper::GetChildrenCount(Element);
	for (uint32 ElementIndex = 0; ElementIndex != ElementCount; ++ElementIndex)
	{
		Noesis::FrameworkElement* ChildElement = Noesis::DynamicPtrCast<Noesis::FrameworkElement>(Noesis::LogicalTreeHelper::GetChild(Element, ElementIndex));
		if (ChildElement)
		{
			CollectElements(ChildElement, Elements);
		}
	}
}

bool NoesisIsViewportHovered(UGameViewportClient* ViewportClient)
{
	FSlateApplicationBase& SlateApplicationBase = FSlateApplicationBase::Get();

	TSharedPtr<SWindow> ViewportWindow = ViewportClient->GetWindow();
	if (!ViewportWindow.IsValid())
	{
		return false;
	}

	TArray<TSharedRef<SWindow> > Windows;
	Windows.Add(ViewportWindow.ToSharedRef());
	FWidgetPath HitTestResults = SlateApplicationBase.LocateWindowUnderMouse(SlateApplicationBase.GetCursorPos(), Windows, false);

	if (!HitTestResults.IsValid())
	{
		return false;
	}

	TSharedRef<SWidget> TopmostWidget = HitTestResults.GetLastWidget();

	if (TopmostWidget->GetType() != FName(TEXT("SObjectWidget")))
	{
		return false;
	}

	SObjectWidget* ObjectWidget = (SObjectWidget*)&TopmostWidget.Get();
	UUserWidget* UserWidget = ObjectWidget->GetWidgetObject();

	if (!UserWidget || !UserWidget->IsA<UNoesisInstance>())
	{
		return false;
	}

	TOptional<FArrangedWidget> TopmostArrangedWidget = HitTestResults.FindArrangedWidget(TopmostWidget);
	if (!TopmostArrangedWidget.IsSet())
	{
		return false;
	}

	FVector2D Position = TopmostArrangedWidget->Geometry.AbsoluteToLocal(SlateApplicationBase.GetCursorPos()) * TopmostArrangedWidget->Geometry.Scale;

	UNoesisInstance* NoesisInstance = (UNoesisInstance*)UserWidget;
	return !NoesisInstance->HitTest(Position);
}
