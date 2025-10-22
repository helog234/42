from beverages import *
import random

class CoffeeMachine:

	class EmptyCup(HotBeverage):
		def __init__(self):
			super().__init__(name="Empty Cup", price=0.90)

		def description(self):
			return "An empty cup?! Gimme my money back!"


	class BrokenMachineException(Exception):
		def __init__(self, message="This coffee machine has to be repaired."):
			super().__init__(message)

	def __init__(self):
		self.countUsage = 0

	def repair(self):
		print("The coffee machine has been repaired.")
		self.countUsage = 0

	def serve(self, beverage):
		if self.countUsage >= 9:
			raise self.BrokenMachineException()
		self.countUsage += 1
		if random.choice([True, False]):
			return self.EmptyCup()
		if isinstance(beverage, HotBeverage):
			return beverage


def test_coffee_machine():
	print("---- Coffee Machine ----")
	machine = CoffeeMachine()
	beverages = [Coffee(), Tea(), Chocolate(), Cappuccino()]

	for _ in range(15):
		try:
			beverage = random.choice(beverages)
			print(machine.serve(beverage))
		except CoffeeMachine.BrokenMachineException as e:
			print(e)
   
	machine.repair()
 
	for _ in range(10):
		try:
			beverage = random.choice(beverages)
			print(machine.serve(beverage))
		except CoffeeMachine.BrokenMachineException as e:
			print(e)
   
	machine.repair()
	for _ in range(5):
		try:
			beverage = random.choice(beverages)
			print(machine.serve(beverage))
		except CoffeeMachine.BrokenMachineException as e:
			print(e)
	print("---- End of Coffee Machine Test ----")
   
if __name__ == "__main__":
	test_coffee_machine()