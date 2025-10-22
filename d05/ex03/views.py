from ex01.models import Movie
from django.http import HttpResponse, HttpRequest

# Create your views here.
def populate(request: HttpRequest) -> HttpResponse:
	movies = [
		{
			"episode_nb": 1,
			"title": "The Phantom Menace",
			"director": "George Lucas",
			"producer": "Rick McCallum",
			"release_date": "1999-05-19"
		},
		{
			"episode_nb": 2,
			"title": "Attack of the Clones",
			"director": "George Lucas",
			"producer": "Rick McCallum",
			"release_date": "2002-05-16"
		},
		{
			"episode_nb": 3,
			"title": "Revenge of the Sith",
			"director": "George Lucas",
			"producer": "Rick McCallum",
			"release_date": "2005-05-19"
		},
		{
			"episode_nb": 4,
			"title": "A New Hope",
			"director": "George Lucas",
			"producer": "Gary Kurtz, Rick McCallum",
			"release_date": "1977-05-25"
		},
		{
			"episode_nb": 5,
			"title": "The Empire Strikes Back",
			"director": "Irvin Kershner",
			"producer": "Gary Kurtz, Rick McCallum",
			"release_date": "1980-05-17"
		},
		{
			"episode_nb": 6,
			"title": "Return of the Jedi",
			"director": "Richard Marquand",
			"producer": "Howard G. Kazanjian, George Lucas, Rick McCallum",
			"release_date": "1983-05-25"
		},
		{
			"episode_nb": 7,
			"title": "The Force Awakens",
			"director": "J. J. Abrams",
			"producer": "Kathleen Kennedy, J. J. Abrams, Bryan Burk",
			"release_date": "2015-12-11"
		}
	]
	messages = []
	for movie in movies:
		try:
			m = Movie(
				title=movie['title'],
				director=movie['director'],
				producer=movie['producer'],
				release_date=movie['release_date'],
				episode_nb=movie['episode_nb']
			)
			m.save()
			messages.append("OK")
		except Exception as e:
			messages.append(f"Error adding movie {movie['episode_nb']} - {movie['title']}: {str(e)}")
	return HttpResponse("<br>".join(messages))

def display(request: HttpRequest) -> HttpResponse:
	movies = Movie.objects.all().order_by('episode_nb')
	if not movies:
		return HttpResponse("No data available.")
	html = "<html><body>"
	for movie in movies:
		html += f"<h2>Episode {movie.episode_nb} - {movie.title}</h2>"
		html += f"<p><strong>Director:</strong> {movie.director}</p>"
		html += f"<p><strong>Producer:</strong> {movie.producer}</p>"
		html += f"<p><strong>Release Date:</strong> {movie.release_date}</p>"
		if movie.opening_crawl:
			html += f"<p><strong>Opening Crawl:</strong> {movie.opening_crawl}</p>"
		else:
			html += "<p><strong>Opening Crawl:</strong> N/A</p>"
		html += "<hr>"
	html += "</body></html>"
	return HttpResponse(html) 