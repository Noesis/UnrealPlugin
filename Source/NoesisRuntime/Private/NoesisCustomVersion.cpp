////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisCustomVersion.h"
#include "Serialization/CustomVersion.h"

const FGuid FNoesisCustomVersion::GUID(0x70f52360, 0x814e4387, 0xb1ee5c55, 0x506879ae);

// Register the custom version with core
FCustomVersionRegistration GRegisterNoesisCustomVersion(FNoesisCustomVersion::GUID, FNoesisCustomVersion::LatestVersion, TEXT("NoesisVer"));
