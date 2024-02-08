////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

using UnrealBuildTool;
using System;
using System.IO;

public class Noesis : ModuleRules
{
	public Noesis(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;

		string NoesisBasePath = Path.Combine(ModuleDirectory, "NoesisSDK");
		string NoesisIncludePath = Path.Combine(NoesisBasePath, "Include");
		string NoesisInteractivityIncludePath = Path.Combine(NoesisBasePath, "Src", "Packages", "App", "Interactivity", "Include");
		string NoesisMediaElementIncludePath = Path.Combine(NoesisBasePath, "Src", "Packages", "App", "MediaElement", "Include");
		string NoesisRiveBaseIncludePath = Path.Combine(NoesisBasePath, "Src", "Packages", "App", "RiveBase", "Include");
		string NoesisRiveIncludePath = Path.Combine(NoesisBasePath, "Src", "Packages", "App", "Rive", "Include");
		string RiveIncludePath = Path.Combine(NoesisBasePath, "Src", "Packages", "App", "RiveBase", "Src", "rive", "include");
		string RiveSheenBidiIncludePath = Path.Combine(NoesisBasePath, "Src", "Packages", "App", "RiveBase", "Src", "SheenBidi", "Headers");

		// In monolithic builds we don't want the Interactivity and MediaElement functions
		// dllexported or dllimported from any modules.
		// That's why we use PublicDefinitions.
		if (Target.LinkType == TargetLinkType.Monolithic)
		{
			PublicDefinitions.Add("NS_APP_INTERACTIVITY_API=");
			PublicDefinitions.Add("NS_APP_MEDIAELEMENT_API=");
			PublicDefinitions.Add("NS_APP_RIVEBASE_API=");
			PublicDefinitions.Add("NS_APP_RIVE_API=");
			if (Target.Type == TargetType.Editor)
			{
				PublicDefinitions.Add("NS_APP_LANGSERVER_API=");
				PublicDefinitions.Add("NS_APP_PROVIDERS_API=");
			}
		}

		PublicIncludePaths.Add(ModuleDirectory);
		PublicIncludePaths.Add(NoesisIncludePath);
		PublicIncludePaths.Add(NoesisInteractivityIncludePath);
		PublicIncludePaths.Add(NoesisMediaElementIncludePath);
		PublicIncludePaths.Add(NoesisRiveBaseIncludePath);
		PublicIncludePaths.Add(NoesisRiveIncludePath);
		PublicIncludePaths.Add(RiveIncludePath);
		PublicIncludePaths.Add(RiveSheenBidiIncludePath);

		if (Target.Type == TargetType.Editor)
		{
			PublicIncludePaths.Add(Path.Combine(NoesisBasePath, "Src", "Packages", "App", "LangServer", "Include"));
		}

		if (!Directory.Exists(NoesisBasePath))
		{
			throw new BuildException("Could not find NoesisGUI SDK in " + NoesisBasePath + ".");
		}

		if (!Directory.Exists(NoesisIncludePath))
		{
			throw new BuildException("Could not find NoesisGUI SDK Include directory in " + NoesisIncludePath);
		}

		PublicSystemIncludePaths.Add(NoesisIncludePath);

		UnrealTargetPlatform Platform;
		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			PublicAdditionalLibraries.Add(Path.Combine(NoesisBasePath, "Lib", "windows_x86_64", "Noesis.lib"));

			string NoesisDllPath = Path.Combine(NoesisBasePath, "Bin", "windows_x86_64", "Noesis.dll");
			string NoesisDllTargetPath = Path.Combine("$(BinaryOutputDir)", "Noesis.dll");

			RuntimeDependencies.Add(NoesisDllTargetPath, NoesisDllPath, StagedFileType.NonUFS);
		}
		else if (Target.Platform == UnrealTargetPlatform.Linux)
		{
			PublicAdditionalLibraries.Add(Path.Combine(NoesisBasePath, "Bin", "linux_x86_64", "libNoesis.so"));

			string NoesisSoPath = Path.Combine("NoesisSDK", "Bin", "linux_x86_64", "libNoesis.so");
			RuntimeDependencies.Add(Path.Combine(ModuleDirectory, NoesisSoPath));
		}
		else if (Target.Platform == UnrealTargetPlatform.Mac)
		{
			PublicAdditionalLibraries.Add(Path.Combine(NoesisBasePath, "Bin", "macos", "Noesis.dylib"));

			string NoesisDylibPath = Path.Combine("NoesisSDK", "Bin", "macos", "Noesis.dylib");
			RuntimeDependencies.Add(Path.Combine(ModuleDirectory, NoesisDylibPath));
		}
		else if (Target.Platform == UnrealTargetPlatform.IOS)
		{
			PublicDefinitions.Add("NS_STATIC_LIBRARY");
			PublicAdditionalLibraries.Add(Path.Combine(NoesisBasePath, "Lib", "ios", "libNoesis.a"));

			PublicFrameworks.Add("CoreText");
		}
		else if (Target.Platform == UnrealTargetPlatform.Android)
		{
			AddAndroidLibrary(NoesisBasePath, "android_arm", "armeabi-v7a");
			AddAndroidLibrary(NoesisBasePath, "android_arm64", "arm64-v8a");
			AddAndroidLibrary(NoesisBasePath, "android_x86", "x86");
			AddAndroidLibrary(NoesisBasePath, "android_x86_64", "x86_64");

			string NoesisAplPath = "Noesis_APL.xml";
			AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(ModuleDirectory, NoesisAplPath));
		}
		else if (UnrealTargetPlatform.TryParse("HTML5", out Platform) && Target.Platform == Platform)
		{
			PublicAdditionalLibraries.Add(Path.Combine(NoesisBasePath, "Bin", "wasm", "Noesis.bc"));
		}
		else if (UnrealTargetPlatform.TryParse("XboxOneGDK", out Platform) && Target.Platform == Platform)
		{
			PublicAdditionalLibraries.Add(Path.Combine(NoesisBasePath, "Lib", "xbox_one", "Noesis.lib"));

			string NoesisDllPath = Path.Combine(NoesisBasePath, "Bin", "xbox_one", "Noesis.dll");
			string NoesisDllTargetPath = Path.Combine("$(BinaryOutputDir)", "Noesis.dll");

			RuntimeDependencies.Add(NoesisDllTargetPath, NoesisDllPath, StagedFileType.NonUFS);
		}
		else if (UnrealTargetPlatform.TryParse("XSX", out Platform) && Target.Platform == Platform)
		{
			PublicAdditionalLibraries.Add(Path.Combine(NoesisBasePath, "Lib", "xbox_series", "Noesis.lib"));

			string NoesisDllPath = Path.Combine(NoesisBasePath, "Bin", "xbox_series", "Noesis.dll");
			string NoesisDllTargetPath = Path.Combine("$(BinaryOutputDir)", "Noesis.dll");

			RuntimeDependencies.Add(NoesisDllTargetPath, NoesisDllPath, StagedFileType.NonUFS);
		}
		else if (UnrealTargetPlatform.TryParse("PS4", out Platform) && Target.Platform == Platform)
		{
			PublicDefinitions.Add("NS_STATIC_LIBRARY");
			PublicAdditionalLibraries.Add(Path.Combine(NoesisBasePath, "Lib", "ps4", "Noesis.a"));
		}
		else if (UnrealTargetPlatform.TryParse("PS5", out Platform) && Target.Platform == Platform)
		{
			PublicDefinitions.Add("NS_STATIC_LIBRARY");
			PublicAdditionalLibraries.Add(Path.Combine(NoesisBasePath, "Lib", "ps5", "Noesis.a"));
		}
		else if (UnrealTargetPlatform.TryParse("Switch", out Platform) && Target.Platform == Platform)
		{
			PublicDefinitions.Add("NS_STATIC_LIBRARY");
			PublicAdditionalLibraries.Add(Path.Combine(NoesisBasePath, "Lib", "nx", "Noesis.a"));
		}
	}

	private void AddAndroidLibrary(string pluginPath, string src, string arch)
	{
		string libDir = Path.Combine(pluginPath, "Bin", "android", arch);
		if (!Directory.Exists(libDir))
		{
			System.Console.WriteLine("[" + arch + "]");
			System.Console.WriteLine("  Library not found!");
			string srcDir = Path.Combine(pluginPath, "Bin", src);
			if (Directory.Exists(srcDir))
			{
				System.Console.WriteLine("  Moving from SDK '" + srcDir + "' to '" + libDir + "'");
				Directory.CreateDirectory(libDir);
				Directory.Delete(libDir);
				Directory.Move(srcDir, libDir);
			}
			else
			{
				System.Console.WriteLine("  SDK library '" + srcDir + "'  not found");
			}
		}

		PublicAdditionalLibraries.Add(Path.Combine(libDir, "libNoesis.so"));
	}
}
