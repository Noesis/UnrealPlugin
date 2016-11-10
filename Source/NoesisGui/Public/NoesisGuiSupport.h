////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

inline FString NsStringToFString(const NsChar* String)
{
	return FString(StringCast<TCHAR>(String).Get());
}

inline FName NsStringToFName(const NsChar* String)
{
	return FName(String);
}

inline FMatrix NsMatrixToFMatrix(const Noesis::Math::Matrix4f& Matrix)
{
	return FMatrix(FPlane(Matrix[0][0], Matrix[1][0], Matrix[2][0], Matrix[3][0]), FPlane(Matrix[0][1], Matrix[1][1], Matrix[2][1], Matrix[3][1]), FPlane(Matrix[0][2], Matrix[1][2], Matrix[2][2], Matrix[3][2]), FPlane(Matrix[0][3], Matrix[1][3], Matrix[2][3], Matrix[3][3]));
}

inline Noesis::Math::Matrix4f FMatrixToNsMatrix(const FMatrix& Matrix)
{
	FMatrix TransposedMatrix = Matrix.GetTransposed();
	return Noesis::Math::Matrix4f((float*)&TransposedMatrix);
}

Noesis::Ptr<Noesis::Render::Texture> NoesisGuiCreateTexture(UTexture2D* Texture);

NOESISGUI_API void CollectElements(Noesis::FrameworkElement* Element, TArray<Noesis::FrameworkElement*>& Elements);
