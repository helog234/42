#!/usr/bin/python3

def my_sort():
	d = {
		'Hendrix' : '1942',
		'Allman' : '1946',
		'King' : '1925',
		'Clapton' : '1945',
		'Johnson' : '1911',
		'Berry' : '1926',
		'Vaughan' : '1954',
		'Cooder' : '1947',
		'Page' : '1944',
		'Richards' : '1943',
		'Hammett' : '1962',
		'Cobain' : '1967',
		'Garcia' : '1942',
		'Beck' : '1944',
		'Santana' : '1947',
		'Ramone' : '1948',
		'White' : '1975',
		'Frusciante': '1970',
		'Thompson' : '1949',
		'Burton' : '1939',
	}
	
	items_to_sort = d.items()
 
 
	#  lambda function tells sorted() to create a new tuple (year, name) for each item,
	#  and sort by year first, then by name.
	sorted_list = sorted(items_to_sort, key=lambda item: (item[1], item[0]))
	
	for artist in sorted_list:
		print(f" {artist[0]}")
        
if __name__ == "__main__":
	my_sort()
 
    
    