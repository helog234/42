#!/usr/bin/python3
import requests
import sys
import dewiki
import json

def request_wikipedia(page_name):
	base_url = "https://en.wikipedia.org/w/api.php"
 
	params = {
		'action': 'parse',
		'page': page_name,
		'format': 'json',
		'prop': 'wikitext',
  		'redirects': True,
		'formatversion': 2,
	}
	
	response = requests.get(base_url, params=params)
	if response.status_code != 200:
		print(f"Error: Unable to fetch data for {page_name}")
		return None

	data = json.loads(response.text)
	if 'error' in data:
		print(f"Error: {data['error']['info']}")
		return None

	if 'parse' not in data or 'wikitext' not in data['parse']:
		print(f"Error: No wikitext found for {page_name}")
		return None

	text = dewiki.from_string(data['parse']['wikitext'])
	return text

def check_args():
	if len(sys.argv) != 2:
		print("Usage: python request_wikipedia.py <page_name>")
		sys.exit(1)
  
def write_to_file(text, filename):
	filename = filename + '.wiki'
	try:
		with open(filename, 'w', encoding='utf-8') as file:
			file.write(text)
	except IOError as e:
		print(f"Error writing to file {filename}: {e}")

if __name__ == "__main__":
	check_args()
	text = request_wikipedia(sys.argv[1])
	if text:
		write_to_file(text, sys.argv[1])

