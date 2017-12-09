@echo off
setlocal EnableExtensions

rem get unique file name 
:uniqLoop
set "uniqueFileName=%tmp%\NoesisGuiPlugin%RANDOM%"
if exist "%uniqueFileName%" goto :uniqLoop

"%~dp0..\..\Binaries\DotNET\AutomationTool.exe" BuildPlugin -Plugin="%~dp0NoesisGUI.uplugin" -TargetPlatforms=Win64 -Package="%uniqueFileName%"
xcopy "%uniqueFileName%\Binaries\*" "%~dp0Binaries" /e /i /y
xcopy "%uniqueFileName%\Intermediate\*" "%~dp0Intermediate" /e /i /y
rmdir /s /q "%uniqueFileName%