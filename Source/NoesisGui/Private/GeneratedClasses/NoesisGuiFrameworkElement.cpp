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

void UNoesisGuiFrameworkElement::ContextMenuClosing_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ContextMenuEventArgs& InArgs)
{
	if (!ContextMenuClosing.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiContextMenuEventArgs Args(Instance, InArgs);
	ContextMenuClosing.Broadcast(Sender, Args);
}

void UNoesisGuiFrameworkElement::ContextMenuOpening_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ContextMenuEventArgs& InArgs)
{
	if (!ContextMenuOpening.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiContextMenuEventArgs Args(Instance, InArgs);
	ContextMenuOpening.Broadcast(Sender, Args);
}

void UNoesisGuiFrameworkElement::DataContextChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::DependencyPropertyChangedEventArgs& InArgs)
{
	if (!DataContextChanged.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiDependencyPropertyChangedEventArgs Args(Instance, InArgs);
	DataContextChanged.Broadcast(Sender, Args);
}

void UNoesisGuiFrameworkElement::Initialized_Private(Noesis::Core::BaseComponent* InSender, const Noesis::EventArgs& InArgs)
{
	if (!Initialized.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiEventArgs Args(Instance, InArgs);
	Initialized.Broadcast(Sender, Args);
}

void UNoesisGuiFrameworkElement::Loaded_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Loaded.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	Loaded.Broadcast(Sender, Args);
}

void UNoesisGuiFrameworkElement::SizeChanged_Private(Noesis::Core::BaseComponent* InSender, const Noesis::SizeChangedEventArgs& InArgs)
{
	if (!SizeChanged.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiSizeChangedEventArgs Args(Instance, InArgs);
	SizeChanged.Broadcast(Sender, Args);
}

void UNoesisGuiFrameworkElement::ToolTipClosing_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ToolTipEventArgs& InArgs)
{
	if (!ToolTipClosing.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiToolTipEventArgs Args(Instance, InArgs);
	ToolTipClosing.Broadcast(Sender, Args);
}

void UNoesisGuiFrameworkElement::ToolTipOpening_Private(Noesis::Core::BaseComponent* InSender, const Noesis::ToolTipEventArgs& InArgs)
{
	if (!ToolTipOpening.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiToolTipEventArgs Args(Instance, InArgs);
	ToolTipOpening.Broadcast(Sender, Args);
}

void UNoesisGuiFrameworkElement::Unloaded_Private(Noesis::Core::BaseComponent* InSender, const Noesis::RoutedEventArgs& InArgs)
{
	if (!Unloaded.IsBound() || !Instance || Instance->HasAnyFlags(RF_BeginDestroyed))
		return;
	UNoesisGuiBaseComponent* Sender = CastChecked<UNoesisGuiBaseComponent>(Instance->FindUnrealComponentForNoesisComponent(InSender));
	FNoesisGuiRoutedEventArgs Args(Instance, InArgs);
	Unloaded.Broadcast(Sender, Args);
}

void UNoesisGuiFrameworkElement::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement)

	ContextMenuClosing_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiFrameworkElement::ContextMenuClosing_Private);
	if (ContextMenuClosing.IsBound())
	{
		NoesisFrameworkElement->ContextMenuClosing() += ContextMenuClosing_Delegate;
	}
	ContextMenuOpening_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiFrameworkElement::ContextMenuOpening_Private);
	if (ContextMenuOpening.IsBound())
	{
		NoesisFrameworkElement->ContextMenuOpening() += ContextMenuOpening_Delegate;
	}
	DataContextChanged_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiFrameworkElement::DataContextChanged_Private);
	if (DataContextChanged.IsBound())
	{
		NoesisFrameworkElement->DataContextChanged() += DataContextChanged_Delegate;
	}
	Initialized_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiFrameworkElement::Initialized_Private);
	if (Initialized.IsBound())
	{
		NoesisFrameworkElement->Initialized() += Initialized_Delegate;
	}
	Loaded_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiFrameworkElement::Loaded_Private);
	if (Loaded.IsBound())
	{
		NoesisFrameworkElement->Loaded() += Loaded_Delegate;
	}
	SizeChanged_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiFrameworkElement::SizeChanged_Private);
	if (SizeChanged.IsBound())
	{
		NoesisFrameworkElement->SizeChanged() += SizeChanged_Delegate;
	}
	ToolTipClosing_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiFrameworkElement::ToolTipClosing_Private);
	if (ToolTipClosing.IsBound())
	{
		NoesisFrameworkElement->ToolTipClosing() += ToolTipClosing_Delegate;
	}
	ToolTipOpening_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiFrameworkElement::ToolTipOpening_Private);
	if (ToolTipOpening.IsBound())
	{
		NoesisFrameworkElement->ToolTipOpening() += ToolTipOpening_Delegate;
	}
	Unloaded_Delegate = Noesis::MakeDelegate(this, &UNoesisGuiFrameworkElement::Unloaded_Private);
	if (Unloaded.IsBound())
	{
		NoesisFrameworkElement->Unloaded() += Unloaded_Delegate;
	}

}

void UNoesisGuiFrameworkElement::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::FrameworkElement* NoesisFrameworkElement = NsDynamicCast<Noesis::Gui::FrameworkElement*>(NoesisComponent.GetPtr());
	check(NoesisFrameworkElement)

	if (ContextMenuClosing.IsBound())
	{
		NoesisFrameworkElement->ContextMenuClosing() -= ContextMenuClosing_Delegate;
	}
	if (ContextMenuOpening.IsBound())
	{
		NoesisFrameworkElement->ContextMenuOpening() -= ContextMenuOpening_Delegate;
	}
	if (DataContextChanged.IsBound())
	{
		NoesisFrameworkElement->DataContextChanged() -= DataContextChanged_Delegate;
	}
	if (Initialized.IsBound())
	{
		NoesisFrameworkElement->Initialized() -= Initialized_Delegate;
	}
	if (Loaded.IsBound())
	{
		NoesisFrameworkElement->Loaded() -= Loaded_Delegate;
	}
	if (SizeChanged.IsBound())
	{
		NoesisFrameworkElement->SizeChanged() -= SizeChanged_Delegate;
	}
	if (ToolTipClosing.IsBound())
	{
		NoesisFrameworkElement->ToolTipClosing() -= ToolTipClosing_Delegate;
	}
	if (ToolTipOpening.IsBound())
	{
		NoesisFrameworkElement->ToolTipOpening() -= ToolTipOpening_Delegate;
	}
	if (Unloaded.IsBound())
	{
		NoesisFrameworkElement->Unloaded() -= Unloaded_Delegate;
	}

}

