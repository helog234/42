from django.http import HttpResponse, HttpRequest
from utils import execute_sql_query_with_params

def init(request: HttpRequest) -> HttpResponse:
    query = """
    CREATE TABLE IF NOT EXISTS ex00_movies(
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