////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4426)
#endif

// Can't include App.Toolkit.cpp because it uses EmbeddedProviders for default styles and fonts
//#include "NoesisSDK/Src/Packages/App/Toolkit/Src/App.Toolkit.cpp"
// So we just copy the parts we need and manually add the required embedded resources
//@{

#include <NsCore/Package.h>
#include <NsCore/EnumConverter.h>
#include <NsGui/FreezableCollection.h>

#include "NoesisSDK/Src/Packages/App/Toolkit/Include/NsApp/ToolkitApi.h"

#include "NoesisSDK/Src/Packages/App/Toolkit/Include/NsApp/RadialNeedle.h"
#include "NoesisSDK/Src/Packages/App/Toolkit/Include/NsApp/RadialTicks.h"
#include "NoesisSDK/Src/Packages/App/Toolkit/Include/NsApp/RadialNumbers.h"
#include "NoesisSDK/Src/Packages/App/Toolkit/Include/NsApp/RadialBorder.h"
#include "NoesisSDK/Src/Packages/App/Toolkit/Include/NsApp/RadialGauge.h"

#include "NoesisSDK/Src/Packages/App/Toolkit/Include/NsApp/LayoutScaler.h"

#include "NoesisSDK/Src/Packages/App/Toolkit/Include/NsApp/Star.h"
#include "NoesisSDK/Src/Packages/App/Toolkit/Include/NsApp/RegularPolygon.h"
#include "NoesisSDK/Src/Packages/App/Toolkit/Include/NsApp/CornerBox.h"
#include "NoesisSDK/Src/Packages/App/Toolkit/Include/NsApp/Gear.h"

#include "NoesisSDK/Src/Packages/App/Toolkit/Include/NsApp/NineSliceImage.h"
#include "NoesisSDK/Src/Packages/App/Toolkit/Include/NsApp/GridImage.h"

#include "NoesisSDK/Src/Packages/App/Toolkit/Include/NsApp/TransitionContentPresenter.h"

#include "NoesisSDK/Src/Packages/App/Toolkit/Include/NsApp/DragDropExtensions.h"
#include "NoesisSDK/Src/Packages/App/Toolkit/Include/NsApp/NavigationExtensions.h"

#include "NoesisSDK/Src/Packages/App/Toolkit/Include/NsApp/MathConverter.h"
#include "NoesisSDK/Src/Packages/App/Toolkit/Include/NsApp/CaseConverter.h"
#include "NoesisSDK/Src/Packages/App/Toolkit/Include/NsApp/BoolInvertConverter.h"
#include "NoesisSDK/Src/Packages/App/Toolkit/Include/NsApp/NumberToThicknessConverter.h"

#if WITH_EDITOR
#include <NsGui/IntegrationAPI.h>
#include "NoesisSDK/Src/Packages/App/Providers/Include/NsApp/EmbeddedXamlProvider.h"
#include "NoesisSDK/Src/Packages/App/Providers/Include/NsApp/EmbeddedFontProvider.h"
#include "NoesisToolkit.generic.xaml.bin.h"
#include "NoesisToolkitIcons.ttf.bin.h"

namespace NoesisApp
{
    static EmbeddedXaml gToolkitXamls[] =
    {
        { "Toolkit.generic.xaml", Toolkit_generic_xaml },
    };

    static EmbeddedFont gToolkitFonts[] =
    {
        { "", ToolkitIcons_ttf },
    };
}
#endif

