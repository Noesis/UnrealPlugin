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

		string NoesisBasePath = Path.Combine(ModuleDirectory, "NoesisSDK");
		string NoesisIncludePath = Path.Combine(NoesisBasePath, "Include");
		string NoesisInteractivityIncludePath = Path.Combine(NoesisBasePath, "Src", "Packages", "App", "Interactivity", "Include");

		// In monolithic builds we don't want the Interactivity functions
		// dllexported or dllimported from any modules.
		// That's why we use PublicDefinitions.
		if (Target.LinkType == TargetLinkType.Monolithic)
		{
			PublicDefinitions.Add("NS_APP_INTERACTIVITY_API=");
		}

		PublicIncludePaths.Add(ModuleDirectory);
		PublicIncludePaths.Add(NoesisIncludePath);
		PublicIncludePaths.Add(NoesisInteractivityIncludePath);

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

			string NoesisDllPath = Path.Combine("NoesisSDK", "Bin", "windows_x86_64", "Noesis.dll");
			string NoesisDllTargetPath = Path.Combine("Binaries", "Win64", "Noesis.dll");

			if (Target.ProjectFile != null)
			{
				System.Console.WriteLine("Copying Noesis.dll to {0}", Path.Combine(DirectoryReference.FromFile(Target.ProjectFile).ToString(), NoesisDllTargetPath));
				CopyNoesisDll(Path.Combine(ModuleDirectory, NoesisDllPath), Path.Combine(DirectoryReference.FromFile(Target.ProjectFile).ToString(), NoesisDllTargetPath));
			}

			System.Console.WriteLine("Copying Noesis.dll to {0}", System.IO.Path.GetFullPath(Path.Combine(ModuleDirectory, "..", "..", NoesisDllTargetPath)));
			CopyNoesisDll(Path.Combine(ModuleDirectory, NoesisDllPath), Path.Combine(ModuleDirectory, "..", "..", NoesisDllTargetPath));

			if (System.IO.File.Exists(Path.Combine(Target.RelativeEnginePath, NoesisDllTargetPath)))
			{
				System.Console.WriteLine("Deleting Noesis.dll from {0}", Path.Combine(Target.RelativeEnginePath, NoesisDllTargetPath));
				System.IO.File.Delete(Path.Combine(Target.RelativeEnginePath, NoesisDllTargetPath));
			}

			if (Target.LinkType == TargetLinkType.Monolithic)
			{
				RuntimeDependencies.Add(Path.Combine("$(ProjectDir)", NoesisDllTargetPath));
			}
			else
			{
				RuntimeDependencies.Add(Path.Combine("$(EngineDir)", NoesisDllTargetPath));
			}
		}
		else if (Target.Platform == UnrealTargetPlatform.Linux)
		{
			PublicAdditionalLibraries.Add(Path.Combine(NoesisBasePath, "Bin", "linunx_x86_64", "libNoesis.so"));
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
			PublicAdditionalLibraries.Add(Path.Combine(NoesisBasePath, "Bin", "android_arm", "libNoesis.so"));
			PublicAdditionalLibraries.Add(Path.Combine(NoesisBasePath, "Bin", "android_arm64", "libNoesis.so"));
			PublicAdditionalLibraries.Add(Path.Combine(NoesisBasePath, "Bin", "android_x86", "libNoesis.so"));
			PublicAdditionalLibraries.Add(Path.Combine(NoesisBasePath, "Bin", "android_x86_64", "libNoesis.so"));

			string NoesisAplPath = "Noesis_APL.xml";
			AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(ModuleDirectory, NoesisAplPath));
		}
		else if (Target.Platform == UnrealTargetPlatform.PS4)
		{
			PublicDefinitions.Add("NS_STATIC_LIBRARY");
			PublicAdditionalLibraries.Add(Path.Combine(NoesisBasePath, "Lib", "ps4", "Noesis.a"));
		}
		else if (Target.Platform == UnrealTargetPlatform.XboxOne)
		{
			PublicAdditionalLibraries.Add(Path.Combine(NoesisBasePath, "Lib", "xbox_one", "Noesis.lib"));

			string NoesisDllPath = Path.Combine("NoesisSDK", "Bin", "xbox_one", "Noesis.dll");
			string NoesisDllTargetPath = Path.Combine("Binaries", "XboxOne", "Noesis.dll");

			if (Target.ProjectFile != null)
			{
				System.Console.WriteLine("Copying Noesis.dll to {0}", Path.Combine(DirectoryReference.FromFile(Target.ProjectFile).ToString(), NoesisDllTargetPath));
				CopyNoesisDll(Path.Combine(ModuleDirectory, NoesisDllPath), Path.Combine(DirectoryReference.FromFile(Target.ProjectFile).ToString(), NoesisDllTargetPath));
			}

			if (Target.LinkType == TargetLinkType.Monolithic)
			{
				RuntimeDependencies.Add(Path.Combine("$(ProjectDir)", NoesisDllTargetPath));
			}
			else
			{
				RuntimeDependencies.Add(Path.Combine("$(EngineDir)", NoesisDllTargetPath));
			}
		}
		else if (UnrealTargetPlatform.TryParse("HTML5", out Platform) && Target.Platform == Platform)
		{
			PublicAdditionalLibraries.Add(Path.Combine(NoesisBasePath, "Bin", "wasm", "Noesis.bc"));
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
