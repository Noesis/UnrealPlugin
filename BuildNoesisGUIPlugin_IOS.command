#!/bin/bash

SCRIPT_DIR=$(cd "`dirname "$0"`" && pwd)
if [ ! -f "$SCRIPT_DIR/../../../Engine/Build/BatchFiles/RunUAT.sh" ] || [ ! -f "$SCRIPT_DIR/../../../Engine/Plugins/NoesisGUI/NoesisGUI.uplugin" ]; then
	echo "BuildNoesisGUIPlugin.command: The shell script does not appear to be located in the /Engine/Plugins/NoesisGUI directory."
	echo "If you've installed the plugin as a Project plugin, please disregard this error."
	echo "If you meant to install it as an Engine plugin, please make sure it's in the specified directory."
	exit 1
fi

TEMP_DIR=$(mktemp -d -t NoesisGUIPlugin)

"$SCRIPT_DIR/../../../Engine/Build/BatchFiles/RunUAT.sh" BuildPlugin -Plugin="$SCRIPT_DIR/NoesisGUI.uplugin" -TargetPlatforms=IOS -Package="$TEMP_DIR" -NoHostPlatform
cp -R "$TEMP_DIR/Binaries/" "$SCRIPT_DIR/Binaries"
cp -R "$TEMP_DIR/Intermediate/" "$SCRIPT_DIR/Intermediate"
rm -r "$TEMP_DIR"