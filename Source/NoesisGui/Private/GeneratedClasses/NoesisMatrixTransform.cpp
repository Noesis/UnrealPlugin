////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GeneratedClasses/NoesisMatrixTransform.h"
#include "NoesisCreateClass.h"
#include "NoesisCreateInterface.h"

using namespace Noesis;
using namespace Gui;

UNoesisMatrixTransform::UNoesisMatrixTransform(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NoesisComponentTypeClass = Noesis::Gui::MatrixTransform::StaticGetClassType();
}

void UNoesisMatrixTransform::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::MatrixTransform* NoesisMatrixTransform = NsDynamicCast<Noesis::Gui::MatrixTransform*>(InNoesisComponent);
	check(NoesisMatrixTransform);
}

void UNoesisMatrixTransform::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::MatrixTransform* NoesisMatrixTransform = NsDynamicCast<Noesis::Gui::MatrixTransform*>(NoesisComponent.GetPtr());
	check(NoesisMatrixTransform);


}

void UNoesisMatrixTransform::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::MatrixTransform* NoesisMatrixTransform = NsDynamicCast<Noesis::Gui::MatrixTransform*>(NoesisComponent.GetPtr());
	check(NoesisMatrixTransform);


}

