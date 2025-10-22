from django.urls import path
from . import views

urlpatterns = [
	path('ex10/', views.index, name='ex10'),
]