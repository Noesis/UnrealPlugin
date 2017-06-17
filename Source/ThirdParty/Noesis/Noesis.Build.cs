////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

using UnrealBuildTool;
using System;

public class Noesis : ModuleRules
{
	public Noesis(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;

		string NoesisBasePath = ModuleDirectory + "/NoesisGUI-NativeSDK-2.0.2f2/";
		string NoesisIncludePath = NoesisBasePath + "Include/";

		PublicSystemIncludePaths.Add(NoesisIncludePath);

		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			string NoesisLibPath = NoesisBasePath + "Lib/windows_x86_64/";
			PublicLibraryPaths.Add(NoesisLibPath);
			PublicAdditionalLibraries.Add("Noesis.lib");

			string NoesisDllPath = "Binaries/Win64/Noesis.dll";
			RuntimeDependencies.Add(new RuntimeDependency("$(EngineDir)/" + NoesisDllPath));

			Definitions.Add("NOESISGUI_DLL_PATH=\"" + NoesisDllPath + "\"");

			try
			{
				System.IO.File.Copy(NoesisBasePath + "Bin/windows_x86_64/Noesis.dll", BuildConfiguration.RelativeEnginePath + NoesisDllPath, true);
			}
			catch (Exception E)
			{
				System.Console.WriteLine(E.ToString());
			}
		}
	}
}
