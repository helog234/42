import requests
from bs4 import BeautifulSoup
import sys

def get_hyperlink(page_txt):
	try:
		soup = BeautifulSoup(page_txt, 'html.parser')
		main_article = soup.find('div', id="mw-content-text")
		paragraphs = main_article.find_all('p')
		for para in paragraphs:
			#find the first link
			link = para.find('a', href=True)
			if link and link['href'].startswith('/wiki/') and not link['href'].startswith('/wiki/Special:'):
				return 'https://en.wikipedia.org' + link['href']
		else:
			return None
	except Exception as e:
		print(f"Error getting hyperlink: {e}")
		return None

def get_page_title(page_txt):
	try:
		soup = BeautifulSoup(page_txt, 'html.parser')
		title = soup.find('h1', id='firstHeading')
		return title.string if title else "No title found"
	except Exception as e:
		print(f"Error getting page title: {e}")
		return None

def request_philosophy(url):
	try:
		response = requests.get(url)
		if response.status_code == 200:
			return response.text
		else:
			return None
	except Exception as e:
		print(f"Error requesting philosophy: {e}")
		return None

def parse_input(input_string):
	try:
		input_string = input_string.strip()
		if input_string.find(' ') != -1:
			input_string = input_string.replace(' ', '_')
		wiki_url = f"https://en.wikipedia.org/wiki/{input_string}"
		return wiki_url
	except Exception as e:
		print(f"Error parsing input: {e}")
		return None


def main():
	if len(sys.argv) != 2:
		print("Usage: python roads_to_philosophy.py <search_item>")
		sys.exit(1)

	search_item = sys.argv[1]
	visited_links = set()
	visited_pages = []
	
	while True:
		wiki_url = parse_input(search_item)
		if not wiki_url:
			sys.exit(1)

		page_txt = request_philosophy(wiki_url)
		if not page_txt:
			print("It leads to a dead end !")
			sys.exit(1)

		if get_page_title(page_txt) == "Philosophy":
			visited_pages.append("Philosophy")
			for page in visited_pages:
				print(page)
			print(f"{len(visited_pages)} roads from {sys.argv[1]} to philosophy !")
			break
   
		hyperlink = get_hyperlink(page_txt)
		if hyperlink in visited_links:
			print("It leads to an infinite loop !")
			break
		if hyperlink:
			visited_links.add(hyperlink)
			visited_pages.append(get_page_title(page_txt))
			search_item = hyperlink.split('/')[-1].replace('_', ' ')
		else:
			print(": It leads to a dead end !")
			break
   
if __name__ == "__main__":
	main()