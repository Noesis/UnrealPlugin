@echo off
setlocal EnableExtensions

python --version > nul 2>&1
if ERRORLEVEL 1 (
	echo Error: Python is not installed
	exit /B 1
)

python --version 2>&1 | findstr "2.7" > nul 2>&1
if ERRORLEVEL 1 (
	echo Error: Wrong version of Python detected
	exit /B 1
)

python -c "import pip"
if ERRORLEVEL 1 (
	echo Error: Module pip not installed. Exiting...
)

echo Python 2.7 installed. Checking required modules...

echo | set /p="Testing configparser... "
python -c "import configparser" > nul 2>&1
if ERRORLEVEL 1 (
	echo not installed. Installing...
	python -m pip install --user -U configparser
	if ERRORLEVEL 1 (
		echo Error: Python failed installing configparser
		exit /B 1
	)
) else (
	echo already installed!
)

echo | set /p="Testing pywin32... "
python -c "import win32api" > nul 2>&1
if ERRORLEVEL 1 (
	echo not installed. Installing...
	python -m pip install -U pywin32
	if ERRORLEVEL 1 (
		echo Error: Python failed installing pywin32
		exit /B 1
	)
) else (
	echo already installed!
)
echo Setup successful
