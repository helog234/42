#!/usr/bin/python3
import sys
import antigravity

def geohash(latitude, longitude, dowOpening):
	try:
		latitude = float(latitude)
	except ValueError:
		return print("latitude required type: float")
	try:
		longitude = float(longitude)
	except ValueError:
		return print("longitude required type: float")
	try:
		dowOpening = dowOpening.encode('utf-8')
	except AttributeError:
		return print("dowOpening required type: string")

	antigravity.geohash(latitude, longitude, dowOpening)

# ex python3 geohashing.py 37.421542 -122.085589 2005-05-26-10458.68
if __name__ == "__main__":
	if len(sys.argv) != 4:
		print("Usage: python geohashing.py <latitude> <longitude> <dowOpening>")
	else:
		geohash(sys.argv[1], sys.argv[2], sys.argv[3])