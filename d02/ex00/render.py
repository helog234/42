#!/usr/bin/python3
import sys
import os
import re

def render_template(template_path):
	if not os.path.exists(template_path):
		print("Template file does not exist.")
		return

	with open(template_path, 'r') as file:
		template = file.read()

	# get the environment variables from settings.py
	settings_path = os.path.join(os.path.dirname(template_path), 'settings.py')
	if not os.path.exists(settings_path):
		print("Settings file does not exist.")
		return

	env_values = {}
	#open file and read the content
	with open(settings_path, 'r') as settings_file:
		for line in settings_file:
			# split the line into key and value
			if '=' in line:
				key, value = line.split('=', 1)
				key = key.strip()
				value = value.strip().strip('"')  # remove quotes around the value
				env_values[key] = value

	#get name of the file without the extension
	template_name = os.path.splitext(os.path.basename(template_path))[0]

	# create the output file name
	output_file_name = f"{template_name}.html"
	output_file_path = os.path.join(os.path.dirname(template_path), output_file_name)

	# write the rendered template to the output file
	with open(output_file_path, 'w') as output_file:
		# find the placeholders in the template and replace them
		for key, value in env_values.items():
			placeholder = "{" + key + "}"
			template = template.replace(placeholder, value)
		output_file.write(template)
 
if __name__ == "__main__":
	if len(sys.argv) != 2:
		print("Usage: python render.py <template_path>")
		sys.exit(1)

	template_path = sys.argv[1]
	if not re.match(r'.*\.template$', template_path):
		print("Template file must have a .template extension.")
		sys.exit(1)

	render_template(template_path)


