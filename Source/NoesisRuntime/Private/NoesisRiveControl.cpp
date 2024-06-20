////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4426)
#endif

#pragma push_macro("PI")
#undef PI

#pragma push_macro("verify")
#undef verify

#pragma push_macro("ensure")
#undef ensure

#define _SILENCE_CXX20_IS_POD_DEPRECATION_WARNING

// Define to 0 to avoid appending the unique asset ID at the end of Rive assets.
#define NS_USE_RIVE_UNIQUE_FILENAME 1

#include "NoesisSDK/Src/Packages/App/RiveBase/Src/App.RiveBase.cpp"
#include "NoesisSDK/Src/Packages/App/RiveBase/Src/Rive.cpp"
#include "NoesisSDK/Src/Packages/App/RiveBase/Src/RiveRun.cpp"
#include "NoesisSDK/Src/Packages/App/RiveBase/Src/RiveControl.cpp"
#include "NoesisSDK/Src/Packages/App/RiveBase/Src/RiveInput.cpp"
#include "NoesisSDK/Src/Packages/App/Rive/Src/App.Rive.cpp"
#include "NoesisSDK/Src/Packages/App/Rive/Src/RiveTriggerAction.cpp"

#pragma pop_macro("PI")
#pragma pop_macro("verify")
#pragma pop_macro("ensure")

#if defined(_MSC_VER)
#pragma warning(pop)
#endif
