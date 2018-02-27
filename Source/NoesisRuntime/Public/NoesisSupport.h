////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Core includes
#include "CoreMinimal.h"

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

inline NsString TCHARToNsString(const TCHAR* String)
{
	return NsString(TCHAR_TO_UTF8(String));
}

inline FMatrix NsMatrixToFMatrix(const Noesis::Matrix4f& Matrix)
{
	return FMatrix(FPlane(Matrix[0][0], Matrix[1][0], Matrix[2][0], Matrix[3][0]), FPlane(Matrix[0][1], Matrix[1][1], Matrix[2][1], Matrix[3][1]), FPlane(Matrix[0][2], Matrix[1][2], Matrix[2][2], Matrix[3][2]), FPlane(Matrix[0][3], Matrix[1][3], Matrix[2][3], Matrix[3][3]));
}

inline Noesis::Matrix4f FMatrixToNsMatrix(const FMatrix& Matrix)
{
	FMatrix TransposedMatrix = Matrix.GetTransposed();
	return Noesis::Matrix4f((float*)&TransposedMatrix);
}

Noesis::Ptr<Noesis::Texture> NoesisCreateTexture(class UTexture* Texture);

NOESISRUNTIME_API void CollectElements(Noesis::FrameworkElement* Element, TArray<Noesis::FrameworkElement*>& Elements);

bool NOESISRUNTIME_API NoesisIsViewportHovered(class UGameViewportClient* ViewportClient);
