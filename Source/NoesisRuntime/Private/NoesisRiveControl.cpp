////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable: 4265 4426 4834)
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

// Can't include App.RiveBase.cpp because it uses EmbeddedProviders for fonts
//#include "NoesisSDK/Src/Packages/App/MediaElement/Src/App.MediaElement.cpp"
// So we just copy the parts we need and manually add the required embedded resources
//@{

#include <NsCore/Package.h>

#include "NoesisSDK/Src/Packages/App/RiveBase/Include/NsApp/RiveControl.h"
#include "NoesisSDK/Src/Packages/App/RiveBase/Include/NsApp/RiveInput.h"
#include "NoesisSDK/Src/Packages/App/RiveBase/Include/NsApp/RiveRun.h"

#if WITH_EDITOR
#include <NsGui/IntegrationAPI.h>
#include "NoesisSDK/Src/Packages/App/Providers/Include/NsApp/EmbeddedFontProvider.h"
#include "NoesisRive-Icons.ttf.bin.h"

namespace NoesisApp
{
    static EmbeddedFont gRiveFonts[] =
    {
        { "", Rive_Icons_ttf },
    };
}
#endif

NS_BEGIN_COLD_REGION

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_REGISTER_REFLECTION(App, RiveBase)
{
    using namespace Noesis;
    using namespace NoesisApp;

    NS_REGISTER_COMPONENT(RiveControl)
    NS_REGISTER_COMPONENT(RiveInput)
    NS_REGISTER_COMPONENT(RiveRun)

  #if WITH_EDITOR
    GUI::SetAssemblyFontProvider("RiveControl", MakePtr<EmbeddedFontProvider>(gRiveFonts));
  #endif
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_INIT_PACKAGE(App, RiveBase)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_SHUTDOWN_PACKAGE(App, RiveBase)
{
}

//@}

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
