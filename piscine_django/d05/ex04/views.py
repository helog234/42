from django.http import HttpResponse, HttpRequest
from utils import execute_sql_query_with_params, create_table_view, populate_table_view, display_table_view
from django.views.decorators.csrf import csrf_exempt

init = create_table_view("ex04_movies")
populate = populate_table_view("ex04_movies")
display =  display_table_view("ex04_movies")

@csrf_exempt
def remove(request: HttpRequest) -> HttpResponse:
    if request.method == 'GET':
        query = "SELECT episode_nb, title FROM ex04_movies;"
        movies = execute_sql_query_with_params(query, return_result=True)
        if isinstance(movies, str) or not movies:
            return HttpResponse("No data available")
        
        html = """
        <form method="POST">
            <select name="episode_nb">
        """
        for episode_nb, title in movies:
            html += f'<option value="{episode_nb}">{title}</option>'
        html += """
            </select>
            <button type="submit" name="remove">Remove</button>
        </form>
        """
        return HttpResponse(html)
    elif request.method == 'POST':
        episode_nb = request.POST.get('episode_nb')
        query = "DELETE FROM ex04_movies WHERE episode_nb = %s;"
        result = execute_sql_query_with_params(query, (episode_nb,))
        return HttpResponse(result)
    else:
        return HttpResponse("Method not allowed", status=405)