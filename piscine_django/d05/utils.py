import psycopg2
from django.conf import settings
from django.http import HttpResponse, HttpRequest
from django.views.decorators.csrf import csrf_exempt
from django.db import models

def get_db_connection():
    """Returns a connection to the database using settings from Django"""
    return psycopg2.connect(
        dbname=settings.DATABASES['default']['NAME'],
        user=settings.DATABASES['default']['USER'],
        password=settings.DATABASES['default']['PASSWORD'],
        host=settings.DATABASES['default']['HOST'],
        port=settings.DATABASES['default']['PORT']
    )

def execute_sql_query_with_params(query, params=None, return_result=False):
    """Executes a SQL query with parameters (safer)"""
    try:
        conn = get_db_connection()
        with conn.cursor() as cursor:
            cursor.execute(query, params)
            conn.commit()
            if return_result:
                return cursor.fetchall()
        conn.close()
        return "OK"
    except Exception as e:
        return str(e)
    
def create_table_view(table_name):
    """Returns a view function that creates a table with the given name"""
    def init(request: HttpRequest) -> HttpResponse:
        query = f"""
        CREATE TABLE IF NOT EXISTS {table_name}(
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
    return init

def create_table_with_timestamps_view(table_name):
    def init(request):
        query = f"""
        CREATE TABLE IF NOT EXISTS {table_name}(
            title VARCHAR(64) UNIQUE NOT NULL,
            episode_nb INT PRIMARY KEY,
            opening_crawl TEXT,
            director VARCHAR(32) NOT NULL,
            producer VARCHAR(128) NOT NULL,
            release_date DATE NOT NULL,
            created TIMESTAMP DEFAULT NOW(),
            updated TIMESTAMP DEFAULT NOW()
        );
        
        CREATE OR REPLACE FUNCTION update_changetimestamp_column()
        RETURNS TRIGGER AS $$
        BEGIN
            NEW.updated = now();
            NEW.created = OLD.created;
            RETURN NEW;
        END;
        $$ language 'plpgsql';
        
        CREATE TRIGGER update_films_changetimestamp BEFORE UPDATE
        ON {table_name} FOR EACH ROW EXECUTE PROCEDURE
        update_changetimestamp_column();
        """
        result = execute_sql_query_with_params(query)
        return HttpResponse(result)
    return init

def populate_table_view(table_name):
    """Returns a view function that populates a table with the given name"""
    def populate(request: HttpRequest) -> HttpResponse:
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
            query = f"""
            INSERT INTO {table_name} (title, episode_nb, opening_crawl, director, producer, release_date)
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
        return HttpResponse("<br>".join(results))
    return populate
    
def display_table_view(table_name):
    """Returns a view function that displays all records from the given table"""
    def display(request: HttpRequest) -> HttpResponse:
        query = f"SELECT * FROM {table_name};"
        result = execute_sql_query_with_params(query, return_result=True)
        if isinstance(result, str):
            return HttpResponse(result)
        if not result:
            return HttpResponse("No data available")
        html = "<table border='1'><tr><th>Title</th><th>Episode Number</th><th>Opening Crawl</th><th>Director</th><th>Producer</th><th>Release Date</th></tr>"
        for row in result:
             html += "<tr>" + "".join(f"<td>{col if col is not None else ''}</td>" for col in row) + "</tr>"
        html += "</table>"
        return HttpResponse(html)
    return display

def display_table_view_with_timestamps(table_name):
    def display(request):
        query = f"SELECT * FROM {table_name};"
        result = execute_sql_query_with_params(query, return_result=True)
        if isinstance(result, str):
            return HttpResponse(result)
        if not result:
            return HttpResponse("No data available")
        html = "<table border='1'><tr><th>Title</th><th>Episode Number</th><th>Opening Crawl</th><th>Director</th><th>Producer</th><th>Release Date</th><th>Created</th><th>Updated</th></tr>"
        for row in result:
             html += "<tr>" + "".join(f"<td>{col if col is not None else ''}</td>" for col in row) + "</tr>"
        html += "</table>"
        return HttpResponse(html)
    return display


def remove_table_view(table_name):
    """Returns a view function that removes a record from the given table"""
    @csrf_exempt
    def remove(request: HttpRequest) -> HttpResponse:
        if request.method == 'GET':
            query = f"SELECT episode_nb, title FROM {table_name};"
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
            query = f"DELETE FROM {table_name} WHERE episode_nb = %s;"
            result = execute_sql_query_with_params(query, (episode_nb,))
            return HttpResponse(result)
        else:
            return HttpResponse("Method not allowed", status=405)
    return remove


class BaseMovie(models.Model):
    title = models.CharField(max_length=64, unique=True)
    episode_nb = models.IntegerField(primary_key=True)
    opening_crawl = models.TextField(null=True, blank=True)
    director = models.CharField(max_length=32)
    producer = models.CharField(max_length=128)
    release_date = models.DateField()

    class Meta:
        abstract = True

    def __str__(self):
        return self.title

