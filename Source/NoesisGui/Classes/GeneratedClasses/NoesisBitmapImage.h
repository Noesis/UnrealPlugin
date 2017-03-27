////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "NoesisEnums.h"
#include "NoesisStructs.h"
#include "NoesisEvents.h"
#include "GeneratedClasses/NoesisBitmapSource.h"
#include "NoesisBitmapImage.generated.h"

UCLASS(BlueprintType)
class NOESISGUI_API UNoesisBitmapImage : public UNoesisBitmapSource
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

