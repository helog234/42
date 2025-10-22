#!/usr/bin/python3
import sys

def render_capital_city(state):
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
 
	if state in states:
		code = states[state]
		if code in capital_cities:
			print(f"{capital_cities[code]}")
	else:
		print("Unknown state")

if __name__ == "__main__":
#takes a state name as an argument
	if len(sys.argv) == 2:
		render_capital_city(sys.argv[1])

