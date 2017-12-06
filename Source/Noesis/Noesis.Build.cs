////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

using UnrealBuildTool;
using System;

public class Noesis : ModuleRules
{
	public Noesis(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;

		string NoesisSdkDirectory = "/NoesisSDK/";
		string NoesisBasePath = ModuleDirectory + NoesisSdkDirectory;
		string NoesisIncludePath = NoesisBasePath + "Include/";

		PublicSystemIncludePaths.Add(NoesisIncludePath);

		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			string NoesisLibPath = NoesisBasePath + "Lib/windows_x86_64/";
			PublicLibraryPaths.Add(NoesisLibPath);
			PublicAdditionalLibraries.Add("Noesis.lib");

			string NoesisDllPath = "Plugins/NoesisGui/Source/Noesis" + NoesisSdkDirectory + "Bin/windows_x86_64/Noesis.dll";
			RuntimeDependencies.Add(new RuntimeDependency("$(EngineDir)/" + NoesisDllPath));

			Definitions.Add("NOESISGUI_DLL_PATH=\"" + NoesisDllPath + "\"");

			PublicDelayLoadDLLs.Add("Noesis.dll");
		}
		else if (Target.Platform == UnrealTargetPlatform.Mac)
		{
			string NoesisLibPath = NoesisBasePath + "Bin/osx/";
			PublicAdditionalLibraries.Add(NoesisLibPath + "Noesis.dylib");
		}
	}
}
