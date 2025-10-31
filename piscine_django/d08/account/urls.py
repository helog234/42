from django.urls import path
from . import views

urlpatterns = [
    path('', views.account_view, name='account_page'), 

	# --- Endpoints de SOUMISSION (POST) ---
    path('ajax/login/', views.ajax_login_view, name='ajax_login'),
    path('ajax/logout/', views.ajax_logout_view, name='ajax_logout'),
    path('ajax/register/', views.ajax_register_view, name='ajax_register'),
    path('ajax/navbar/', views.ajax_navbar_view, name='ajax_navbar'),

    # --- Endpoints de NAVIGATION (GET) ---
    # .as_view() pour les classes
    path('ajax/get_login/', views.LoginView.as_view(), name='ajax_get_login'),
    path('ajax/get_register/', views.RegisterView.as_view(), name='ajax_get_register'),
]