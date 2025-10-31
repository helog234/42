from django.urls import path
from . import views

urlpatterns = [
    path('', views.HomeView.as_view(), name='home'),
    path('lobby/', views.LobbyView.as_view(), name='chat_lobby'),
	path('room/<str:room_name>/', views.ChatRoomView.as_view(), name='chat_room'),
]