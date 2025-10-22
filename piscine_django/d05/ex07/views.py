from django.shortcuts import render
from .models import Movie
from django.http import HttpResponse, HttpRequest
from django.views.decorators.csrf import csrf_exempt

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
    html = "<table border='1'><tr><th>Title</th><th>Episode Number</th><th>Opening Crawl</th><th>Director</th><th>Producer</th><th>Release Date</th><th>Created</th><th>Updated</th></tr>"
    for movie in movies:
        html += f"<tr><td>{movie.title}</td><td>{movie.episode_nb}</td><td>{movie.opening_crawl if movie.opening_crawl else ''}</td><td>{movie.director}</td><td>{movie.producer}</td><td>{movie.release_date}</td><td>{movie.created}</td><td>{movie.updated}</td></tr>"
    html += "</table>"
    return HttpResponse(html)

@csrf_exempt
def update(request: HttpRequest) -> HttpResponse:
    if request.method == 'GET':
        movies = Movie.objects.all().order_by('episode_nb')
        if not movies:
            return HttpResponse("No data available.")
        html = """
        <form method="GET">
            <select name="episode_nb" onchange="this.form.submit()">
                <option value="">Select a movie</option>
        """
        selected_episode_nb = request.GET.get('episode_nb', '')
        opening_crawl_value = ''
        for movie in movies:
            selected_attr = 'selected' if str(movie.episode_nb) == selected_episode_nb else ''
            html += f'<option value="{movie.episode_nb}" {selected_attr}>{movie.title}</option>'
            if str(movie.episode_nb) == selected_episode_nb:
                opening_crawl_value = movie.opening_crawl or ''
        html += f"""
            </select>
        </form>
        <form method="POST">
            <input type="hidden" name="episode_nb" value="{selected_episode_nb}">
            <textarea name="opening_crawl" rows="10" cols="50">{opening_crawl_value}</textarea>
            <br>
            <input type="submit" value="Update">
        </form>
        """
        return HttpResponse(html)
    elif request.method == 'POST':
        episode_nb = request.POST.get('episode_nb')
        opening_crawl = request.POST.get('opening_crawl')
        if not episode_nb:
            return HttpResponse("No movie selected.")
        try:
            movie = Movie.objects.get(episode_nb=episode_nb)
            movie.opening_crawl = opening_crawl
            movie.save()
            return HttpResponse(f"Movie '{movie.title}' updated successfully.")
        except Movie.DoesNotExist:
            return HttpResponse("Movie not found.")
        return HttpResponse(html)