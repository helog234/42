#!/usr/bin/python3

def my_var():
	var = 42
	print(var, " est de type", type(var))

	var = "42"
	print(var, " est de type", type(var))

	var = "quarente-deux"
	print(var, " est de type", type(var))

	var = 42.0
	print(var, " est de type", type(var))

	var = True
	print(var, " est de type", type(var))

	var = [42]
	print(var, " est de type", type(var))

	var = {42: 42}
	print(var, " est de type", type(var))

	var = (42,)
	print(var, " est de type", type(var))

	var = set()
	print(var, " est de type", type(var))

if __name__ == "__main__":
	my_var()