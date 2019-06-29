////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Generated header include
#include "NoesisXamlFactory.generated.h"

class UNoesisResourceResolver;

struct FXamlDescriptor
{
	FString Path;
	UNoesisXaml* Xaml;
};

struct FFontDescriptor
{
	FString Family;
	UFont* Font;
};

struct FImageDescriptor
{
	FString Path;
	UTexture2D* Texture;
};

UCLASS()
class NOESISEDITOR_API UNoesisXamlFactory : public UFactory
{
	GENERATED_UCLASS_BODY()

	// UFactory interface
	virtual UObject* FactoryCreateBinary(UClass* Class, UObject* Parent, FName Name, EObjectFlags Flags, UObject* Context, const TCHAR* Type, const uint8*& Buffer, const uint8* BufferEnd, FFeedbackContext* Warn) override;
	// End of UFactory interface

protected:
	void ImportXamls(FString BasePackageName, FString ProjectURIRoot, FString Path, TArray<FXamlDescriptor>& XamlDescriptors);
	UFont* ImportFontFamily(FString Path, FString Family, FString BasePackageName, FString ProjectURIRoot);
	void ImportImages(FString BasePackageName, FString ProjectURIRoot, FString Path, TArray<FImageDescriptor>& ImageDescriptors);

	UNoesisResourceResolver* GetResourceResolver();
};
