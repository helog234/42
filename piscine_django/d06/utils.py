from django.http import HttpResponse, HttpRequest
from django.conf import settings
import random

# Create your views here.
def index(request: HttpRequest) -> HttpResponse:
    # user sessions last 42 seconds and needs a new name each time
	if 'name' not in request.session:
		request.session['name'] = random.choice(settings.RANDOM_NAMES)
		request.session.set_expiry(42)
	name = request.session['name']
	return HttpResponse(f"Hello {name}!")