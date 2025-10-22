#!/usr/bin/python3
from path import Path

def my_program():
	dir_path = Path('py_dir')
	file_path = dir_path / 'py_file.txt'
	#create directory
	dir_path.mkdir_p()

	try:
		file_path.write_text('Hello, World!\nMy everything')
		print(file_path.read_text())
	except Exception as e:
		print(f"Error writing to file: {e}")

if __name__ == "__main__":
	my_program()
 
 #lauch ./my_script.sh