////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4426)
#endif

// Include just embedded providers from App/Providers package
//@{

#if WITH_EDITOR
#include "NoesisSDK/Src/Packages/App/Providers/Src/EmbeddedXamlProvider.cpp"
#include "NoesisSDK/Src/Packages/App/Providers/Src/EmbeddedFontProvider.cpp"
#endif

//@}

#if defined(_MSC_VER)
#pragma warning(pop)
#endif
