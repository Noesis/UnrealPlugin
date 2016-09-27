Noesis GUI UE4 Plugin
=====================

Setup
-----

1. Copy the contents of this repository into Engine/Plugins/NoesisGui.

1. Extract the Noesis GUI SDK into Engine/Plugins/NoesisGui/Source/ThirdParty/Noesis.

1. Regenerate the UE4 projects.

How to use
----------

1. Import a XAML file into the editor. This will create at least one NoesisGuiXaml object, and potentially other Texture and Font objects.

1. Create a NoesisGuiBlueprint from the New>MiscelLaneous menu.

1. Open the blueprint and click on Class Settings in the top bar. Edit the Base Xaml property to refer to the NoesisGuiXaml imported in the first step.

1. Create an instance of the NoesisGuiBlueprint object and call InitInstance on it.