////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiFrameworkElement.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiFrameworkElement::UNoesisGuiFrameworkElement(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiFrameworkElement::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(InNoesisComponent);
	check(NoesisFrameworkElement);

	ContextMenuClosing_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiFrameworkElement::ContextMenuClosing_Private);
	NoesisFrameworkElement->ContextMenuClosing() += ContextMenuClosing_Delegate;
	ContextMenuOpening_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiFrameworkElement::ContextMenuOpening_Private);
	NoesisFrameworkElement->ContextMenuOpening() += ContextMenuOpening_Delegate;
	DataContextChanged_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiFrameworkElement::DataContextChanged_Private);
	NoesisFrameworkElement->DataContextChanged() += DataContextChanged_Delegate;
	Initialized_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiFrameworkElement::Initialized_Private);
	NoesisFrameworkElement->Initialized() += Initialized_Delegate;
	Loaded_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiFrameworkElement::Loaded_Private);
	NoesisFrameworkElement->Loaded() += Loaded_Delegate;
	SizeChanged_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiFrameworkElement::SizeChanged_Private);
	NoesisFrameworkElement->SizeChanged() += SizeChanged_Delegate;
	ToolTipClosing_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiFrameworkElement::ToolTipClosing_Private);
	NoesisFrameworkElement->ToolTipClosing() += ToolTipClosing_Delegate;
	ToolTipOpening_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiFrameworkElement::ToolTipOpening_Private);
	NoesisFrameworkElement->ToolTipOpening() += ToolTipOpening_Delegate;
	Unloaded_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiFrameworkElement::Unloaded_Private);
	NoesisFrameworkElement->Unloaded() += Unloaded_Delegate;
}

class UNoesisGuiFrameworkElement* UNoesisGuiFrameworkElement::GetParent()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return CastChecked<UNoesisGuiFrameworkElement>(Instance->FindUnrealComponentForNoesisComponent(NoesisFrameworkElement->GetParent()));
}

class UNoesisGuiResourceDictionary* UNoesisGuiFrameworkElement::GetResources()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return CastChecked<UNoesisGuiResourceDictionary>(Instance->FindUnrealComponentForNoesisComponent(NoesisFrameworkElement->GetResources()));
}

void UNoesisGuiFrameworkElement::SetResources(class UNoesisGuiResourceDictionary* InResources)
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	NoesisFrameworkElement->SetResources(NsDynamicCast<ResourceDictionary*>(InResources->NoesisComponent.GetPtr()));
}

class UNoesisGuiFrameworkElement* UNoesisGuiFrameworkElement::GetTemplatedParent()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return CastChecked<UNoesisGuiFrameworkElement>(Instance->FindUnrealComponentForNoesisComponent(NoesisFrameworkElement->GetTemplatedParent()));
}

class UNoesisGuiTriggerCollection* UNoesisGuiFrameworkElement::GetTriggers()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return CastChecked<UNoesisGuiTriggerCollection>(Instance->FindUnrealComponentForNoesisComponent(NoesisFrameworkElement->GetTriggers()));
}

void UNoesisGuiFrameworkElement::ApplyFrameworkTemplate(class UNoesisGuiFrameworkTemplate* InFrameworkTemplate, class UNoesisGuiBaseComponent* InDataContext)
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	FrameworkTemplate* NoesisInFrameworkTemplate = NsDynamicCast<FrameworkTemplate*>(InFrameworkTemplate->NoesisComponent.GetPtr());
	Core::BaseComponent* NoesisInDataContext = NsDynamicCast<Core::BaseComponent*>(InDataContext->NoesisComponent.GetPtr());
	return NoesisFrameworkElement->ApplyFrameworkTemplate(NoesisInFrameworkTemplate, NoesisInDataContext);
}

void UNoesisGuiFrameworkElement::BringIntoView()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return NoesisFrameworkElement->BringIntoView();
}

void UNoesisGuiFrameworkElement::BringIntoView_(FNoesisGuiDrawingRect InTargetRectangle)
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	const Drawing::Rect NoesisInTargetRectangle = InTargetRectangle.ToNoesis();
	return NoesisFrameworkElement->BringIntoView(NoesisInTargetRectangle);
}

