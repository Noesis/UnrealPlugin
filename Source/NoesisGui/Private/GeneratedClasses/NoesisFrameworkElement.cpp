////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisFrameworkElement.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisFrameworkElement::UNoesisFrameworkElement(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::FrameworkElement::StaticGetClassType();
}

void UNoesisFrameworkElement::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(InNoesisComponent);
	check(NoesisFrameworkElement);
}

float UNoesisFrameworkElement::GetActualHeight()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return (float)NoesisFrameworkElement->GetActualHeight();
}

float UNoesisFrameworkElement::GetActualWidth()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return (float)NoesisFrameworkElement->GetActualWidth();
}

class UNoesisContextMenu* UNoesisFrameworkElement::GetContextMenu()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return CastChecked<UNoesisContextMenu>(CreateClassFor(NoesisFrameworkElement->GetContextMenu(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisFrameworkElement::SetContextMenu(class UNoesisContextMenu* InContextMenu)
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	NoesisFrameworkElement->SetContextMenu(NsDynamicCast<ContextMenu*>(InContextMenu->NoesisComponent.GetPtr()));
}

class UNoesisBaseComponent* UNoesisFrameworkElement::GetDataContext()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return CastChecked<UNoesisBaseComponent>(CreateClassFor(NoesisFrameworkElement->GetDataContext(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisFrameworkElement::SetDataContext(class UNoesisBaseComponent* InDataContext)
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	NoesisFrameworkElement->SetDataContext(NsDynamicCast<Core::BaseComponent*>(InDataContext->NoesisComponent.GetPtr()));
}

class UNoesisResourceKeyType* UNoesisFrameworkElement::GetDefaultStyleKey()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return CastChecked<UNoesisResourceKeyType>(CreateClassFor(NoesisFrameworkElement->GetDefaultStyleKey(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisFrameworkElement::SetDefaultStyleKey(class UNoesisResourceKeyType* InDefaultStyleKey)
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	NoesisFrameworkElement->SetDefaultStyleKey(NsDynamicCast<ResourceKeyType*>(InDefaultStyleKey->NoesisComponent.GetPtr()));
}

class UNoesisStyle* UNoesisFrameworkElement::GetFocusVisualStyle()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return CastChecked<UNoesisStyle>(CreateClassFor(NoesisFrameworkElement->GetFocusVisualStyle(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisFrameworkElement::SetFocusVisualStyle(class UNoesisStyle* InFocusVisualStyle)
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	NoesisFrameworkElement->SetFocusVisualStyle(NsDynamicCast<Style*>(InFocusVisualStyle->NoesisComponent.GetPtr()));
}

float UNoesisFrameworkElement::GetHeight()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return (float)NoesisFrameworkElement->GetHeight();
}

void UNoesisFrameworkElement::SetHeight(float InHeight)
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	NoesisFrameworkElement->SetHeight(InHeight);
}

ENoesisHorizontalAlignment UNoesisFrameworkElement::GetHorizontalAlignment()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return (ENoesisHorizontalAlignment)NoesisFrameworkElement->GetHorizontalAlignment();
}

void UNoesisFrameworkElement::SetHorizontalAlignment(ENoesisHorizontalAlignment InHorizontalAlignment)
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	NoesisFrameworkElement->SetHorizontalAlignment((Noesis::Gui::HorizontalAlignment)InHorizontalAlignment);
}

class UNoesisTransform* UNoesisFrameworkElement::GetLayoutTransform()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return CastChecked<UNoesisTransform>(CreateClassFor(NoesisFrameworkElement->GetLayoutTransform(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisFrameworkElement::SetLayoutTransform(class UNoesisTransform* InLayoutTransform)
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	NoesisFrameworkElement->SetLayoutTransform(NsDynamicCast<Transform*>(InLayoutTransform->NoesisComponent.GetPtr()));
}

FNoesisDrawingThickness UNoesisFrameworkElement::GetMargin()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return FNoesisDrawingThickness(NoesisFrameworkElement->GetMargin());
}

void UNoesisFrameworkElement::SetMargin(FNoesisDrawingThickness InMargin)
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	NoesisFrameworkElement->SetMargin(InMargin.ToNoesis());
}

float UNoesisFrameworkElement::GetMaxHeight()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return (float)NoesisFrameworkElement->GetMaxHeight();
}

void UNoesisFrameworkElement::SetMaxHeight(float InMaxHeight)
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	NoesisFrameworkElement->SetMaxHeight(InMaxHeight);
}

float UNoesisFrameworkElement::GetMaxWidth()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return (float)NoesisFrameworkElement->GetMaxWidth();
}

void UNoesisFrameworkElement::SetMaxWidth(float InMaxWidth)
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	NoesisFrameworkElement->SetMaxWidth(InMaxWidth);
}

