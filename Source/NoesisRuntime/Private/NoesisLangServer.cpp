////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#if WITH_EDITOR

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4426)
#endif

#ifdef PLATFORM_WINDOWS
#if PLATFORM_WINDOWS
#include "Windows/AllowWindowsPlatformTypes.h"
#endif
#endif

#include "NoesisSDK/Src/Packages/App/LangServer/Src/App.LangServer.cpp"
#include "NoesisSDK/Src/Packages/App/LangServer/Src/CapabilityColor.cpp"
#include "NoesisSDK/Src/Packages/App/LangServer/Src/CapabilityCompletion.cpp"
#include "NoesisSDK/Src/Packages/App/LangServer/Src/CapabilityDiagnostics.cpp"
#include "NoesisSDK/Src/Packages/App/LangServer/Src/DocumentHelper.cpp"
#include "NoesisSDK/Src/Packages/App/LangServer/Src/JsonBuilder.cpp"
#include "NoesisSDK/Src/Packages/App/LangServer/Src/JsonObject.cpp"
#include "NoesisSDK/Src/Packages/App/LangServer/Src/LangServer.cpp"
#include "NoesisSDK/Src/Packages/App/LangServer/Src/LangServerReflectionHelper.cpp"
#include "NoesisSDK/Src/Packages/App/LangServer/Src/LenientXamlParser.cpp"
#include "NoesisSDK/Src/Packages/App/LangServer/Src/LangServerSocket.cpp"
#include "NoesisSDK/Src/Packages/App/LangServer/Src/MessageBuffer.cpp"
#include "NoesisSDK/Src/Packages/App/LangServer/Src/MessageReader.cpp"
#include "NoesisSDK/Src/Packages/App/LangServer/Src/MessageWriter.cpp"
#include "NoesisSDK/Src/Packages/App/LangServer/Src/Workspace.cpp"

#ifdef PLATFORM_WINDOWS
#if PLATFORM_WINDOWS
#include "Windows/HideWindowsPlatformTypes.h"
#endif
#endif

#if defined(_MSC_VER)
#pragma warning(pop)
#endif

#endif