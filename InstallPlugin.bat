@echo off
setlocal EnableExtensions

python --version > nul 2>&1
if ERRORLEVEL 1 (
	echo Error: Python is not installed
	exit /B 1
)

python InstallPlugin.py %*