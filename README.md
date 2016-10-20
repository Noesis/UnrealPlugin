Noesis GUI UE4 Plugin
=====================

Setup
-----

1. Copy the contents of this repository into Engine/Plugins/NoesisGui.

2. Extract the Noesis GUI SDK into Engine/Plugins/NoesisGui/Source/ThirdParty/Noesis.
   The Noesis GUI SDK entails folder /NoesisGUI-SDK1.3/ with Bin, Include and Lib. Delete the others.
    

3. Regenerate the UE4 projects.

How to use
----------

1. Import a XAML file into the editor. This will create at least one NoesisGuiXaml object, and potentially other Texture and Font objects.

2. Create a NoesisGuiBlueprint from the New>MiscelLaneous menu.

3. Open the blueprint and click on Class Settings in the top bar. Edit the Base Xaml property to refer to the NoesisGuiXaml imported in the first step.

4. Create an instance of the NoesisGuiBlueprint object and call InitInstance on it.
