class PracticePython :
	@staticmethod
	def update_scores(player_scores, events):
		for player, points in events:
			if (player in player_scores):
				player_scores[player] += points
		return player_scores
	
	@staticmethod
	def get_winner(player_scores):
		points = 0
		for player in player_scores:
			if (player in player_scores):
				if (points < player_scores[player]):
					points = player_scores[player]
					name = player
		return name
	@staticmethod
	def get_winner2(player_scores):
		return max(player_scores, key = player_scores.get)
	@staticmethod
	def get_juice(player_scores):
		player = max(player_scores, key = player_scores.get)
		highest_score = max(player_scores.values())
		return player, highest_score
	

class Calculator:
	@staticmethod
	def calculate_total(cart):
		cost_item = 0
		for dic in cart:
			cost_item += dic['price'] * dic['quantity']
		return cost_item
	@staticmethod
	def find_most_expensive(cart):
		cost = 0
		for dic in cart:
			if (cost < dic['price']):
				cost = dic['price']
				name = dic['name']
		return name
	@staticmethod
	def find_most_expensive2(cart):
		return max(cart, key=(lambda dic: dic['price']))['name']
	# replace lambda by function in your mind and add return before last
	def find_highest_total_cost(cart):
		cost = 0
		for dic in cart:
			if (cost < dic['price'] * dic['quantity']):
				cost = dic['price'] * dic['quantity']
				name = dic['name']
		return name

import statistics
class third:
	@staticmethod
	def calculate_average(grades):
		return statistics.mean(grades)
	def find_top_student(students):
		mean = 0
		for entry in students:
			l = statistics.mean(students[entry])
			if (mean < l):
				mean = l
				name = entry
		return name
	def all_students_passed(students, passing_grade):
		for name, grade in students.items():
			mean = third.calculate_average(grade)
			if (mean < passing_grade):
				return False
		return True


if __name__ == '__main__':
	pp = PracticePython()
	player_scores = {'Alice': 10, 'Bob': 15, 'Charlie': 8}
	events = [('Alice', 5), ('Bob', 10), ('Charlie', 3), ('Alice', 7), ('Charlie', 12)]
	updated_scores = PracticePython.update_scores(player_scores, events)
	winner = PracticePython.get_winner2(updated_scores)
	chad, highest = PracticePython.get_juice(updated_scores)
	print("Updated Scores:", updated_scores)
	print("Winner:", winner)
	print("Winner:", chad, " Score:", highest)


	cart = [
    {"name": "Apple", "price": 1.5, "quantity": 4},
    {"name": "Banana", "price": 0.8, "quantity": 10},
    {"name": "Cherry", "price": 2.0, "quantity": 5},
	]
	c = Calculator()
	tot_cost = Calculator.calculate_total(cart)
	most_exp = Calculator.find_most_expensive(cart)
	most_exp2 = Calculator.find_most_expensive2(cart)
	highest_cost = Calculator.find_highest_total_cost(cart)
	print(tot_cost)
	print(most_exp2)
	print(highest_cost)

	grades = [85, 90, 78]
	students = {
		"Alice": [85, 90, 78],
		"Bob": [55, 60, 65],
		"Charlie": [95, 100, 92],
		"David": [45, 40, 35]
	}
	average = third.calculate_average(grades)
	print("The average grade is :", average)
	name = third.find_top_student(students)
	print("the best stud is :", name)
	success = third.all_students_passed(students, 80)
	print("The class is strong :", success)