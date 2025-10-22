from elem import Elem, Text

class Html(Elem):
	def __init__(self, content=None, attr: dict = {}):
		super().__init__(tag='html', attr=attr, content=content, tag_type='double')
  
class Head(Elem):
	def __init__(self, content=None, attr: dict = {}):
		super().__init__(tag='head', attr=attr, content=content, tag_type='double')

class Body(Elem):
	def __init__(self, content=None, attr: dict = {}):
		super().__init__(tag='body', attr=attr, content=content, tag_type='double')
  
class Title(Elem):
	def __init__(self, content=None, attr: dict = {}):
		super().__init__(tag='title', attr=attr, content=content, tag_type='double')
  
class Meta(Elem):
	def __init__(self, attr: dict = {}):
		super().__init__(tag='meta', attr=attr, content=None, tag_type='simple')
  
class Img(Elem):
	def __init__(self, attr: dict = {}):
		super().__init__(tag='img', attr=attr, content=None, tag_type='simple')

class Table(Elem):
	def __init__(self, content=None, attr: dict = {}):
		super().__init__(tag='table', attr=attr, content=content, tag_type='double')

class Th(Elem):
	def __init__(self, content=None, attr: dict = {}):
		super().__init__(tag='th', attr=attr, content=content, tag_type='double')

class Tr(Elem):
	def __init__(self, content=None, attr: dict = {}):
		super().__init__(tag='tr', attr=attr, content=content, tag_type='double')
  
class Td(Elem):
	def __init__(self, content=None, attr: dict = {}):
		super().__init__(tag='td', attr=attr, content=content, tag_type='double')
  
class Ul(Elem):
	def __init__(self, content=None, attr: dict = {}):
		super().__init__(tag='ul', attr=attr, content=content, tag_type='double')

class Ol(Elem):
	def __init__(self, content=None, attr: dict = {}):
		super().__init__(tag='ol', attr=attr, content=content, tag_type='double')
 
class Li(Elem):
	def __init__(self, content=None, attr: dict = {}):
		super().__init__(tag='li', attr=attr, content=content, tag_type='double')
  
class H1(Elem):
	def __init__(self, content=None, attr: dict = {}):
		super().__init__(tag='h1', attr=attr, content=content, tag_type='double')
  
class H2(Elem):
	def __init__(self, content=None, attr: dict = {}):
		super().__init__(tag='h2', attr=attr, content=content, tag_type='double')

class P(Elem):
	def __init__(self, content=None, attr: dict = {}):
		super().__init__(tag='p', attr=attr, content=content, tag_type='double')

class Div(Elem):
	def __init__(self, content=None, attr: dict = {}):
		super().__init__(tag='div', attr=attr, content=content, tag_type='double')

class Span(Elem):
	def __init__(self, content=None, attr: dict = {}):
		super().__init__(tag='span', attr=attr, content=content, tag_type='double')

class Hr(Elem):
	def __init__(self, attr: dict = {}):
		super().__init__(tag='hr', attr=attr, content=None, tag_type='simple')
  
class Br(Elem):
	def __init__(self, attr: dict = {}):
		super().__init__(tag='br', attr=attr, content=None, tag_type='simple')

# Test du sujet
def test_basic_elem():
	print(Html([Head(), Body()]))

# test comm exercice precedent
def test_html():
    print(Html([
			Head([Title(content=Text('"Hello ground!"'))]),
			Body([
				H1(content=Text("Oh no, not again!")),
				Img({"src": "http://i.imgur.com/pfp3T.jpg"}),
			])
		]))
    
def test_all():
    print(Html([
		Head([Title(content=Text('"Test Page"'))]),
		Body([
			H1(content=Text('"Oh no, not again!"')),
			Img({"src": "http://i.imgur.com/pfp3T.jpg"}),
			P(content=Text('"This is a paragraph."')),
			Div([Span(content=Text('"This is a span."'))]),
			Ul([Li(content=Text('"Item 1"')), Li(content=Text('"Item 2"'))]),
			Ol([Li(content=Text('"First"')), Li(content=Text('"Second"'))]),
			Table([
				Tr([Th(content=Text('"Header 1"')), Th(content=Text('"Header 2"'))]),
				Tr([Td(content=Text('"Data 1"')), Td(content=Text('"Data 2"'))])
			]),
			Hr(),
			Br()
		])
	]))
    
 
if __name__ == "__main__":
	print("Test subject:")
	test_basic_elem()
	print("Test as earlier ex:")
	test_html()
	print("Test all elements:")
	test_all()
 