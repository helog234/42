LOG_FILE="pip_install.log"
PYTHON_PATH="/usr/bin/python3"
VENV_DIR="django_venv"
MY_PROGRAM="request_wikipedia.py"

#!/bin/bash

# virtual environment
$PYTHON_PATH -m venv $VENV_DIR

# Activate the virtual environment
source $VENV_DIR/bin/activate

# Install required packages
python3 -m pip install --log $LOG_FILE --force-reinstall -r requirements.txt

# Check if the installation was successful
if [ $? -eq 0 ]; then
	echo "Package installed successfully."
else
	echo "Package installation failed. Check the log file: $LOG_FILE"
	exit 1
fi