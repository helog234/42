#!/usr/bin/python3

def my_numbers():
	#not checking if the file exists because of the specifications of the exercise
	file = open("numbers.txt")
	line = file.read()
	file.close()
	numbers = line.split(",")
	for number in numbers:
		try:
			number = int(number)
			print(f"{number}")
		except ValueError:
			print(f"{number} n'est pas un nombre entier valide")

	if not numbers:
		print("Le fichier est vide")
		return

if __name__ == "__main__":
	my_numbers()

	