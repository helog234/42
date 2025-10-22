from django.db import models
from utils import BaseMovie

class Movie(BaseMovie):
    created = models.DateTimeField(auto_now_add=True)
    updated = models.DateTimeField(auto_now=True)

