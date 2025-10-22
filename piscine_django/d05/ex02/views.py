from django.http import HttpResponse, HttpRequest
from utils import execute_sql_query_with_params, get_db_connection

# Create your views here.
def init(request: HttpRequest) -> HttpResponse:
    query = """
    CREATE TABLE IF NOT EXISTS ex02_movies(
        title VARCHAR(64) UNIQUE NOT NULL,
        episode_nb INT PRIMARY KEY,
        opening_crawl TEXT,
        director VARCHAR(32) NOT NULL,
        producer VARCHAR(128) NOT NULL,
        release_date DATE NOT NULL
    );
    """
    result = execute_sql_query_with_params(query)
    return HttpResponse(result)


def populate(request: HttpRequest) -> HttpResponse:
    try:
        conn = get_db_connection()
        movies = [
            {
                "title": "The Phantom Menace",
                "episode_nb": 1,
                "opening_crawl": None,
                "director": "George Lucas",
                "producer": "Rick McCallum",
                "release_date": "1999-05-19"
            },
            {
                "title": "Attack of the Clones",
                "episode_nb": 2,
                "opening_crawl": None,
                "director": "George Lucas",
                "producer": "Rick McCallum",
                "release_date": "2002-05-16"
            },
            {
                "title": "Revenge of the Sith",
                "episode_nb": 3,
                "opening_crawl": None,
                "director": "George Lucas",
                "producer": "Rick McCallum",
                "release_date": "2005-05-19"
            },
            {
                "title": "A New Hope",
                "episode_nb": 4,
                "opening_crawl": None,
                "director": "George Lucas",
                "producer": "Gary Kurtz, Rick McCallum",
                "release_date": "1977-05-25"
            },
            {
                "title": "The Empire Strikes Back",
                "episode_nb": 5,
                "opening_crawl": None,
                "director": "Irvin Kershner",
                "producer": "Gary Kutz, Rick McCallum",
                "release_date": "1980-05-17"
            },
            {
                "title": "Return of the Jedi",
                "episode_nb": 6,
                "opening_crawl": None,
                "director": "Richard Marquand",
                "producer": "Howard G. Kazanjian, George Lucas, Rick McCallum",
                "release_date": "1983-05-25"
            },
            {
                "title": "The Force Awakens",
                "episode_nb": 7,
                "opening_crawl": None,
                "director": "J. J. Abrams",
                "producer": "Kathleen Kennedy, J. J. Abrams, Bryan Burk",
                "release_date": "2015-12-11"
            }
        ]
        results = []
        
        for movie in movies:
            query = """
            INSERT INTO ex02_movies (title, episode_nb, opening_crawl, director, producer, release_date)
            VALUES (%s, %s, %s, %s, %s, %s)
            ON CONFLICT (episode_nb) DO NOTHING;
            """
            params = (
                movie["title"],
                movie["episode_nb"],
                movie["opening_crawl"],
                movie["director"],
                movie["producer"],
                movie["release_date"]
            )
            result = execute_sql_query_with_params(query, params)
            if result == "OK":
                results.append(f"{result}")
            else:
                results.append(f"{movie['title']}: {result}")
        conn.close()
        return HttpResponse("<br>".join(results))
    except Exception as e:
        return HttpResponse(str(e))
    

def display(request: HttpRequest) -> HttpResponse:
    query = "SELECT * FROM ex02_movies;"
    result = execute_sql_query_with_params(query, return_result=True)
    if isinstance(result, str):
        return HttpResponse(result)
    if not result:
        return HttpResponse("No data available")
    
    html = "<html><body><table border='1'><tr><th>Title</th><th>Episode Number</th><th>Opening Crawl</th><th>Director</th><th>Producer</th><th>Release Date</th></tr>"
    for row in result:
        html += "<tr>" + "".join(f"<td>{col if col is not None else ''}</td>" for col in row) + "</tr>"
    html += "</table></body></html>"
    return HttpResponse(html)