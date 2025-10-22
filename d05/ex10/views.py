from django.http import HttpResponse, HttpRequest
from django.views.decorators.csrf import csrf_exempt
from .models import Movies, People, Planets

# Create your views here.
@csrf_exempt
def index(request: HttpRequest) -> HttpResponse:
    if request.method == 'POST':
        params = []
        for key, value in request.POST.items():
            if value and key != 'csrfmiddlewaretoken':
                params.append(f"{key}={value}")
        redirect_url = f"/ex10/?{'&'.join(params)}"
        return HttpResponse(f'<script>window.location.href="{redirect_url}"</script>')
    
    # GET
    minReleaseDate = request.GET.get('minReleaseDate', '')
    maxReleaseDate = request.GET.get('maxReleaseDate', '')
    planetDiameter = request.GET.get('planetDiameter', '')
    characterGender = request.GET.get('characterGender', '')
    
    genderOptions = People.objects.values_list('gender', flat=True).distinct().exclude(gender__isnull=True)
    options_html = ''.join(f'<option value="{gender}" {"selected" if gender == characterGender else ""}>{gender}</option>' for gender in genderOptions)
    
    html = f"""
    <form method="POST">
        <label for="minReleaseDate">Movies minimum release date:</label>
        <input type="date" id="minReleaseDate" name="minReleaseDate" value="{minReleaseDate}"><br><br>
        
        <label for="maxReleaseDate">Movies maximum release date:</label>
        <input type="date" id="maxReleaseDate" name="maxReleaseDate" value="{maxReleaseDate}"><br><br>
        
        <label for="planetDiameter">Planet diameter greater than:</label>
        <input type="number" id="planetDiameter" name="planetDiameter" value="{planetDiameter}"><br><br>
        
        <label for="characterGender">Character gender:</label>
        <select id="characterGender" name="characterGender">
            <option value="">Select Gender</option>
            {options_html}
        </select><br><br>
        
        <button type="submit">Search</button>
    </form>
    """
    
    if minReleaseDate and maxReleaseDate and planetDiameter and characterGender:
        results = People.objects.filter(
            gender=characterGender,
            movies__release_date__gte=minReleaseDate,
            movies__release_date__lte=maxReleaseDate,
            homeworld__diameter__gte=int(planetDiameter)
        ).select_related('homeworld').prefetch_related('movies').distinct()
        
        if results:
            html += "<h3>Results:</h3><ul>"
            for person in results:
                for movie in person.movies.filter(release_date__gte=minReleaseDate, release_date__lte=maxReleaseDate):
                    html += f"<li>{movie.title} - {person.name} - {person.gender} - {person.homeworld.name if person.homeworld else 'Unknown'} - {person.homeworld.diameter if person.homeworld else 'Unknown'}</li>"
            html += "</ul>"
        else:
            html += "<p>Nothing corresponding to your research</p>"
    
    return HttpResponse(html)
      