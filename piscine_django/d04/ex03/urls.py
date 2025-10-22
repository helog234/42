from django.urls import path

from . import views

urlpatterns = [
    path('', views.fifty_shades_of_bic, name='index'),
]