class UNoesisGuiFrameworkElement* UNoesisGuiFrameworkElement::Clone(class UNoesisGuiFrameworkElement* InParent, class UNoesisGuiFrameworkElement* InTemplatedParent, class UNoesisGuiFrameworkTemplate* InTemplate_)
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	FrameworkElement* NoesisInParent = NsDynamicCast<FrameworkElement*>(InParent->NoesisComponent.GetPtr());
	FrameworkElement* NoesisInTemplatedParent = NsDynamicCast<FrameworkElement*>(InTemplatedParent->NoesisComponent.GetPtr());
	FrameworkTemplate* NoesisInTemplate_ = NsDynamicCast<FrameworkTemplate*>(InTemplate_->NoesisComponent.GetPtr());
	return CastChecked<UNoesisGuiFrameworkElement>(Instance->FindUnrealComponentForNoesisComponent(NoesisFrameworkElement->Clone(NoesisInParent, NoesisInTemplatedParent, NoesisInTemplate_)));
}

class UNoesisGuiBaseComponent* UNoesisGuiFrameworkElement::FindName(FString InName)
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	const NsChar* NoesisInName = StringCast<NsChar>(*InName).Get();
	return CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisFrameworkElement->FindName(NoesisInName)));
}

class UNoesisGuiBaseComponent* UNoesisGuiFrameworkElement::FindResource(class UNoesisGuiIResourceKey* InKey)
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	IResourceKey* NoesisInKey = NsDynamicCast<IResourceKey*>(InKey->NoesisInterface.GetPtr());
	return CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisFrameworkElement->FindResource(NoesisInKey)));
}

class UNoesisGuiBaseExpression* UNoesisGuiFrameworkElement::GetBindingExpression(const class UNoesisGuiDependencyProperty* InDp)
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	const DependencyProperty* NoesisInDp = NsDynamicCast<const DependencyProperty*>(InDp->NoesisComponent.GetPtr());
	return CastChecked<UNoesisGuiBaseExpression>(Instance->FindUnrealComponentForNoesisComponent(NoesisFrameworkElement->GetBindingExpression(NoesisInDp)));
}

class UNoesisGuiFrameworkTemplate* UNoesisGuiFrameworkElement::GetFrameworkTemplate()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return CastChecked<UNoesisGuiFrameworkTemplate>(Instance->FindUnrealComponentForNoesisComponent(NoesisFrameworkElement->GetFrameworkTemplate()));
}

class UNoesisGuiFrameworkElement* UNoesisGuiFrameworkElement::GetParentOrTemplatedParent()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return CastChecked<UNoesisGuiFrameworkElement>(Instance->FindUnrealComponentForNoesisComponent(NoesisFrameworkElement->GetParentOrTemplatedParent()));
}

class UNoesisGuiFrameworkElement* UNoesisGuiFrameworkElement::GetStateGroupsRoot()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return CastChecked<UNoesisGuiFrameworkElement>(Instance->FindUnrealComponentForNoesisComponent(NoesisFrameworkElement->GetStateGroupsRoot()));
}

class UNoesisGuiBaseComponent* UNoesisGuiFrameworkElement::GetTemplateChild(FString InName)
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	const NsChar* NoesisInName = StringCast<NsChar>(*InName).Get();
	return CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(NoesisFrameworkElement->GetTemplateChild(NoesisInName)));
}

class UNoesisGuiFrameworkElement* UNoesisGuiFrameworkElement::GetTemplateRoot()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return CastChecked<UNoesisGuiFrameworkElement>(Instance->FindUnrealComponentForNoesisComponent(NoesisFrameworkElement->GetTemplateRoot()));
}

class UNoesisGuiITimeManager* UNoesisGuiFrameworkElement::GetTimeManager()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return CastChecked<UNoesisGuiITimeManager>(Instance->FindUnrealInterfaceForNoesisInterface(NoesisFrameworkElement->GetTimeManager()));
}

bool UNoesisGuiFrameworkElement::IsLoaded()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	return NoesisFrameworkElement->IsLoaded();
}

