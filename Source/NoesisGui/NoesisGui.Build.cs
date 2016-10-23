////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

using System;
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

        string ShaderFileName = "NoesisGui.usf";
        string ShaderPluginFolder = ModuleDirectory + "\\Shaders\\";
        string ShaderProjectRootFolder = ModuleDirectory + "\\..\\..\\..\\..\\Shaders\\";

        if (System.IO.File.Exists(ShaderPluginFolder + ShaderFileName))
        {
            Console.WriteLine("Found: " + ShaderPluginFolder + ShaderFileName);
            if (!System.IO.Directory.Exists(ShaderProjectRootFolder))
            {
                System.IO.Directory.CreateDirectory(ShaderProjectRootFolder);
            }

            System.IO.File.Copy(ShaderPluginFolder + ShaderFileName, ShaderProjectRootFolder + ShaderFileName, true);

            Console.WriteLine("Copied NoesisGui shader to ProjectRootDirectory/Shaders/ folder.");
        }
        else
        {
            Console.WriteLine("Not Found: " + ShaderPluginFolder + ShaderFileName);
        }
    }
}