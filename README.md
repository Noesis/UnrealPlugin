Noesis GUI UE4 Plugin
=====================

Setup
-----

1. Copy the contents of this repository into Engine/Plugins/NoesisGui.

1. Extract the Noesis GUI SDK into Engine/Plugins/NoesisGui/Source/ThirdParty/Noesis. The Noesis GUI SDK means the folder /NoesisGUI-SDK1.3/ with Bin, Include and Lib. You may delete the other directories.

1. Regenerate the UE4 projects.

How to use
----------

1. Import a XAML file into the editor. This will create at least one NoesisGuiXaml object, and potentially other Texture and Font objects.

1. Create a NoesisGuiBlueprint from the New>MiscelLaneous menu.

1. Open the blueprint and click on Class Settings in the top bar. Edit the Base Xaml property to refer to the NoesisGuiXaml imported in the first step.

1. Create an instance of the NoesisGuiBlueprint object using the CreateWidget function and call AddToViewport/AddToPlayerScreen as you would with a native UE4 widget.

1. Alternatively you can use the NoesisGuiBlueprint with a WidgetComponent to obtain a 3D widget the same way you would with a native UE4 widget.

Upgrade notes for 0.2
---------------------

Many classes have been renamed from NoesisGui to simply Noesis. If you had native C++ classes that inherited from these, you'll have to modify your code. If you have existing assets, you'll have to add class redirects from the old classes to the new. The file Engine.ini contains the redirects. You can add them to your BaseEngine.ini file or your project's DefaultEngine.ini files.

Known issues
------------

There's a problem with delay load DLLs that will be addressed in an upcoming release. At the moment it means that the Noesis SDK DLL (Noesis.dll) is loaded normally, which means it must be in the same directory as the exe. The build script copies it to the right directory for modular (Editor) builds. For monolothic builds (by default, all configurations without editor) the DLL must be copied manually.