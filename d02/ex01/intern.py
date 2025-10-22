class Intern:

	def __init__(self, name="My name? I’m nobody, an intern, I have no name"):
		self.name = name
		
	def __str__(self):
		return self.name

	def make_coffee(self):
		return Coffee()

	def work(self):
		raise Exception("I’m just an intern, I can’t do that....")

class Coffee():

	def __str__(self):
		return "This is the worst coffee you ever tasted."


def test_intern():
	print("---- No Name Intern ----")
	intern = Intern()
	print(intern)
	print(intern.make_coffee())
	try:
		intern.work()
	except Exception as e:
		print(e)

	print("\n---- Named Intern ----")
	mark = Intern("Mark")
	print(mark)
	print(mark.make_coffee())
	try:
		mark.work()
	except Exception as e:
		print(e)
 

if __name__ == "__main__":
	test_intern()
 
 