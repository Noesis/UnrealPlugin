<a href="https://www.noesisengine.com"><img alt="website" src="https://img.shields.io/badge/site-noesisengine.com-blue.svg"></a>
<a href="https://www.noesisengine.com/docs/Gui.Core.Index.html"><img alt="documentation" src="https://img.shields.io/badge/doc-index-blue.svg"></a>
<a href="https://www.noesisengine.com/bugs/"><img alt="issues" src="https://img.shields.io/badge/issues-bugtracker-blue"></a>
<a href="https://twitter.com/NoesisEngine"><img src="https://img.shields.io/badge/twitter-%40NoesisEngine-55acee.svg?style=flat-square"></a>

# NoesisGUI Unreal Engine Plugin

This repository contains the source code for the [NoesisGUI](https://www.noesisengine.com/) Unreal integration.

> This is just a short guide on how to install and build the plugin from the source code on this repository. For your convenience, you can download a ready to use version of the plugin directly from [our website](https://www.noesisengine.com/developers/downloads.php). If you do so, you can skip the installation instructions and jump directly to our [First steps with NoesisGUI and Unreal](https://www.noesisengine.com/docs/Gui.Core.UnrealTutorial.html).

Please, use our [forums](https://forums.noesisengine.com) and [tracker](https://bugs.noesisengine.com) to submit bugs and feature requests.

### Prerequisites

1. Unreal Engine, with source code. This can be either a pre-built version installed through the Epic Games Launcher, or a version built by yourself from the source in GitHub. To install a pre-built version of Unreal Engine, please refer to the document [Installing Unreal Engine](https://docs.unrealengine.com/latest/INT/GettingStarted/Installation/index.html) and follow the instructions there. For instructions on how to get a copy of the Unreal Engine source code and how to build it, please refer to the README.md document on their [GitHub repository](https://github.com/EpicGames/UnrealEngine). If you're using a version of Unreal Engine installed trough the Epic Games Launcher, make sure you have the engine source code installed. To verify you do, go to the Unreal Engine tab in the Epic Games Launcher, then go to your library of installed components. From there, at the top, look for the Unreal Engine version with which you wish to use NoesisGUI, and from the drop down list next to the Launch button, select options. Make sure the Engine Source option is selected. If it isn't, click on the tick box next to it and then click Apply to download it.

![Installed Engine version options](https://noesis.github.io/NoesisGUI/UE4Plugin/VersionOptions.png)
![Engine Source installed](https://noesis.github.io/NoesisGUI/UE4Plugin/EngineSource.png)

2. Download and install Python. Additionally, you need to install the following modules: `configparser` (both on Windows and Mac), `pywin32` (on Windows) and `pyobjc` (on Mac). If you're not sure how to do this, for your convenience we provide `InstallPythonPrerequisites.bat` and `InstallPythonPrerequisites.command` that will check these prerequisites and will install the required packages for you. Please, read the following section [Plugin installation](#plugin-installation) for more details. The installation scripts have been tested with Python 2.7 and 3.6. Other versions may work, but they are untested.

### Plugin installation

1. Copy the contents of this repository into `[UE4Root]/Engine/Plugins/NoesisGUI` if you want to use it as an Engine plugin, or `[ProjectRoot]/Plugins/NoesisGUI` if you choose to use it as a Project plugin. We'll refer to the directory where you install the plugin as `[NoesisGUIRoot]` from now on. `[UE4Root]` is the directory where you installed the engine from the Epic Games Launcher, or the directory where you cloned the GitHub repository. With versions of Unreal Engine built from the source code in GitHub you can use the NoesisGUI Unreal Engine plugin as either an Engine plugin or a Project (Game) plugin. However, if you're using an Epic Games Launcher version of the engine, you can only install the plugin as a Project plugin. For more information about Unreal Engine Plugins, please refer to the [Plugins](https://docs.unrealengine.com/latest/INT/Programming/Plugins/index.html) documentation.

2. Download the NoesisGUI Native SDK (C++) from [our developer portal](https://www.noesisengine.com/forums/viewtopic.php?f=14&t=1491) and extract it into `[NoesisGUIRoot]/Source/Noesis/NoesisSDK`.

3. If you haven't installed the required Python modules, or you want to verify they are correctly installed, you can execute `InstallPythonPrerequisites.bat` and `InstallPythonPrerequisites.command` from the Command Prompt on Windows or Terminal on Mac. Navigate to the plugin directory and execute them from there. These will test whether the required modules are installed or not, and will install them if they're not present. You only need to install them once, so you don't need to perform this step every time you update the plugin or Unreal Engine.

3. Install the plugin by executing `InstallPlugin.bat` from the Command Prompt on Windows or `InstallPlugin.command` from the Terminal on Mac. If you're targeting more than one platform, you can pass them as arguments like this: `InstallPlugin.command Mac IOS`. The installer uses the same platform names as Unreal. The valid platform names are `Win64`, `Mac`, `IOS`, `Android`, `PS4` and `XboxOne`. The host platform (`Win64` or `Mac`) is always built, as those binaries are required to run the editor. If you've installed the plugin as a project plugin the installer will enable it automatically by adding it to your `.uproject` file, as described in [First steps with NoesisGUI and Unreal](https://www.noesisengine.com/docs/Gui.Core.UnrealTutorial.html#configuring-noesisgui). IMPORTANT: You will need to perform this step every time you update Unreal Engine or get a new version of this plugin or the NoesisGUI SDK.

4. Even after these steps, sometimes the Editor will warn you that the modules NoesisRuntime and NoesisEditor are out of date when you try to launch it. This may happen if you're running a configuration other than Development or if you've changed to a different engine version. Just click accept so the modules are rebuilt to target the correct version of Unreal Engine.

## Directory structure

If all the steps so far have been successful, your Unreal Engine install should contain the following directories. Please note that only the directories relevant to the NoesisGUI plugin are listed here, and that your installation may contain additional files and directories that have been omitted here for clarity.

```
[NoesisGUIRoot]
+-- Binaries
+-- Config
+-- Intermediate
+-- Resources
+-- Shaders
+-- Source
    +-- Noesis
        +-- NoesisSDK
            +-- Bin
            +-- Include
            +-- Lib
            +-- version.txt
    +-- NoesisBlueprint
    +-- NoesisEditor
    +-- NoesisRuntime
+-- NoesisGUI.uplugin
```

## Samples

After you read this document, we have a few samples so you can see some of the concepts in action:

* [HelloWorld](https://github.com/Noesis/Tutorials/tree/master/Samples/HelloWorld/UE4): A minimal sample showing how to present the contents of a XAML on the screen.

* [Buttons](https://github.com/Noesis/Tutorials/tree/master/Samples/Buttons/UE4): A simple game that shows how you can use `Binding`s to implement `Command`s as `Blueprint` functions.

* [Widget3D](https://github.com/Noesis/Tutorials/tree/master/Samples/Widget3D/UE4): A similar UI, but this time presented in 3D using Unreal Engine's `WidgetComponent`.

* [Login](https://github.com/Noesis/Tutorials/tree/master/Samples/Login/UE4): A slightly more elaborated sample that uses `Binding`s to data and functions in a `Blueprint`, combined with some C++ code for more advanced functions.

* [QuestLog](https://github.com/Noesis/Tutorials/tree/master/Samples/QuestLog/UE4): This samples shows how to use `Binding`s to more complex data, such as `Texture`s and `Array`s of `Object`s.

* [Scoreboard](https://github.com/Noesis/Tutorials/tree/master/Samples/Scoreboard/UE4): This sample shows more advanced ways to expose data on `Blueprint`s so that it can be used in `Binding`s, such as using Getter functions and manually notifying property changes.

* [Localization](https://github.com/Noesis/Tutorials/tree/master/Samples/Localization/UE4): A sample showing a way to implement content localization using `ResourceDictionary`s.

* [UserControl](https://github.com/Noesis/Tutorials/tree/master/Samples/UserControl/UE4): This sample shows how to implement an `UserControl` using a XAML and a C++ code-behind class, and how to use it from another XAML.

* [Menu3D](https://github.com/Noesis/Tutorials/tree/master/Samples/Menu3D/UE4): This sample shows how to use `UserControl`s to implement a multi-panel game main menu.

* [TicTacToe](https://github.com/Noesis/Tutorials/tree/master/Samples/TicTacToe/UE4): This sample shows how to use XAML and `Blueprint`s to implement the classic pen and paper game tic-tac-toe.

* [Inventory](https://github.com/Noesis/Tutorials/tree/master/Samples/Inventory/UE4): This sample shows how to implement a drag and drop inventory system UI.

* [ShooterGame](https://github.com/Noesis/UE4-ShooterGame): This sample replaces the UI from Epic's ShooterGame sample with NoesisGUI. Some changes were dome to the source code in order to expose data and functionality, but otherwise the UI is done completely in `Blueprint`.

## Troubleshooting

* When you try to build, package or launch your project you get an error complaining about missing libraries `UE4-NoesisRuntime.lib` or `UE4-NoesisRuntime-Win64-Shipping.lib` (`UE4-NoesisRuntime.a` or `UE4-NoesisRuntime-Mac-Shipping.a` on Mac).

    * Make sure you ran the installation script, as described in the [Plugin installation](#plugin-installation) section.

* When starting your project editor you get an error because your game module could not be loaded.

    * Make sure you enabled the plugin for your project before adding the dependency to the module `NoesisRuntime`. If you already had a project created, simply add the dependency manually as described in [First steps with NoesisGUI and Unreal](https://www.noesisengine.com/docs/Gui.Core.UnrealTutorial.html#project-setup).

* In windows, you get an error stating that `NoesisRuntime` cannot be loaded because `Noesis.dll` cannot be found.
    
    * Make sure you ran the installation script, as described in the [Plugin installation](#plugin-installation) section.
