@echo off
setlocal EnableExtensions

set "SCRIPT_DIR=%~dp0"
if not exist "%SCRIPT_DIR%..\..\..\Engine\Build\BatchFiles\RunUAT.bat" goto :Exit_Wrong_Directory
if not exist "%SCRIPT_DIR%..\..\..\Engine\Plugins\NoesisGUI\NoesisGUI.uplugin" goto :Exit_Wrong_Directory

:Temp_Dir
set "TEMP_DIR=%tmp%\NoesisGUIPlugin.%RANDOM%"
if exist "%TEMP_DIR%" goto :Temp_Dir

call "%SCRIPT_DIR%..\..\..\Engine\Build\BatchFiles\RunUAT.bat" BuildPlugin -Plugin="%SCRIPT_DIR%NoesisGUI.uplugin" -TargetPlatforms=Win64 -Package="%TEMP_DIR%" -NoHostPlatform
xcopy "%TEMP_DIR%\Binaries\*" "%SCRIPT_DIR%Binaries" /s /i /y /q
rmdir /s /q "%TEMP_DIR%"
exit /B 0

:Exit_Wrong_Directory
echo "BuildNoesisGUIPlugin.bat: The batch file does not appear to be located in the /Engine/Plugins/NoesisGUI directory."
echo "If you've installed the plugin as a Project plugin, please disregard this error."
echo "If you meant to install it as an Engine plugin, please make sure it's in the specified directory."
exit /B 1