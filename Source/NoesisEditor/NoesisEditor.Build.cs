////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

using UnrealBuildTool;
using System;

public class NoesisEditor : ModuleRules
{
	public NoesisEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.NoSharedPCHs;
		PrivatePCHHeaderFile = "Private/NoesisEditorPrivatePCH.h";

		PublicIncludePaths.AddRange(
			new string[] {
			}
			);

		PrivateIncludePaths.AddRange(
			new string[] {
				"NoesisEditor/Private",
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
				"UnrealEd",
				"SlateCore",
			}
			);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Kismet",
				"EditorStyle",
				"KismetCompiler",
				"BlueprintGraph",
				"AssetRegistry",
				"Noesis",
				"NoesisRuntime",
				"RHI",
				"RenderCore",
				"Projects",
				"Slate",
				"ToolMenus",
				"UMG",
				"LevelEditor",
				"WorkspaceMenuStructure",
				"InputCore"
			}
			);

		PrivateIncludePathModuleNames.AddRange(
			new string[]
			{
				"AssetTools",
			}
			);

		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				"AssetTools",
				"Settings"
			}
			);
	}
}
