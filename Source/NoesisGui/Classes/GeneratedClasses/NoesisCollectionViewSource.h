////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisDependencyObject.h"
#include "NoesisCollectionViewSource.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisCollectionViewSource : public UNoesisDependencyObject
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property CollectionViewType
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisResourceKeyType* GetCollectionViewType();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetCollectionViewType(class UNoesisResourceKeyType* InCollectionViewType);

	// Property Source
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisBaseComponent* GetSource();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetSource(class UNoesisBaseComponent* InSource);

	// Property View
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	class UNoesisCollectionView* GetView();

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

