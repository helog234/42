LOG_FILE="pip_install.log"
PYTHON_PATH="/usr/bin/python3"
PATH_PY_URL="https://github.com/jaraco/path.git"
VENV_DIR="local_lib"
MY_PROGRAM="my_program.py"

#!/bin/bash
# pip version
python3 -m pip --version

# Create a virtual environment
	$PYTHON_PATH -m venv $VENV_DIR

# Activate the virtual environment
source $VENV_DIR/bin/activate

# Install the required package
python3 -m pip install --log $LOG_FILE --force-reinstall git+$PATH_PY_URL

# Check if the installation was successful
if [ $? -eq 0 ]; then
	echo "Package installed successfully."
	echo "Lauching Python end of script"
	echo "-------------------------"
	echo "" 
    PYTHONPATH="$INSTALL_DIR" python3 "$MY_PROGRAM"
else
	echo "Package installation failed. Check the log file: $LOG_FILE"
	exit 1
fi
