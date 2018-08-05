#!/bin/bash

python --version > /dev/null 2>&1
if [[ ! $? -eq 0 ]]; then
	echo "Error: Python is not installed"
	exit 1
fi

python --version 2>&1 | grep -q "3.6"
if [[ ! $? -eq 0 ]]; then
	python --version 2>&1 | grep -q "2.7"
	if [[ ! $? -eq 0 ]]; then
		echo "Error: Wrong version of Python detected. 2.7.x or 3.6.x required"
		exit 1
	fi
fi

echo "Python installed. Checking required modules..."

python -c "import pip" > /dev/null 2>&1
if [[ ! $? -eq 0 ]]; then
	echo "Module pip not installed. Using easy_install"
	echo -n "Testing configparser... "
	python -c "import configparser" > /dev/null 2>&1
	if [[ ! $? -eq 0 ]]; then
		echo "not installed. Installing..."
		easy_install --user -U configparser
		if [[ ! $? -eq 0 ]]; then
			echo "Error: Python failed installing configparser"
			exit 1
		fi
	else
		echo "already installed!"
	fi

	echo -n "Testing pyobjc... "
	python -c "import Cocoa" > /dev/null 2>&1
	if [[ ! $? -eq 0 ]]; then
		echo "not installed. Installing..."
		easy_install --user -U pyobjc
		if [[ ! $? -eq 0 ]]; then
			echo "Error: Python failed installing pyobjc"
			exit 1
		fi
	else
		echo "already installed!"
	fi

	echo "Setup successful"
	exit 0
fi

echo -n "Testing configparser... "
python -c "import configparser" > /dev/null 2>&1
if [[ ! $? -eq 0 ]]; then
	echo "not installed. Installing..."
	python -m pip install --user -U configparser
	if [[ ! $? -eq 0 ]]; then
		echo "Error: Python failed installing configparser"
		exit 1
	fi
else
	echo "already installed!"
fi

echo -n "Testing pyobjc...  "
python -c "import Cocoa" > /dev/null 2>&1
if [[ ! $? -eq 0 ]]; then
	echo "not installed. Installing..."
	python -m pip install --user -U pyobjc
	if [[ ! $? -eq 0 ]]; then
		echo "Error: Python failed installing pyobjc"
		exit 1
	fi
else
	echo "already installed!"
fi

echo "Setup successful"
