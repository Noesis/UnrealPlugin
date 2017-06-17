////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

using UnrealBuildTool;
using System;

public class NoesisGui : ModuleRules
{
	public NoesisGui(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.NoSharedPCHs;
		PrivatePCHHeaderFile = "Private/NoesisGuiPrivatePCH.h";

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
				"UMG"
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

		try
		{
			System.IO.File.Copy(ModuleDirectory + "/Shaders/NoesisGui.usf", ModuleDirectory + "/../../../../Shaders/NoesisGui.usf", true);
		}
		catch (Exception E)
		{
			System.Console.WriteLine(E.ToString());
		}
	}
}
