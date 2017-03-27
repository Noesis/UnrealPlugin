////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"
#include "GeneratedClasses/NoesisCollectionViewSource.h"

using namespace Noesis;
using namespace Gui;

UNoesisCollectionViewSource::UNoesisCollectionViewSource(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::CollectionViewSource::StaticGetClassType();
}

void UNoesisCollectionViewSource::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::CollectionViewSource* NoesisCollectionViewSource = NsDynamicCast<Noesis::Gui::CollectionViewSource*>(InNoesisComponent);
	check(NoesisCollectionViewSource);
}

class UNoesisResourceKeyType* UNoesisCollectionViewSource::GetCollectionViewType()
{
	Noesis::Gui::CollectionViewSource* NoesisCollectionViewSource = NsDynamicCast<Noesis::Gui::CollectionViewSource*>(NoesisComponent.GetPtr());
	check(NoesisCollectionViewSource);
	return CastChecked<UNoesisResourceKeyType>(CreateClassFor(NoesisCollectionViewSource->GetCollectionViewType(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisCollectionViewSource::SetCollectionViewType(class UNoesisResourceKeyType* InCollectionViewType)
{
	Noesis::Gui::CollectionViewSource* NoesisCollectionViewSource = NsDynamicCast<Noesis::Gui::CollectionViewSource*>(NoesisComponent.GetPtr());
	check(NoesisCollectionViewSource);
	NoesisCollectionViewSource->SetCollectionViewType(NsDynamicCast<ResourceKeyType*>(InCollectionViewType->NoesisComponent.GetPtr()));
}

class UNoesisBaseComponent* UNoesisCollectionViewSource::GetSource()
{
	Noesis::Gui::CollectionViewSource* NoesisCollectionViewSource = NsDynamicCast<Noesis::Gui::CollectionViewSource*>(NoesisComponent.GetPtr());
	check(NoesisCollectionViewSource);
	return CastChecked<UNoesisBaseComponent>(CreateClassFor(NoesisCollectionViewSource->GetSource(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisCollectionViewSource::SetSource(class UNoesisBaseComponent* InSource)
{
	Noesis::Gui::CollectionViewSource* NoesisCollectionViewSource = NsDynamicCast<Noesis::Gui::CollectionViewSource*>(NoesisComponent.GetPtr());
	check(NoesisCollectionViewSource);
	NoesisCollectionViewSource->SetSource(NsDynamicCast<Core::BaseComponent*>(InSource->NoesisComponent.GetPtr()));
}

class UNoesisCollectionView* UNoesisCollectionViewSource::GetView()
{
	Noesis::Gui::CollectionViewSource* NoesisCollectionViewSource = NsDynamicCast<Noesis::Gui::CollectionViewSource*>(NoesisComponent.GetPtr());
	check(NoesisCollectionViewSource);
	return CastChecked<UNoesisCollectionView>(CreateClassFor(NoesisCollectionViewSource->GetView(), nullptr), ECastCheckedType::NullAllowed);
}

void UNoesisCollectionViewSource::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::CollectionViewSource* NoesisCollectionViewSource = NsDynamicCast<Noesis::Gui::CollectionViewSource*>(NoesisComponent.GetPtr());
	check(NoesisCollectionViewSource);


}

void UNoesisCollectionViewSource::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::CollectionViewSource* NoesisCollectionViewSource = NsDynamicCast<Noesis::Gui::CollectionViewSource*>(NoesisComponent.GetPtr());
	check(NoesisCollectionViewSource);


}

