////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

using UnrealBuildTool;

public class NoesisGui : ModuleRules
{
	public NoesisGui(TargetInfo Target)
	{
		PCHUsage = PCHUsageMode.NoSharedPCHs;

		PublicIncludePaths.AddRange(
			new string[] {
			}
			);

		PrivateIncludePaths.AddRange(
			new string[] {
				"NoesisGui/Private",
			}
			);

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"RHI",
				"RenderCore",
				"ShaderCore",
				"SlateCore",
				"InputCore",
			}
			);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Noesis",
			}
			);

		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
			}
			);

		System.IO.File.Copy(ModuleDirectory + "/Shaders/NoesisGui.usf", ModuleDirectory + "/../../../../Shaders/NoesisGui.usf", true);
	}
}
