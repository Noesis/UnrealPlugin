////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisGuiTypes.h"
#include "GeneratedClasses/NoesisGuiBitmapSource.h"
#include "NoesisGuiBitmapImage.generated.h"

UCLASS()
class NOESISGUI_API UNoesisGuiBitmapImage : public UNoesisGuiBitmapSource
{
public:
	GENERATED_UCLASS_BODY()

	virtual void SetNoesisComponent(Noesis::Core::BaseComponent* NoesisComponent) override;

	// Property UriSource
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	FString GetUriSource();
	UFUNCTION(BlueprintCallable, Category = "NoesisGui")
	void SetUriSource(FString InUriSource);

protected:

	virtual void BindEvents() override;
	virtual void UnbindEvents() override;

private:

};

