#!/usr/bin/python3
import sys

def render_state(city):
	states = {
		"Oregon" : "OR",
		"Alabama" : "AL",
		"New Jersey": "NJ",
		"Colorado" : "CO"
	}
	capital_cities = {
		"OR": "Salem",
		"AL": "Montgomery",
		"NJ": "Trenton",
		"CO": "Denver"
	}
 
	if city in capital_cities.values():
		for state, code in states.items():
			if capital_cities[code] == city:
				print(f"{state}")
				return
	else:
		print("Unknown city")

if __name__ == "__main__":
#takes a city name as an argument
	if len(sys.argv) == 2:
		render_state(sys.argv[1])
	