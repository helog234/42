#!/usr/bin/python3
from elements import *

class Page():
	def __init__(self, elem):
		self.root_element = elem
  
	def is_valid(self):
		return self.to_check(self.root_element)

	def to_check(self, element):
		#base case for recursion (where to stop)
		if isinstance(element, Text):
			return True
        
		allowed_types = (Html, Head, Body, Title, Meta, Img, Table, Th, Tr, Td,
		Ul, Ol, Li, H1, H2, P, Div, Span, Hr, Br)
		if not isinstance(element, allowed_types):
			return False

		if isinstance(element, Html):
			# very next element must be Head then Body
			if len(element.content) != 2 or \
				not isinstance(element.content[0], Head) or \
				not isinstance(element.content[1], Body):
				return False
	
		elif isinstance(element, Head):
			# Head must contain Title and only Title
			if len(element.content) != 1 or not isinstance(element.content[0], Title):
				return False
	
		elif isinstance(element, (Body, Div)):
			if any(not isinstance(c, (H1, H2, Div, Table, Ul, Ol, Span, Text, P)) for c in element.content):
				return False
	
		elif isinstance(element, (Title, H1, H2, Li, Th, Td)):
			# These elements can only contain Text 
			if len(element.content) != 1 or not isinstance(element.content[0], Text):
				return False

		elif isinstance(element, P):
			# P can contain Text
			if any(not isinstance(c, Text) for c in element.content):
				return False

		elif isinstance(element, Span):
			# Span can contain Text or P
			if any(not isinstance(c, (Text, P)) for c in element.content):
				return False

		elif isinstance(element, (Ol, Ul)):
			# Ol and Ul can only contain Li and need at least one Li
			if not element.content or any(not isinstance(c, Li) for c in element.content):
				return False

		elif isinstance(element, Tr):
			# Tr can only contain Th or Td and those needs to be mutually exclusive
			if not element.content:
				return False
			is_th = all(isinstance(c, Th) for c in element.content)
			is_td = all(isinstance(c, Td) for c in element.content)
			if not (is_th or is_td):
				return False
    
		elif isinstance(element, Table):
			# Table can only contain Tr
			if any(not isinstance(c, Tr) for c in element.content):
				return False

  		# Check children recursively
		for child in element.content:
			if not self.to_check(child):
				return False

		return True

	def __str__(self):
		doctype = '<!DOCTYPE html>\n' if isinstance(self.root_element, Html) else ''
		return doctype + str(self.root_element)

  
	def write_to_file(self, filename):
		with open(filename, 'w') as file:
			file.write(str(self))
    

def tests():
	# --- Test 1: A valid page ---
	valid_page_content = Html([
		Head([Title(Text("A Valid Page"))]),
		Body([
			H1(Text("Welcome!")),
			P(Text("This is a test of a valid HTML structure.")),
			Table([
				Tr([Th(Text("Col 1")), Th(Text("Col 2"))]),
				Tr([Td(Text("Data A")), Td(Text("Data B"))])
			])
		])
	])
	valid_page = Page(valid_page_content)
	print(f"Test 1 (Valid Page): {'OK' if valid_page.is_valid() else 'FAILED'}")
	valid_page.write_to_file('valid_page.html')

	# --- Test 2: Invalid - Body inside Head ---
	invalid_page_1 = Page(Html([Head([Body([])])]))
	print(f"Test 2 (Invalid - Body in Head): {'OK' if not invalid_page_1.is_valid() else 'FAILED'}")

	# --- Test 3: Invalid - Div inside H1 ---
	invalid_page_2 = Page(Html([Head([Title(Text(""))]), Body([H1([Div([])])])]))
	print(f"Test 3 (Invalid - Div in H1): {'OK' if not invalid_page_2.is_valid() else 'FAILED'}")

	# --- Test 4: Invalid - Mixed Th and Td in Tr ---
	invalid_page_3 = Page(Html([Head([Title(Text(""))]), Body([Table([Tr([Th(Text("")), Td(Text(""))])])])]))
	print(f"Test 4 (Invalid - Mixed Th/Td): {'OK' if not invalid_page_3.is_valid() else 'FAILED'}")

	# --- Test 5: Invalid - Ul without Li ---
	invalid_page_4 = Page(Html([Head([Title(Text(""))]), Body([Ul([])])]))
	print(f"Test 5 (Invalid - Ul without Li): {'OK' if not invalid_page_4.is_valid() else 'FAILED'}")

	# --- Test 6: Invalid - Unknown element ---
	class Unknown(Elem):
		def __init__(self):
			super().__init__()
	
	invalid_page_5 = Page(Html([Head([Title(Text(""))]), Body([Unknown()])]))
	print(f"Test 6 (Invalid - Unknown element): {'OK' if not invalid_page_5.is_valid() else 'FAILED'}")

	# --- Test 7: Invalid - Html without Head/Body ---
	invalid_page_6 = Page(Html([P(Text("Orphan"))]))
	print(f"Test 7 (Invalid - Html without Head/Body): {'OK' if not invalid_page_6.is_valid() else 'FAILED'}")

	# --- Test 8: Invalid - Head with two Titles ---
	invalid_page_7 = Page(Html([Head([Title(Text("1")), Title(Text("2"))]), Body([])]))
	print(f"Test 8 (Invalid - Head with two Titles): {'OK' if not invalid_page_7.is_valid() else 'FAILED'}")
	
  
if __name__ == "__main__":
	tests()