////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Core includes
#include "CoreMinimal.h"
#include "Misc/Paths.h"

// CoreUObject includes
#include "Misc/PackageName.h"

// Noesis includes
#include "NoesisSDK.h"

inline FString NsStringToFString(const char* String)
{
	return FString(UTF8_TO_TCHAR(String));
}

inline FName NsStringToFName(const char* String)
{
	return FName(UTF8_TO_TCHAR(String));
}

inline Noesis::String TCHARToNsString(const TCHAR* String)
{
	return Noesis::String(TCHAR_TO_UTF8(String));
}

inline FMatrix NsMatrixToFMatrix(const Noesis::Matrix4& Matrix)
{
	return FMatrix(FPlane(Matrix[0][0], Matrix[1][0], Matrix[2][0], Matrix[3][0]), FPlane(Matrix[0][1], Matrix[1][1], Matrix[2][1], Matrix[3][1]), FPlane(Matrix[0][2], Matrix[1][2], Matrix[2][2], Matrix[3][2]), FPlane(Matrix[0][3], Matrix[1][3], Matrix[2][3], Matrix[3][3]));
}

inline Noesis::Matrix4 FMatrixToNsMatrix(const FMatrix& Matrix)
{
	FMatrix TransposedMatrix = Matrix.GetTransposed();
	return Noesis::Matrix4((float*)&TransposedMatrix);
}

inline FString SanitizeAssetPath(const FString& AssetPath)
{
	FString Result = AssetPath;
	const TCHAR* InvalidChar = INVALID_LONGPACKAGE_CHARACTERS;
	while (*InvalidChar)
	{
		Result.ReplaceCharInline(*InvalidChar, TCHAR('_'), ESearchCase::CaseSensitive);
		++InvalidChar;
	}
	return Result;
}

inline Noesis::String GetAssetRoot(const Noesis::String& Assembly)
{
	return Assembly.Empty() ? "Game" : (Assembly == "Noesis.GUI.Extensions" ? "NoesisGUI" : Assembly.Str());
}

inline FString NsProviderUriToAssetPath(const Noesis::Uri& Uri)
{
	Noesis::FixedString<512> Path;
	Uri.GetPath(Path);

	FString FullPath = FPaths::GetPath(Path.Str());
	FString Package = FPaths::GetBaseFilename(Path.Str());
	FString SafePath = Package.IsEmpty() ? FullPath : FullPath / SanitizeAssetPath(Package);

	Noesis::String Assembly;
	Uri.GetAssembly(Assembly);

	FString AssetPath = TEXT("/");
	AssetPath += GetAssetRoot(Assembly).Str();
	AssetPath += TEXT("/") + SafePath;

	return AssetPath;
}

NOESISRUNTIME_API Noesis::Ptr<Noesis::Texture> NoesisCreateTexture(class UTexture* Texture);

NOESISRUNTIME_API void* NoesisCreateMaterial(class UMaterialInterface* Material);

NOESISRUNTIME_API void NoesisDestroyMaterial(void* Material);

NOESISRUNTIME_API void CollectElements(Noesis::FrameworkElement* Element, TArray<Noesis::FrameworkElement*>& Elements);

bool NOESISRUNTIME_API NoesisIsViewportHovered(class UGameViewportClient* ViewportClient);

template<typename T>
inline uint32 GetTypeHash(const Noesis::Ptr<T>& Pointer)
{
	return PointerHash(Pointer.GetPtr());
}
