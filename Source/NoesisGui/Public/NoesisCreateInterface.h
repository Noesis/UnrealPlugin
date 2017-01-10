////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGeneratedClasses.h"

UNoesisInterface* CreateInterfaceFor(Noesis::Core::Interface* BaseInterface, UObject* Outer)
{
	const Noesis::Core::TypeClass* BaseInterfaceClass = BaseInterface->GetClassType();
	UClass* Class = UNoesisInterface::StaticClass();
	if (BaseInterfaceClass == Noesis::Gui::ICollectionView::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::ICollectionView::StaticGetClassType()))
	{
		Class = UNoesisICollectionView::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::ICommand::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::ICommand::StaticGetClassType()))
	{
		Class = UNoesisICommand::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::ICommandSource::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::ICommandSource::StaticGetClassType()))
	{
		Class = UNoesisICommandSource::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::IDictionary::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::IDictionary::StaticGetClassType()))
	{
		Class = UNoesisIDictionary::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::IEasingFunction::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::IEasingFunction::StaticGetClassType()))
	{
		Class = UNoesisIEasingFunction::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::IExpression::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::IExpression::StaticGetClassType()))
	{
		Class = UNoesisIExpression::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::IItemContainerGenerator::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::IItemContainerGenerator::StaticGetClassType()))
	{
		Class = UNoesisIItemContainerGenerator::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::IRecyclingItemContainerGenerator::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::IRecyclingItemContainerGenerator::StaticGetClassType()))
	{
		Class = UNoesisIRecyclingItemContainerGenerator::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::ILayerManager::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::ILayerManager::StaticGetClassType()))
	{
		Class = UNoesisILayerManager::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::IList::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::IList::StaticGetClassType()))
	{
		Class = UNoesisIList::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::INameScope::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::INameScope::StaticGetClassType()))
	{
		Class = UNoesisINameScope::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::INotifyCollectionChanged::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::INotifyCollectionChanged::StaticGetClassType()))
	{
		Class = UNoesisINotifyCollectionChanged::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::INotifyPropertyChanged::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::INotifyPropertyChanged::StaticGetClassType()))
	{
		Class = UNoesisINotifyPropertyChanged::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::IRenderer::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::IRenderer::StaticGetClassType()))
	{
		Class = UNoesisIRenderer::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::IResourceKey::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::IResourceKey::StaticGetClassType()))
	{
		Class = UNoesisIResourceKey::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::IScrollInfo::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::IScrollInfo::StaticGetClassType()))
	{
		Class = UNoesisIScrollInfo::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::ISealable::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::ISealable::StaticGetClassType()))
	{
		Class = UNoesisISealable::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::IStoryboard::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::IStoryboard::StaticGetClassType()))
	{
		Class = UNoesisIStoryboard::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::ITimeManager::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::ITimeManager::StaticGetClassType()))
	{
		Class = UNoesisITimeManager::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::IValueConverter::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::IValueConverter::StaticGetClassType()))
	{
		Class = UNoesisIValueConverter::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::IView::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::IView::StaticGetClassType()))
	{
		Class = UNoesisIView::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::IXamlContextReceiver::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::IXamlContextReceiver::StaticGetClassType()))
	{
		Class = UNoesisIXamlContextReceiver::StaticClass();
	}
	UNoesisInterface* Interface = NewObject<UNoesisInterface>(Outer, Class);
	Interface->SetNoesisInterface(BaseInterface);
	return Interface;
}

