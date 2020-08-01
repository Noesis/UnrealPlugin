////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

using UnrealBuildTool;
using System;
using System.IO;
using Tools.DotNETCommon;

public class Noesis : ModuleRules
{
	public Noesis(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;

		string NoesisBasePath = ModuleDirectory + "/NoesisSDK/";
		string NoesisIncludePath = NoesisBasePath + "Include/";
		string NoesisInteractivityIncludePath = NoesisBasePath + "Src/Packages/App/Interactivity/Include/";

		PublicIncludePaths.Add(ModuleDirectory);
		PublicIncludePaths.Add(NoesisIncludePath);
		PublicIncludePaths.Add(NoesisInteractivityIncludePath);

		if (!Directory.Exists(NoesisBasePath))
		{
			throw new BuildException("Could not find NoesisGUI SDK in " + NoesisBasePath + ".");
		}

		if (!Directory.Exists(NoesisBasePath + "Include"))
		{
			throw new BuildException("Could not find NoesisGUI SDK Include directory in " + NoesisBasePath + "Include.");
		}

		PublicSystemIncludePaths.Add(NoesisIncludePath);

		UnrealTargetPlatform Platform;
		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			PublicAdditionalLibraries.Add(NoesisBasePath + "Lib/windows_x86_64/Noesis.lib");

			string NoesisDllPath = "/NoesisSDK/Bin/windows_x86_64/Noesis.dll";
			string NoesisDllTargetPath = "/Binaries/Win64/Noesis.dll";

			if (Target.ProjectFile != null)
			{
				System.Console.WriteLine("Copying Noesis.dll to {0}", DirectoryReference.FromFile(Target.ProjectFile).ToString() + NoesisDllTargetPath);
				CopyNoesisDll(ModuleDirectory + NoesisDllPath, DirectoryReference.FromFile(Target.ProjectFile).ToString() + NoesisDllTargetPath);
			}

			System.Console.WriteLine("Copying Noesis.dll to {0}", System.IO.Path.GetFullPath(ModuleDirectory + "/../.." + NoesisDllTargetPath));
			CopyNoesisDll(ModuleDirectory + NoesisDllPath, ModuleDirectory + "/../.." + NoesisDllTargetPath);

			if (System.IO.File.Exists(Target.RelativeEnginePath + NoesisDllTargetPath))
			{
				System.IO.File.Delete(Target.RelativeEnginePath + NoesisDllTargetPath);
			}

			if (Target.LinkType == TargetLinkType.Monolithic)
			{
				RuntimeDependencies.Add("$(ProjectDir)" + NoesisDllTargetPath);
			}
			else
			{
				RuntimeDependencies.Add("$(EngineDir)" + NoesisDllTargetPath);
			}
		}
		else if (Target.Platform == UnrealTargetPlatform.Linux)
		{
			PublicAdditionalLibraries.Add(NoesisBasePath + "Bin/linunx_x86_64/libNoesis.so");
		}
		else if (Target.Platform == UnrealTargetPlatform.Mac)
		{
			PublicAdditionalLibraries.Add(NoesisBasePath + "Bin/macos/Noesis.dylib");

			string NoesisDylibPath = "/NoesisSDK/Bin/macos/Noesis.dylib";
			RuntimeDependencies.Add(ModuleDirectory + NoesisDylibPath);
		}
		else if (Target.Platform == UnrealTargetPlatform.IOS)
		{
			PublicAdditionalLibraries.Add(NoesisBasePath + "Lib/ios/libNoesis.a");

			PublicFrameworks.Add("CoreText");
		}
		else if (Target.Platform == UnrealTargetPlatform.Android)
		{
			PublicAdditionalLibraries.Add(NoesisBasePath + "Bin/android_arm/libNoesis.so");
			PublicAdditionalLibraries.Add(NoesisBasePath + "Bin/android_arm64/libNoesis.so");
			PublicAdditionalLibraries.Add(NoesisBasePath + "Bin/android_x86/libNoesis.so");
			PublicAdditionalLibraries.Add(NoesisBasePath + "Bin/android_x86_64/libNoesis.so");

			string NoesisAplPath = "/Noesis_APL.xml";
			AdditionalPropertiesForReceipt.Add("AndroidPlugin", ModuleDirectory + NoesisAplPath);
		}
		else if (Target.Platform == UnrealTargetPlatform.PS4)
		{
			PublicAdditionalLibraries.Add(NoesisBasePath + "Lib/ps4/Noesis.a");
		}
		else if (Target.Platform == UnrealTargetPlatform.XboxOne)
		{
			PublicAdditionalLibraries.Add(NoesisBasePath + "Bin/xbox_one/Noesis.lib");
		}
		else if (UnrealTargetPlatform.TryParse("HTML5", out Platform) && Target.Platform == Platform)
		{
			PublicAdditionalLibraries.Add(NoesisBasePath + "Bin/wasm/Noesis.bc");
		}
	}

	private void CopyNoesisDll(string Source, string Target)
	{
		try
		{
			string TargetDirectory = System.IO.Path.GetDirectoryName(Target);
			if (!System.IO.Directory.Exists(TargetDirectory))
			{
				System.IO.Directory.CreateDirectory(TargetDirectory);
			}
			System.IO.File.Copy(Source, Target, true);
		}
		catch (IOException Exception)
		{
			if (Exception.HResult != -2147024864) // 0x80070020: The process cannot access the file ... because it is being used by another process.
			{
				throw;
			}
		}
	}
}
