#!/usr/bin/python3

def my_dict():
	d = [
		('Hendrix' , '1942'),
		('Allman' , '1946'),
		('King' , '1925'),
		('Clapton' , '1945'),
		('Johnson' , '1911'),
		('Berry' , '1926'),
		('Vaughan' , '1954'),
		('Cooder' , '1947'),
		('Page' , '1944'),
		('Richards' , '1943'),
		('Hammett' , '1962'),
		('Cobain' , '1967'),
		('Garcia' , '1942'),
		('Beck' , '1944'),
		('Santana' , '1947'),
		('Ramone' , '1948'),
		('White' , '1975'),
		('Frusciante', '1970'),
		('Thompson' , '1949'),
		('Burton' , '1939')
	]
 
	#As of Python version 3.7, dictionaries are ordered. In Python 3.6 and earlier, dictionaries are unordered.
 
	#empty dict
	years = {}
	#fill the dict with the data from the list of tuples
	for name, year in d:
     	#if year does not exists yet create a new key
		if year not in years:
			years[year] = []
		#append the name to the list of names for that year (in all cases)
		years[year].append(name)
	#print the dict
	for year, names in years.items():
		if len(names) > 1:
			print(f"{year} : {' '.join(names)}")
		else:
			print(f"{year} : {names[0]}")

	if not years:
		print("Le dictionnaire est vide")
		return

if __name__ == "__main__":
	my_dict()