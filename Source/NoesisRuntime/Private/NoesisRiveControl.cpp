////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4426)
#endif

#ifdef PI
#undef PI
#endif

#define _SILENCE_CXX20_IS_POD_DEPRECATION_WARNING

#include "NoesisSDK/Src/Packages/App/RiveBase/Src/App.RiveBase.cpp"
#include "NoesisSDK/Src/Packages/App/RiveBase/Src/Rive.cpp"
#include "NoesisSDK/Src/Packages/App/RiveBase/Src/RiveControl.cpp"
#include "NoesisSDK/Src/Packages/App/RiveBase/Src/RiveInput.cpp"
#include "NoesisSDK/Src/Packages/App/Rive/Src/App.Rive.cpp"
#include "NoesisSDK/Src/Packages/App/Rive/Src/RiveTriggerAction.cpp"

#if defined(_MSC_VER)
#pragma warning(pop)
#endif
