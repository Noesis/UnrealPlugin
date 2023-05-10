////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

using UnrealBuildTool;
using EpicGames.Core;
using System;

public class NoesisRuntime : ModuleRules
{
	public NoesisRuntime(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.NoSharedPCHs;
		PrivatePCHHeaderFile = "Private/NoesisRuntimePrivatePCH.h";

		// In modular builds we want the Interactivity and MediaElement functions
		// dllexported from this module and
		// dllimported from the other modules.
		// That's why we use PrivateDefinitions.
		if (Target.LinkType == TargetLinkType.Modular)
		{
			PrivateDefinitions.Add("NS_APP_INTERACTIVITY_API=NS_DLL_EXPORT");
			PrivateDefinitions.Add("NS_APP_MEDIAELEMENT_API=NS_DLL_EXPORT");
			PrivateDefinitions.Add("NS_APP_RIVEBASE_API=NS_DLL_EXPORT");
			PrivateDefinitions.Add("NS_APP_RIVE_API=NS_DLL_EXPORT");
			if (Target.Type == TargetType.Editor)
			{
				// In modular builds we want the LangServer functions
				// dllexported from this module and
				// dllimported from the other modules.
				// That's why we use PrivateDefinitions.
				PrivateDefinitions.Add("NS_APP_LANGSERVER_API=NS_DLL_EXPORT");
				PrivateDefinitions.Add("NS_APP_PROVIDERS_API=NS_DLL_EXPORT");
			}
		}

		PublicIncludePaths.AddRange(
			new string[] {
			}
			);

		PrivateIncludePaths.AddRange(
			new string[] {
				"NoesisRuntime/Private",
				EngineDirectory + "/Source/Runtime/Renderer/Private",
			}
			);

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"MediaAssets",
				"AudioMixer",
				"RHI",
				"RenderCore",
				"SlateCore",
				"InputCore",
				"UMG",
				"ApplicationCore",
				"Slate",
				"Projects",
				"zlib",
				"UElibPNG",
				"Renderer",
				"NetCore",
				"Noesis"
			}
			);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
			}
			);

		if (Target.bBuildEditor == true)
		{
			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"UnrealEd"
				}
				);
		}

		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				"AssetRegistry"
			}
			);

		var Project = Target.ProjectFile != null ? ProjectDescriptor.FromFile(Target.ProjectFile) : null;
		var AvailablePlugins = Plugins.ReadAvailablePlugins(new DirectoryReference(EngineDirectory), Target.ProjectFile?.Directory, null);

		Func<string, bool> IsPluginEnabled = (string Name) =>
		{
			var PluginInfo = AvailablePlugins.Find(pPluginInfo => { return pPluginInfo.Name == Name; });
			return PluginInfo != null ? Plugins.IsPluginEnabledForTarget(PluginInfo, Project, Target.Platform, Target.Configuration, Target.Type) : false;
		};

		bool WithEnhancedInput = true;
		if (WithEnhancedInput)
		{
			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"EnhancedInput"
				}
				);
			PublicDefinitions.Add("WITH_ENHANCED_INPUT=1");
		}
		else
		{
			PublicDefinitions.Add("WITH_ENHANCED_INPUT=0");
		}

		bool WithCommonUI = IsPluginEnabled("CommonUI");
		if (WithCommonUI)
		{
			System.Console.WriteLine("NoesisGUI: It looks like your project is using the CommonUI plugin. The warning below is harmless but, if you want to get rid of it, you can edit NoesisGUI.uplugin and change the CommonUI plugin dependency to be enabled.");
			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"CommonInput"
				}
				);
			PublicDefinitions.Add("WITH_COMMON_UI=1");
		}
		else
		{
			PublicDefinitions.Add("WITH_COMMON_UI=0");
		}
	}
}
