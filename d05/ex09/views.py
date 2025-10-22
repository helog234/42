from django.http import HttpResponse, HttpRequest
from .models import People

# Create your views here.
def display(request: HttpRequest) -> HttpResponse:
	people = People.objects.all().order_by('name')
	if not people:
		return HttpResponse("No data available, please use the following command line before use: python3 manage.py loaddata ex09_initial_data.json")

	output = "<table border='1'><tr><th>Name</th><th>Homeworld</th><th>Climate</th></tr>"
	for person in people:
		if person.homeworld and person.homeworld.climate and "windy" in person.homeworld.climate.lower():
			output += f"<tr><td>{person.name}</td><td>{person.homeworld.name}</td><td>{person.homeworld.climate}</td></tr>"
	output += "</table>"
	return HttpResponse(output)