NS_BEGIN_COLD_REGION

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_REGISTER_REFLECTION(App, Toolkit)
{
    using namespace Noesis;
    using namespace NoesisApp;

    TypeOf<NoesisApp::DragDrop>();
    TypeOf<NoesisApp::Navigation>();

    NS_REGISTER_COMPONENT(RadialNeedle)
    NS_REGISTER_COMPONENT(RadialTicks)
    NS_REGISTER_COMPONENT(RadialNumbers)
    NS_REGISTER_COMPONENT(RadialBorder)
    NS_REGISTER_COMPONENT(RadialGauge)

    NS_REGISTER_COMPONENT(LayoutScaler)

    NS_REGISTER_COMPONENT(NoesisApp::Star)
    NS_REGISTER_COMPONENT(RegularPolygon)
    NS_REGISTER_COMPONENT(CornerBox)
    NS_REGISTER_COMPONENT(Gear)

    NS_REGISTER_COMPONENT(NineSliceImage)
    NS_REGISTER_COMPONENT(GridImage)

    NS_REGISTER_COMPONENT(TransitionContentPresenter)

    NS_REGISTER_COMPONENT(NavDestination)
    NS_REGISTER_COMPONENT(NavDestinationCollection)
    NS_REGISTER_COMPONENT(NavigateToAction)
    NS_REGISTER_COMPONENT(NavigateBackAction)

    NS_REGISTER_COMPONENT(MathConverter)
    NS_REGISTER_COMPONENT(CaseConverter)
    NS_REGISTER_COMPONENT(BoolInvertConverter)
    NS_REGISTER_COMPONENT(NumberToThicknessConverter)

    NS_REGISTER_COMPONENT(EnumConverter<CaseFormat>)
    NS_REGISTER_COMPONENT(EnumConverter<ThicknessFormat>)
    NS_REGISTER_COMPONENT(EnumConverter<DragDropRole>)
    NS_REGISTER_COMPONENT(EnumConverter<DragDropTransfer>)
    NS_REGISTER_COMPONENT(EnumConverter<TransferMouseButton>)

#if WITH_EDITOR
    GUI::SetAssemblyXamlProvider("Toolkit", MakePtr<EmbeddedXamlProvider>(gToolkitXamls));
    GUI::SetAssemblyFontProvider("Toolkit", MakePtr<EmbeddedFontProvider>(gToolkitFonts));
    GUI::RegisterDefaultStyles(Uri::Pack("Toolkit", "Toolkit.generic.xaml"));
#endif
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_INIT_PACKAGE(App, Toolkit)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_SHUTDOWN_PACKAGE(App, Toolkit)
{
}

NS_END_COLD_REGION

//@}

#include "NoesisSDK/Src/Packages/App/Toolkit/Src/RadialNeedle.cpp"
#include "NoesisSDK/Src/Packages/App/Toolkit/Src/RadialTicks.cpp"
#include "NoesisSDK/Src/Packages/App/Toolkit/Src/RadialNumbers.cpp"
#include "NoesisSDK/Src/Packages/App/Toolkit/Src/RadialBorder.cpp"
#include "NoesisSDK/Src/Packages/App/Toolkit/Src/RadialGauge.cpp"

#include "NoesisSDK/Src/Packages/App/Toolkit/Src/Star.cpp"
#include "NoesisSDK/Src/Packages/App/Toolkit/Src/RegularPolygon.cpp"
#include "NoesisSDK/Src/Packages/App/Toolkit/Src/CornerBox.cpp"
#include "NoesisSDK/Src/Packages/App/Toolkit/Src/Gear.cpp"

#include "NoesisSDK/Src/Packages/App/Toolkit/Src/LayoutScaler.cpp"

#include "NoesisSDK/Src/Packages/App/Toolkit/Src/NineSliceImage.cpp"
#include "NoesisSDK/Src/Packages/App/Toolkit/Src/GridImage.cpp"

#include "NoesisSDK/Src/Packages/App/Toolkit/Src/TransitionContentPresenter.cpp"

#include "NoesisSDK/Src/Packages/App/Toolkit/Src/DragDropExtensions.cpp"
#include "NoesisSDK/Src/Packages/App/Toolkit/Src/NavigationExtensions.cpp"

#include "NoesisSDK/Src/Packages/App/Toolkit/Src/ArithmeticParser.cpp"
#include "NoesisSDK/Src/Packages/App/Toolkit/Src/MathConverter.cpp"
#include "NoesisSDK/Src/Packages/App/Toolkit/Src/CaseConverter.cpp"
#include "NoesisSDK/Src/Packages/App/Toolkit/Src/BoolInvertConverter.cpp"
#include "NoesisSDK/Src/Packages/App/Toolkit/Src/NumberToThicknessConverter.cpp"

#if defined(_MSC_VER)
#pragma warning(pop)
#endif
