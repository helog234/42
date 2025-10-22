from django.shortcuts import render
from ex01.models import Movie
from ex03.views import populate, display
from django.http import HttpResponse, HttpRequest
from django.views.decorators.csrf import csrf_exempt

populate = populate
display = display

@csrf_exempt
def remove(request: HttpRequest) -> HttpResponse:
	if request.method == 'GET':
		movies = Movie.objects.all().order_by('episode_nb')
		if not movies:
			return HttpResponse("No data available.")
		html = """
		<form method="POST">
			<select name="episode_nb">
		"""
		for movie in movies:
			html += f'<option value="{movie.episode_nb}">{movie.title}</option>'
		html += """
			</select>
			<button type="submit" name="remove">Remove</button>
		</form>
		"""
		return HttpResponse(html)
	elif request.method == 'POST':
		episode_nb = request.POST.get('episode_nb')
		try:
			movie = Movie.objects.get(episode_nb=episode_nb)
			movie.delete()
			return HttpResponse(f"Movie '{movie.title}' removed successfully.")
		except Movie.DoesNotExist:
			return HttpResponse("Movie not found.")
	else:
		return HttpResponse("Method not allowed", status=405)