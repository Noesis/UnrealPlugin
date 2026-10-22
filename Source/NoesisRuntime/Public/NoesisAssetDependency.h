////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// Core includes
#include "CoreMinimal.h"

// Noesis includes
#include "NoesisSDK.h"

namespace Noesis
{
////////////////////////////////////////////////////////////////////////////////////////////////////
/// Class metadata that indicates asset dependencies for the associated class.
/// Can be specified multiple times if the type depends on more than one asset.
////////////////////////////////////////////////////////////////////////////////////////////////////
class NOESISRUNTIME_API AssetDependency : public TypeMetaData
{
public:
	AssetDependency(const Uri& AssetPath) : mAssetPath(AssetPath) {}
	AssetDependency(Uri&& AssetPath) : mAssetPath(AssetPath) {}

	Uri AssetPath() const { return mAssetPath; }

private:
	Uri mAssetPath;

	NS_IMPLEMENT_INLINE_REFLECTION_(AssetDependency, TypeMetaData)
};
}
