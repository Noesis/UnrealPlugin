#!/bin/bash

python --version > /dev/null 2>&1
if [[ ! $? -eq 0 ]]; then
	echo "Error: Python is not installed"
	exit 1
fi

python InstallPlugin.py "$@"