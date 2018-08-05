@echo off
setlocal EnableExtensions

python --version > nul 2>&1
if ERRORLEVEL 1 (
	echo Error: Python is not installed
	exit /B 1
)

python --version 2>&1 | findstr "2.7" > nul 2>&1
if ERRORLEVEL 1 (
	python --version 2>&1 | findstr "3.6" > nul 2>&1
	if ERRORLEVEL 1 (
		echo Error: Wrong version of Python detected. 2.7.x or 3.6.x required
		exit /B 1
	)
)

echo Python installed. Checking required modules...

python -c "import pip" > nul 2>&1
if ERRORLEVEL 1 (
	echo "Module pip not installed. Using easy_install"
	echo | set /p="Testing configparser... "
	python -c "import configparser" > nul 2>&1
	if ERRORLEVEL 1 (
		echo not installed. Installing...
		easy_install --user -U configparser
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
		easy_install --user -U pywin32
		if ERRORLEVEL 1 (
			echo Error: Python failed installing pywin32
			exit /B 1
		)
	) else (
		echo already installed!
	)
) else (
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
		python -m pip install --user -U pywin32
		if ERRORLEVEL 1 (
			echo Error: Python failed installing pywin32
			exit /B 1
		)
	) else (
		echo already installed!
	)
)
echo Setup successful
