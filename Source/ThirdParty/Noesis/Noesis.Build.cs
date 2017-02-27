////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

using UnrealBuildTool;
using System;

public class Noesis : ModuleRules
{
	public Noesis(TargetInfo Target)
	{
		Type = ModuleType.External;

		string NoesisBasePath = ModuleDirectory + "/NoesisGUI-SDK1.3/";
		string NoesisIncludePath = NoesisBasePath + "Include/";

		PublicSystemIncludePaths.Add(NoesisIncludePath);

		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			string NoesisLibPath = NoesisBasePath + "Lib/windows_x86_64/";
			PublicLibraryPaths.Add(NoesisLibPath);
			PublicAdditionalLibraries.Add("Noesis.lib");

			string NoesisDllPath = "Binaries/ThirdParty/Noesis/windows_x86_64/Noesis.dll";
			PublicDelayLoadDLLs.Add("Noesis.dll");
			RuntimeDependencies.Add(new RuntimeDependency("$(EngineDir)/" + NoesisDllPath));

			Definitions.Add("NOESISGUI_DLL_PATH=\"" + NoesisDllPath + "\"");

			try
			{
				System.IO.Directory.CreateDirectory(UEBuildConfiguration.UEThirdPartyBinariesDirectory + "Noesis/windows_x86_64");
				System.IO.File.Copy(NoesisBasePath + "Bin/windows_x86_64/Noesis.dll", UEBuildConfiguration.UEThirdPartyBinariesDirectory + "Noesis/windows_x86_64/Noesis.dll", true);
			}
			catch (Exception)
			{
			}
		}
	}
}
