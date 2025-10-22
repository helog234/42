#!/usr/bin/python3

def parse_periodic_table():
	"""
	Parses the periodic table data from the file and returns a dictionaries.
 	ex: Hydrogen = position:0, number:1, small: H, molar:1.00794, electron:1
	"""
	elements_by_position = {}
	current_row = 0
	with open("periodic_table.txt", "r") as file:
		for line in file:
			# Split the line by commas and strip whitespace
			data = [item.strip() for item in line.split(",")]
			if len(data) < 5:
				print(f"Skipping malformed line: {line.strip()}")
				continue
			try:
				# transform first item Hydrogen = position:0 into two items
				# parse name then position
				name, position_str = data[0].split("=", 1)
				name = name.strip()
				position = int(position_str.split(":")[1].strip())
				# Create a dictionary for the element
				element = {
					'name': name,
					'position': position,
					'number': int(data[1].split(":")[1].strip()),
					'small': data[2].split(":")[1].strip(),
					'molar': float(data[3].split(":")[1].strip()),
					'electron': data[4].split(":")[1].strip() # Stores as string to handle values like "2 1"
				}
				#position is the colum
				#but we need to creat a row to deduce structure of Mendeleiev table
				if position == 0 and name != "Hydrogen":
					current_row += 1
				# dictionary keyed by a (row, col) tuple
				col = position
				elements_by_position[(current_row, col)] = element
	
			except (ValueError, IndexError) as e:
				print(f"Error parsing line: {line.strip()} - {e}")
	return elements_by_position

def create_css_file():
	"""
	Creates a CSS file to style the periodic table.
	"""
	with open("periodic_table.css", "w") as file:
		css = """
		body {
			font-family: sans-serif;
		}
		table {
			border-collapse: collapse;
			margin: 20px auto;
			width: 95vw; /* Viewport Width: The vw unit represents a percentage of the root element width. One vw is equal to 1percent the viewport width. */
			max-width: 1400px;
		}
		/* Style for every cell, including empty ones */
		td {
			border: 1px solid black;
			width: 5.5vw;
			max-height: 80px;
			height: 5.5vw;
			vertical-align: top;
			padding: 2px;
			position: relative;
		}
		/* empty cells invisible */
		td.empty {
			border: none;
		}
		td > div {
            position: absolute;
            text-align: center;
        }

        .number {
            top: 3px;
            left: 3px;
            font-size: 0.7em;
        }
        .mass {
            bottom: 3px;
            right: 3px;
            font-size: 0.7em;
        }
        .symbol {
            top: 0;
            left: 0;
            right: 0;
            bottom: 0;
            display: flex;
            align-items: center;
            justify-content: center;
            font-size: 1.5em;
            font-weight: bold;
        }
        .name {
			position: absolute;
			bottom: 20px;
			left: 0;
			right: 0;
			text-align: center;
			font-size: 0.7em;
			padding-bottom: 2px;
		}
		.electron {
			top: 20px;
            right: 3px;
            font-size: 0.6em;
            text-align: right;
			color: gray; /* text gray */
        }
        """
		file.write(css)

def create_html_file(elements_by_position):
	"""
	Creates an HTML file displaying the periodic table with 
	the structure of Mendeleiev table and the data from the list dict.
	"""
	#create html and use the css file
	with open("periodic_table.html", "w") as file:
		file.write("<!DOCTYPE html>\n<html lang='en'>\n<head>\n")
		file.write("<link rel='stylesheet' type='text/css' href='periodic_table.css'>\n")
		file.write("<title>Periodic Table</title>\n")
		file.write("<meta charset='UTF-8'>\n")
		file.write("<meta name='viewport' content='width=device-width, initial-scale=1.0'>\n")
		file.write("</head>\n<body>\n")
		file.write("<h1>Periodic Table</h1>\n")
		file.write("<table>\n")
  
		# 7 cause i did not include the lanthanides and actinides since they are not given in the file
		# now that we have decoded the positions, with the rows and columns, we can create html table
		for row in range(7):
			file.write("<tr>\n")
			for col in range(18):
				if col == 2:
				# add an empty cell for the 3rd column
					file.write("<td style='border: none; padding:10px'></td>\n")
				element = elements_by_position.get((row, col))
				if element:
					content = (f"<div class='number'>{element['number']}</div>"
						f"<div class='electron'>{element['electron']}</div>"
						f"<div class='symbol'>{element['small']}</div>"
						f"<div class='name'>{element['name']}</div>"
						f"<div class='mass'>{element['molar']:.4f}</div>")

					file.write(f"<td>{content}</td>\n")
				else:
					# If no element exists at this position, create an empty cell with no border
					file.write("<td class='empty'></td>\n")

			file.write("</tr>\n")
   
		file.write("</table>\n</body>\n</html>\n")

  
def main():
	"""
	Main function to parse the periodic table and create the HTML file.
	"""
	periodic_table = parse_periodic_table()
	create_css_file()
	create_html_file(periodic_table)

if __name__ == "__main__":
	main()
  
