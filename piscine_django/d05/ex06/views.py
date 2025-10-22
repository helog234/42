from django.http import HttpResponse, HttpRequest
from utils import execute_sql_query_with_params, create_table_with_timestamps_view, populate_table_view, display_table_view_with_timestamps, remove_table_view
from django.views.decorators.csrf import csrf_exempt

init = create_table_with_timestamps_view("ex06_movies")
populate = populate_table_view("ex06_movies")
display =  display_table_view_with_timestamps("ex06_movies")
remove = remove_table_view("ex06_movies")

@csrf_exempt
def update(request: HttpRequest) -> HttpResponse:
    if request.method == 'GET':
        query = "SELECT episode_nb, title, opening_crawl FROM ex06_movies;"
        movies = execute_sql_query_with_params(query, return_result=True)
        if isinstance(movies, str) or not movies:
            return HttpResponse("No data available")
        
        selected_episode_nb = request.GET.get('episode_nb', '')
        opening_crawl_value = ''
        
        # Trouver le opening_crawl du film sélectionné
        for episode_nb, title, opening_crawl in movies:
            if str(episode_nb) == selected_episode_nb:
                opening_crawl_value = opening_crawl or ''
                break
        
        html = """
        <form method="GET">
            <select name="episode_nb" onchange="this.form.submit()">
                <option value="">Select a movie</option>
        """
        for episode_nb, title, opening_crawl in movies:
            selected_attr = 'selected' if str(episode_nb) == selected_episode_nb else ''
            html += f'<option value="{episode_nb}" {selected_attr}>{title}</option>'
        
        html += f"""
            </select>
        </form>
        
        <form method="POST">
            <input type="hidden" name="episode_nb" value="{selected_episode_nb}">
            <textarea name="opening_crawl" rows="10" cols="50" placeholder="Enter opening crawl here...">{opening_crawl_value}</textarea>
            <br><br>
            <button type="submit">Update</button>
        </form>
        """
        return HttpResponse(html)
    
    elif request.method == 'POST':
        episode_nb = request.POST.get('episode_nb')
        opening_crawl = request.POST.get('opening_crawl')
        
        if not episode_nb:
            return HttpResponse("No movie selected")
        
        query = "UPDATE ex06_movies SET opening_crawl = %s WHERE episode_nb = %s;"
        execute_sql_query_with_params(query, (opening_crawl, episode_nb))
        
        return HttpResponse(f"Updated successfully.")
