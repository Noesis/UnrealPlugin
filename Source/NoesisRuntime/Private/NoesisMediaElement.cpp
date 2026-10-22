////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4426)
#endif

// Can't include App.MediaElement.cpp because it uses EmbeddedProviders for fonts
//#include "NoesisSDK/Src/Packages/App/MediaElement/Src/App.MediaElement.cpp"
// So we just copy the parts we need and manually add the required embedded resources
//@{

#include <NsCore/Package.h>
#include <NsCore/EnumConverter.h>

#include "NoesisSDK/Src/Packages/App/MediaElement/Include/NsApp/MediaElement.h"
#include "NoesisSDK/Src/Packages/App/MediaElement/Include/NsApp/MediaActions.h"

#if WITH_EDITOR
#include <NsGui/IntegrationAPI.h>
#include "NoesisSDK/Src/Packages/App/Providers/Include/NsApp/EmbeddedFontProvider.h"
#include "NoesisMediaElement-Icons.ttf.bin.h"

namespace NoesisApp
{
    static EmbeddedFont gMediaElementFonts[] =
    {
        { "", Media_Icons_ttf },
    };
}
#endif

NS_BEGIN_COLD_REGION

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_REGISTER_REFLECTION(App, MediaElement)
{
    using namespace Noesis;
    using namespace NoesisApp;

    NS_REGISTER_COMPONENT(MediaElement)
    NS_REGISTER_COMPONENT(EnumConverter<MediaState>)
    NS_REGISTER_COMPONENT(PlayMediaAction)
    NS_REGISTER_COMPONENT(PauseMediaAction)
    NS_REGISTER_COMPONENT(RewindMediaAction)
    NS_REGISTER_COMPONENT(StopMediaAction)

  #if WITH_EDITOR
    GUI::SetAssemblyFontProvider("Media",MakePtr<EmbeddedFontProvider>(gMediaElementFonts));
  #endif
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_INIT_PACKAGE(App, MediaElement)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_SHUTDOWN_PACKAGE(App, MediaElement)
{
}

//@}

#include "NoesisSDK/Src/Packages/App/MediaElement/Src/MediaElement.cpp"
#include "NoesisSDK/Src/Packages/App/MediaElement/Src/MediaPlayer.cpp"
#include "NoesisSDK/Src/Packages/App/MediaElement/Src/MediaActions.cpp"

#if defined(_MSC_VER)
#pragma warning(pop)
#endif
