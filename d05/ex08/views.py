from django.http import HttpResponse, HttpRequest
from utils import get_db_connection, execute_sql_query_with_params

# Create your views here.
def init(request: HttpRequest) -> HttpResponse:
    query = """
    CREATE TABLE IF NOT EXISTS ex08_planets(
        id SERIAL PRIMARY KEY,
        name VARCHAR(64) UNIQUE NOT NULL,
        climate VARCHAR,
        diameter INT,
        orbital_period INT,
        population BIGINT,
        rotation_period INT,
        surface_water FLOAT,
        terrain VARCHAR(128)
    );
 
    CREATE TABLE IF NOT EXISTS ex08_people(
        id SERIAL PRIMARY KEY,
        name VARCHAR(64) UNIQUE NOT NULL,
        birth_year VARCHAR(32),
        gender VARCHAR(32),
        eye_color VARCHAR(32),
        hair_color VARCHAR(32),
        height INT,
        mass FLOAT,
        homeworld VARCHAR(64) REFERENCES ex08_planets(name)
    );
    """
    result = execute_sql_query_with_params(query)
    return HttpResponse(result)

def populate(request: HttpRequest) -> HttpResponse:
    try:
        conn = get_db_connection()
        with conn.cursor() as cursor:
            with open('ex08/planets.csv', 'r') as f:
                cursor.copy_from(
                    f,
                    'ex08_planets',
                    columns=('name', 'climate', 'diameter', 'orbital_period', 'population', 'rotation_period', 'surface_water', 'terrain'),
                    sep='\t',
                    null='NULL'
                )
            
            with open('ex08/people.csv', 'r') as f:
                cursor.copy_from(
                    f,
                    'ex08_people', 
                    columns=('name', 'birth_year', 'gender', 'eye_color', 'hair_color', 'height', 'mass', 'homeworld'),
                    sep='\t',
                    null='NULL'
                )
        
        conn.commit()
        return HttpResponse("OK")
    except Exception as e:
        return HttpResponse(f"Error: {e}")
    finally:
        conn.close()

def display(request: HttpRequest) -> HttpResponse:
    conn = get_db_connection()
    try:
        with conn.cursor() as cursor:
            cursor.execute("SELECT * FROM ex08_people;")
            people = cursor.fetchall()
            if not people:
                return HttpResponse("No data available")
            html = "<table border='1'><tr><th>ID</th><th>Name</th><th>Birth Year</th><th>Gender</th><th>Eye Color</th><th>Hair Color</th><th>Height</th><th>Mass</th><th>Homeworld</th></tr>"
            for person in people:
                html += f"<tr><td>{person[0]}</td><td>{person[1]}</td><td>{person[2]}</td><td>{person[3]}</td><td>{person[4]}</td><td>{person[5]}</td><td>{person[6]}</td><td>{person[7]}</td><td>{person[8]}</td></tr>"
            html += "</table>"
            return HttpResponse(html)
    except Exception as e:
        return HttpResponse("No data available")
    finally:
        conn.close()
        
