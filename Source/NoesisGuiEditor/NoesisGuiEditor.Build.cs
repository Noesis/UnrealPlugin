////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

using UnrealBuildTool;
using System;

public class NoesisGuiEditor : ModuleRules
{
	public NoesisGuiEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.NoSharedPCHs;
		PrivatePCHHeaderFile = "Private/NoesisGuiEditorPrivatePCH.h";

		PublicIncludePaths.AddRange(
			new string[] {
			}
			);

		PrivateIncludePaths.AddRange(
			new string[] {
				"NoesisGuiEditor/Private",
			}
			);

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"UnrealEd",
				"SlateCore",
			}
			);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Kismet",
				"KismetCompiler",
				"BlueprintGraph",
				"AssetRegistry",
				"Noesis",
				"NoesisGui",
				"FreeType2",
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
			}
			);
	}
}