float UNoesisFrameworkElement::GetMinHeight()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return (float)NoesisFrameworkElement->GetMinHeight();
}

void UNoesisFrameworkElement::SetMinHeight(float InMinHeight)
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	NoesisFrameworkElement->SetMinHeight(InMinHeight);
}

float UNoesisFrameworkElement::GetMinWidth()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return (float)NoesisFrameworkElement->GetMinWidth();
}

void UNoesisFrameworkElement::SetMinWidth(float InMinWidth)
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	NoesisFrameworkElement->SetMinWidth(InMinWidth);
}

FString UNoesisFrameworkElement::GetName()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return NsStringToFString(NoesisFrameworkElement->GetName());
}

void UNoesisFrameworkElement::SetName(FString InName)
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	NoesisFrameworkElement->SetName(StringCast<NsChar>(*InName).Get());
}

bool UNoesisFrameworkElement::GetOverridesDefaultStyle()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return NoesisFrameworkElement->GetOverridesDefaultStyle();
}

void UNoesisFrameworkElement::SetOverridesDefaultStyle(bool InOverridesDefaultStyle)
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	NoesisFrameworkElement->SetOverridesDefaultStyle(InOverridesDefaultStyle);
}

class UNoesisFrameworkElement* UNoesisFrameworkElement::GetParent()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return CastChecked<UNoesisFrameworkElement>(CreateClassFor(NoesisFrameworkElement->GetParent(), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisResourceDictionary* UNoesisFrameworkElement::GetResources()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return CastChecked<UNoesisResourceDictionary>(CreateClassFor(NoesisFrameworkElement->GetResources(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisFrameworkElement::SetResources(class UNoesisResourceDictionary* InResources)
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	NoesisFrameworkElement->SetResources(NsDynamicCast<ResourceDictionary*>(InResources->NoesisComponent.GetPtr()));
}

class UNoesisStyle* UNoesisFrameworkElement::GetStyle()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return CastChecked<UNoesisStyle>(CreateClassFor(NoesisFrameworkElement->GetStyle(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisFrameworkElement::SetStyle(class UNoesisStyle* InStyle)
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	NoesisFrameworkElement->SetStyle(NsDynamicCast<Style*>(InStyle->NoesisComponent.GetPtr()));
}

class UNoesisBaseComponent* UNoesisFrameworkElement::GetTag()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return CastChecked<UNoesisBaseComponent>(CreateClassFor(NoesisFrameworkElement->GetTag(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisFrameworkElement::SetTag(class UNoesisBaseComponent* InTag)
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	NoesisFrameworkElement->SetTag(NsDynamicCast<Core::BaseComponent*>(InTag->NoesisComponent.GetPtr()));
}

class UNoesisFrameworkElement* UNoesisFrameworkElement::GetTemplatedParent()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return CastChecked<UNoesisFrameworkElement>(CreateClassFor(NoesisFrameworkElement->GetTemplatedParent(), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisBaseComponent* UNoesisFrameworkElement::GetToolTip()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return CastChecked<UNoesisBaseComponent>(CreateClassFor(NoesisFrameworkElement->GetToolTip(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisFrameworkElement::SetToolTip(class UNoesisBaseComponent* InToolTip)
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	NoesisFrameworkElement->SetToolTip(NsDynamicCast<Core::BaseComponent*>(InToolTip->NoesisComponent.GetPtr()));
}

class UNoesisTriggerCollection* UNoesisFrameworkElement::GetTriggers()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return CastChecked<UNoesisTriggerCollection>(CreateClassFor(NoesisFrameworkElement->GetTriggers(), nullptr), ECastCheckedType::NullAllowed);
}

bool UNoesisFrameworkElement::GetUseLayoutRounding()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return NoesisFrameworkElement->GetUseLayoutRounding();
}

void UNoesisFrameworkElement::SetUseLayoutRounding(bool InUseLayoutRounding)
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	NoesisFrameworkElement->SetUseLayoutRounding(InUseLayoutRounding);
}

ENoesisVerticalAlignment UNoesisFrameworkElement::GetVerticalAlignment()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return (ENoesisVerticalAlignment)NoesisFrameworkElement->GetVerticalAlignment();
}

void UNoesisFrameworkElement::SetVerticalAlignment(ENoesisVerticalAlignment InVerticalAlignment)
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	NoesisFrameworkElement->SetVerticalAlignment((Noesis::Gui::VerticalAlignment)InVerticalAlignment);
}

float UNoesisFrameworkElement::GetWidth()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return (float)NoesisFrameworkElement->GetWidth();
}

void UNoesisFrameworkElement::SetWidth(float InWidth)
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	NoesisFrameworkElement->SetWidth(InWidth);
}

void UNoesisFrameworkElement::ApplyFrameworkTemplate(class UNoesisFrameworkTemplate* InFrameworkTemplate, class UNoesisBaseComponent* InDataContext)
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	FrameworkTemplate* NoesisInFrameworkTemplate = NsDynamicCast<FrameworkTemplate*>(InFrameworkTemplate->NoesisComponent.GetPtr());
	Core::BaseComponent* NoesisInDataContext = NsDynamicCast<Core::BaseComponent*>(InDataContext->NoesisComponent.GetPtr());
	return NoesisFrameworkElement->ApplyFrameworkTemplate(NoesisInFrameworkTemplate, NoesisInDataContext);
}

void UNoesisFrameworkElement::BringIntoView()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return NoesisFrameworkElement->BringIntoView();
}

void UNoesisFrameworkElement::BringIntoView_(FNoesisDrawingRect InTargetRectangle)
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	const Drawing::Rect NoesisInTargetRectangle = InTargetRectangle.ToNoesis();
	return NoesisFrameworkElement->BringIntoView(NoesisInTargetRectangle);
}

class UNoesisFrameworkElement* UNoesisFrameworkElement::Clone(class UNoesisFrameworkElement* InParent, class UNoesisFrameworkElement* InTemplatedParent, class UNoesisFrameworkTemplate* InTemplate_)
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	FrameworkElement* NoesisInParent = NsDynamicCast<FrameworkElement*>(InParent->NoesisComponent.GetPtr());
	FrameworkElement* NoesisInTemplatedParent = NsDynamicCast<FrameworkElement*>(InTemplatedParent->NoesisComponent.GetPtr());
	FrameworkTemplate* NoesisInTemplate_ = NsDynamicCast<FrameworkTemplate*>(InTemplate_->NoesisComponent.GetPtr());
	return CastChecked<UNoesisFrameworkElement>(CreateClassFor(NoesisFrameworkElement->Clone(NoesisInParent, NoesisInTemplatedParent, NoesisInTemplate_), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisFrameworkElement::Connect(class UNoesisBaseComponent* InSource, FString InEventName, FString InHandlerName)
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	Core::BaseComponent* NoesisInSource = NsDynamicCast<Core::BaseComponent*>(InSource->NoesisComponent.GetPtr());
	const NsChar* NoesisInEventName = StringCast<NsChar>(*InEventName).Get();
	const NsChar* NoesisInHandlerName = StringCast<NsChar>(*InHandlerName).Get();
	return NoesisFrameworkElement->Connect(NoesisInSource, NoesisInEventName, NoesisInHandlerName);
}

class UNoesisBaseComponent* UNoesisFrameworkElement::FindName(FString InName)
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	const NsChar* NoesisInName = StringCast<NsChar>(*InName).Get();
	return CastChecked<UNoesisBaseComponent>(CreateClassFor(NoesisFrameworkElement->FindName(NoesisInName), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisBaseComponent* UNoesisFrameworkElement::FindResource(class UNoesisIResourceKey* InKey)
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	IResourceKey* NoesisInKey = NsDynamicCast<IResourceKey*>(InKey->NoesisInterface.GetPtr());
	return CastChecked<UNoesisBaseComponent>(CreateClassFor(NoesisFrameworkElement->FindResource(NoesisInKey), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisFrameworkTemplate* UNoesisFrameworkElement::GetFrameworkTemplate()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return CastChecked<UNoesisFrameworkTemplate>(CreateClassFor(NoesisFrameworkElement->GetFrameworkTemplate(), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisFrameworkElement* UNoesisFrameworkElement::GetParentOrTemplatedParent()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return CastChecked<UNoesisFrameworkElement>(CreateClassFor(NoesisFrameworkElement->GetParentOrTemplatedParent(), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisFrameworkElement* UNoesisFrameworkElement::GetStateGroupsRoot()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return CastChecked<UNoesisFrameworkElement>(CreateClassFor(NoesisFrameworkElement->GetStateGroupsRoot(), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisBaseComponent* UNoesisFrameworkElement::GetTemplateChild(FString InName)
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	const NsChar* NoesisInName = StringCast<NsChar>(*InName).Get();
	return CastChecked<UNoesisBaseComponent>(CreateClassFor(NoesisFrameworkElement->GetTemplateChild(NoesisInName), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisFrameworkElement* UNoesisFrameworkElement::GetTemplateRoot()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return CastChecked<UNoesisFrameworkElement>(CreateClassFor(NoesisFrameworkElement->GetTemplateRoot(), nullptr), ECastCheckedType::NullAllowed);
}

class UNoesisITimeManager* UNoesisFrameworkElement::GetTimeManager()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return CastChecked<UNoesisITimeManager>(CreateInterfaceFor(NoesisFrameworkElement->GetTimeManager(), nullptr), ECastCheckedType::NullAllowed);
}

bool UNoesisFrameworkElement::IsLoaded()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return NoesisFrameworkElement->IsLoaded();
}

void UNoesisFrameworkElement::ContextMenuClosing_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ContextMenuEventArgs& InArgs)
{
	if (!ContextMenuClosing.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisContextMenuEventArgs Args(InArgs);
	ContextMenuClosing.Broadcast(Sender, Args);
}

void UNoesisFrameworkElement::ContextMenuOpening_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ContextMenuEventArgs& InArgs)
{
	if (!ContextMenuOpening.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisContextMenuEventArgs Args(InArgs);
	ContextMenuOpening.Broadcast(Sender, Args);
}

void UNoesisFrameworkElement::DataContextChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs)
{
	if (!DataContextChanged.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisDependencyPropertyChangedEventArgs Args(InArgs);
	DataContextChanged.Broadcast(Sender, Args);
}

void UNoesisFrameworkElement::Initialized_Private(Noesis::Core::BaseComponent* InSender, const Noesis::EventArgs& InArgs)
{
	if (!Initialized.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisEventArgs Args(InArgs);
	Initialized.Broadcast(Sender, Args);
}

void UNoesisFrameworkElement::Loaded_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Loaded.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisRoutedEventArgs Args(InArgs);
	Loaded.Broadcast(Sender, Args);
}

void UNoesisFrameworkElement::RequestBringIntoView_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RequestBringIntoViewEventArgs& InArgs)
{
	if (!RequestBringIntoView.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisRequestBringIntoViewEventArgs Args(InArgs);
	RequestBringIntoView.Broadcast(Sender, Args);
}

void UNoesisFrameworkElement::SizeChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::SizeChangedEventArgs& InArgs)
{
	if (!SizeChanged.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisSizeChangedEventArgs Args(InArgs);
	SizeChanged.Broadcast(Sender, Args);
}

void UNoesisFrameworkElement::ToolTipClosing_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ToolTipEventArgs& InArgs)
{
	if (!ToolTipClosing.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisToolTipEventArgs Args(InArgs);
	ToolTipClosing.Broadcast(Sender, Args);
}

void UNoesisFrameworkElement::ToolTipOpening_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ToolTipEventArgs& InArgs)
{
	if (!ToolTipOpening.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisToolTipEventArgs Args(InArgs);
	ToolTipOpening.Broadcast(Sender, Args);
}

void UNoesisFrameworkElement::Unloaded_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Unloaded.IsBound())
		return;
	UNoesisBaseComponent* Sender = CastChecked<UNoesisBaseComponent>(CreateClassFor(InSender, nullptr), ECastCheckedType::NullAllowed);
	FNoesisRoutedEventArgs Args(InArgs);
	Unloaded.Broadcast(Sender, Args);
}

void UNoesisFrameworkElement::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);

	ContextMenuClosing_Delegate = Noesis::MakeDelegate(this, &UNoesisFrameworkElement::ContextMenuClosing_Private);
	NoesisFrameworkElement->ContextMenuClosing() += ContextMenuClosing_Delegate;
	ContextMenuOpening_Delegate = Noesis::MakeDelegate(this, &UNoesisFrameworkElement::ContextMenuOpening_Private);
	NoesisFrameworkElement->ContextMenuOpening() += ContextMenuOpening_Delegate;
	DataContextChanged_Delegate = Noesis::MakeDelegate(this, &UNoesisFrameworkElement::DataContextChanged_Private);
	NoesisFrameworkElement->DataContextChanged() += DataContextChanged_Delegate;
	Initialized_Delegate = Noesis::MakeDelegate(this, &UNoesisFrameworkElement::Initialized_Private);
	NoesisFrameworkElement->Initialized() += Initialized_Delegate;
	Loaded_Delegate = Noesis::MakeDelegate(this, &UNoesisFrameworkElement::Loaded_Private);
	NoesisFrameworkElement->Loaded() += Loaded_Delegate;
	RequestBringIntoView_Delegate = Noesis::MakeDelegate(this, &UNoesisFrameworkElement::RequestBringIntoView_Private);
	NoesisFrameworkElement->RequestBringIntoView() += RequestBringIntoView_Delegate;
	SizeChanged_Delegate = Noesis::MakeDelegate(this, &UNoesisFrameworkElement::SizeChanged_Private);
	NoesisFrameworkElement->SizeChanged() += SizeChanged_Delegate;
	ToolTipClosing_Delegate = Noesis::MakeDelegate(this, &UNoesisFrameworkElement::ToolTipClosing_Private);
	NoesisFrameworkElement->ToolTipClosing() += ToolTipClosing_Delegate;
	ToolTipOpening_Delegate = Noesis::MakeDelegate(this, &UNoesisFrameworkElement::ToolTipOpening_Private);
	NoesisFrameworkElement->ToolTipOpening() += ToolTipOpening_Delegate;
	Unloaded_Delegate = Noesis::MakeDelegate(this, &UNoesisFrameworkElement::Unloaded_Private);
	NoesisFrameworkElement->Unloaded() += Unloaded_Delegate;

}

void UNoesisFrameworkElement::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);

	NoesisFrameworkElement->ContextMenuClosing() -= ContextMenuClosing_Delegate;
	NoesisFrameworkElement->ContextMenuOpening() -= ContextMenuOpening_Delegate;
	NoesisFrameworkElement->DataContextChanged() -= DataContextChanged_Delegate;
	NoesisFrameworkElement->Initialized() -= Initialized_Delegate;
	NoesisFrameworkElement->Loaded() -= Loaded_Delegate;
	NoesisFrameworkElement->RequestBringIntoView() -= RequestBringIntoView_Delegate;
	NoesisFrameworkElement->SizeChanged() -= SizeChanged_Delegate;
	NoesisFrameworkElement->ToolTipClosing() -= ToolTipClosing_Delegate;
	NoesisFrameworkElement->ToolTipOpening() -= ToolTipOpening_Delegate;
	NoesisFrameworkElement->Unloaded() -= Unloaded_Delegate;

}

