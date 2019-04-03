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

		// Let's try to make sure the right version of the SDK is in the right place.
		const string RequiredRevision = "(r7995)";
		const string RequiredVersionName = "2.2.1";

		PublicDefinitions.Add("NOESIS_VERSION_NAME=\"" + RequiredVersionName + "\"");
		if (!Directory.Exists(NoesisBasePath))
		{
			throw new BuildException("Could not find NoesisGUI SDK in " + NoesisBasePath + ". Minimum required version is " + RequiredVersionName);
		}

		if (!Directory.Exists(NoesisBasePath + "Bin"))
		{
			throw new BuildException("Could not find NoesisGUI SDK Bin directory in " + NoesisBasePath + "Bin. Minimum required version is " + RequiredVersionName);
		}

		if (!Directory.Exists(NoesisBasePath + "Include"))
		{
			throw new BuildException("Could not find NoesisGUI SDK Include directory in " + NoesisBasePath + "Include. Minimum required version is " + RequiredVersionName);
		}

		if (!Directory.Exists(NoesisBasePath + "Lib"))
		{
			throw new BuildException("Could not find NoesisGUI SDK Lib directory in " + NoesisBasePath + "Lib. Minimum required version is " + RequiredVersionName);
		}

		string NoesisSdkVersionInfo;
		try
		{
			NoesisSdkVersionInfo = File.ReadAllText(NoesisBasePath + "version.txt");
		}
		catch (Exception)
		{
			throw new BuildException("Could not find NoesisGUI SDK version.txt in " + NoesisBasePath + "version.txt. Minimum required version is " + RequiredVersionName);
		}

		string[] SplitVersion = NoesisSdkVersionInfo.Split(' ');
		if (String.Compare(SplitVersion[SplitVersion.Length - 1], RequiredRevision) < 0)
		{
			throw new BuildException("Wrong version of the NoesisGUI SDK installed in " + NoesisBasePath + ". Minimum required version is " + RequiredVersionName);
		}

		PublicSystemIncludePaths.Add(NoesisIncludePath);

		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			string NoesisLibPath = NoesisBasePath + "Lib/windows_x86_64/";
			PublicLibraryPaths.Add(NoesisLibPath);
			PublicAdditionalLibraries.Add("Noesis.lib");

			string NoesisDllPath = "/NoesisSDK/Bin/windows_x86_64/Noesis.dll";
			string NoesisDllTargetPath = "/Binaries/Win64/Noesis.dll";

			if (Target.ProjectFile != null)
			{
				CopyNoesisDll(ModuleDirectory + NoesisDllPath, DirectoryReference.FromFile(Target.ProjectFile).ToString() + NoesisDllTargetPath);
			}

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
		else if (Target.Platform == UnrealTargetPlatform.Mac)
		{
			string NoesisLibPath = NoesisBasePath + "Bin/osx/";
			PublicLibraryPaths.Add(NoesisLibPath);
			PublicAdditionalLibraries.Add(NoesisLibPath + "Noesis.dylib");

			string NoesisDylibPath = "/NoesisSDK/Bin/osx/Noesis.dylib";
			RuntimeDependencies.Add(ModuleDirectory + NoesisDylibPath);
		}
		else if (Target.Platform == UnrealTargetPlatform.IOS)
		{
			string NoesisLibPath = NoesisBasePath + "Lib/ios/";
			PublicLibraryPaths.Add(NoesisLibPath);
			PublicAdditionalLibraries.Add("Noesis");

			PublicAdditionalShadowFiles.Add(Path.Combine(NoesisLibPath, "libNoesis.a"));
		}
		else if (Target.Platform == UnrealTargetPlatform.Android)
		{
			string NoesisLibPath = NoesisBasePath + "Bin/android_arm/";
			PublicLibraryPaths.Add(NoesisLibPath);
			string NoesisLib64Path = NoesisBasePath + "Bin/android_arm64/";
			PublicLibraryPaths.Add(NoesisLib64Path);
			PublicAdditionalLibraries.Add("Noesis");

			string NoesisAplPath = "/Noesis_APL.xml";
			AdditionalPropertiesForReceipt.Add("AndroidPlugin", ModuleDirectory + NoesisAplPath);
		}
		else if (Target.Platform == UnrealTargetPlatform.PS4)
		{
			string NoesisLibPath = NoesisBasePath + "Lib/ps4/";
			PublicAdditionalLibraries.Add(NoesisLibPath + "Noesis.a");
		}
		else if (Target.Platform == UnrealTargetPlatform.XboxOne)
		{
			string NoesisLibPath = NoesisBasePath + "Bin/xbox_one/";
			PublicLibraryPaths.Add(NoesisLibPath);
			PublicAdditionalLibraries.Add("Noesis.lib");
		}
		else if (Target.Platform == UnrealTargetPlatform.HTML5)
		{
			string NoesisLibPath = NoesisBasePath + "Bin/wasm/";
			PublicAdditionalLibraries.Add(NoesisLibPath + "Noesis.bc");
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
