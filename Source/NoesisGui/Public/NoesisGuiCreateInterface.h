////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiGeneratedClasses.h"

UNoesisGuiInterface* CreateInterfaceFor(Noesis::Core::Interface* BaseInterface, UObject* Outer)
{
	const Noesis::Core::TypeClass* BaseInterfaceClass = BaseInterface->GetClassType();
	UClass* Class = UNoesisGuiInterface::StaticClass();
	if (BaseInterfaceClass == Noesis::Gui::ICollectionView::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::ICollectionView::StaticGetClassType()))
	{
		Class = UNoesisGuiICollectionView::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::ICommand::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::ICommand::StaticGetClassType()))
	{
		Class = UNoesisGuiICommand::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::ICommandSource::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::ICommandSource::StaticGetClassType()))
	{
		Class = UNoesisGuiICommandSource::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::IControlLibrary::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::IControlLibrary::StaticGetClassType()))
	{
		Class = UNoesisGuiIControlLibrary::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::IDictionary::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::IDictionary::StaticGetClassType()))
	{
		Class = UNoesisGuiIDictionary::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::IEasingFunction::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::IEasingFunction::StaticGetClassType()))
	{
		Class = UNoesisGuiIEasingFunction::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::IExpression::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::IExpression::StaticGetClassType()))
	{
		Class = UNoesisGuiIExpression::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::IItemContainerGenerator::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::IItemContainerGenerator::StaticGetClassType()))
	{
		Class = UNoesisGuiIItemContainerGenerator::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::IRecyclingItemContainerGenerator::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::IRecyclingItemContainerGenerator::StaticGetClassType()))
	{
		Class = UNoesisGuiIRecyclingItemContainerGenerator::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::ILayerManager::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::ILayerManager::StaticGetClassType()))
	{
		Class = UNoesisGuiILayerManager::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::IList::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::IList::StaticGetClassType()))
	{
		Class = UNoesisGuiIList::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::INameScope::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::INameScope::StaticGetClassType()))
	{
		Class = UNoesisGuiINameScope::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::INotifyCollectionChanged::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::INotifyCollectionChanged::StaticGetClassType()))
	{
		Class = UNoesisGuiINotifyCollectionChanged::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::INotifyPropertyChanged::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::INotifyPropertyChanged::StaticGetClassType()))
	{
		Class = UNoesisGuiINotifyPropertyChanged::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::IRenderer::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::IRenderer::StaticGetClassType()))
	{
		Class = UNoesisGuiIRenderer::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::IResourceKey::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::IResourceKey::StaticGetClassType()))
	{
		Class = UNoesisGuiIResourceKey::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::IScrollInfo::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::IScrollInfo::StaticGetClassType()))
	{
		Class = UNoesisGuiIScrollInfo::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::IStoryboard::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::IStoryboard::StaticGetClassType()))
	{
		Class = UNoesisGuiIStoryboard::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::ITimeManager::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::ITimeManager::StaticGetClassType()))
	{
		Class = UNoesisGuiITimeManager::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::IValueConverter::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::IValueConverter::StaticGetClassType()))
	{
		Class = UNoesisGuiIValueConverter::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::IView::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::IView::StaticGetClassType()))
	{
		Class = UNoesisGuiIView::StaticClass();
	}
	if (BaseInterfaceClass == Noesis::Gui::IXamlContextReceiver::StaticGetClassType() || BaseInterfaceClass->IsDescendantOf(Noesis::Gui::IXamlContextReceiver::StaticGetClassType()))
	{
		Class = UNoesisGuiIXamlContextReceiver::StaticClass();
	}
	UNoesisGuiInterface* Interface = NewObject<UNoesisGuiInterface>(Outer, Class);
	Interface->SetNoesisInterface(BaseInterface);
	return Interface;
}