class UNoesisGuiBaseExpression* UNoesisGuiFrameworkElement::SetBinding(const class UNoesisGuiDependencyProperty* InDp, class UNoesisGuiBaseBinding* InBinding)
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	const DependencyProperty* NoesisInDp = NsDynamicCast<const DependencyProperty*>(InDp->NoesisComponent.GetPtr());
	BaseBinding* NoesisInBinding = NsDynamicCast<BaseBinding*>(InBinding->NoesisComponent.GetPtr());
	return CastChecked<UNoesisGuiBaseExpression>(Instance->FindUnrealComponentForNoesisComponent(NoesisFrameworkElement->SetBinding(NoesisInDp, NoesisInBinding)));
}

class UNoesisGuiBaseExpression* UNoesisGuiFrameworkElement::SetBinding_(const class UNoesisGuiDependencyProperty* InDp, FString InPath)
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement);
	const DependencyProperty* NoesisInDp = NsDynamicCast<const DependencyProperty*>(InDp->NoesisComponent.GetPtr());
	const NsChar* NoesisInPath = StringCast<NsChar>(*InPath).Get();
	return CastChecked<UNoesisGuiBaseExpression>(Instance->FindUnrealComponentForNoesisComponent(NoesisFrameworkElement->SetBinding(NoesisInDp, NoesisInPath)));
}

	void UNoesisGuiFrameworkElement::ContextMenuClosing_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ContextMenuEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiContextMenuEventArgs Args(Instance, InArgs);
	ContextMenuClosing.Broadcast(Sender, Args);
}

	void UNoesisGuiFrameworkElement::ContextMenuOpening_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ContextMenuEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiContextMenuEventArgs Args(Instance, InArgs);
	ContextMenuOpening.Broadcast(Sender, Args);
}

	void UNoesisGuiFrameworkElement::DataContextChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiDependencyPropertyChangedEventArgs Args(Instance, InArgs);
	DataContextChanged.Broadcast(Sender, Args);
}

	void UNoesisGuiFrameworkElement::Initialized_Private(Noesis::Core::BaseComponent* InSender, const Noesis::EventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiEventArgs Args(Instance, InArgs);
	Initialized.Broadcast(Sender, Args);
}

	void UNoesisGuiFrameworkElement::Loaded_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	Loaded.Broadcast(Sender, Args);
}

	void UNoesisGuiFrameworkElement::SizeChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::SizeChangedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiSizeChangedEventArgs Args(Instance, InArgs);
	SizeChanged.Broadcast(Sender, Args);
}

	void UNoesisGuiFrameworkElement::ToolTipClosing_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ToolTipEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiToolTipEventArgs Args(Instance, InArgs);
	ToolTipClosing.Broadcast(Sender, Args);
}

	void UNoesisGuiFrameworkElement::ToolTipOpening_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ToolTipEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiToolTipEventArgs Args(Instance, InArgs);
	ToolTipOpening.Broadcast(Sender, Args);
}

	void UNoesisGuiFrameworkElement::Unloaded_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	Unloaded.Broadcast(Sender, Args);
}

	void UNoesisGuiFrameworkElement::BeginDestroy()
{
	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	if (!NoesisFrameworkElement)
		return Super::BeginDestroy();

	NoesisFrameworkElement->ContextMenuClosing() -= ContextMenuClosing_Delegate;
	NoesisFrameworkElement->ContextMenuOpening() -= ContextMenuOpening_Delegate;
	NoesisFrameworkElement->DataContextChanged() -= DataContextChanged_Delegate;
	NoesisFrameworkElement->Initialized() -= Initialized_Delegate;
	NoesisFrameworkElement->Loaded() -= Loaded_Delegate;
	NoesisFrameworkElement->SizeChanged() -= SizeChanged_Delegate;
	NoesisFrameworkElement->ToolTipClosing() -= ToolTipClosing_Delegate;
	NoesisFrameworkElement->ToolTipOpening() -= ToolTipOpening_Delegate;
	NoesisFrameworkElement->Unloaded() -= Unloaded_Delegate;

	Super::BeginDestroy();
}

