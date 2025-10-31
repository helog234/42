from django.shortcuts import render, get_object_or_404, redirect
from .models import ChatRoom
from django.views import View
from django.contrib.auth.mixins import LoginRequiredMixin

class HomeView(View):
    def get(self, request):
        if request.user.is_authenticated:
            return redirect('chat_lobby')
        else:
            return redirect('account_page')

class LobbyView(View):
    def get(self, request, *args, **kwargs):
        chat_rooms = ChatRoom.objects.all()
        context = {'chat_rooms': chat_rooms}
        return render(request, 'chat/lobby.html', context)

class ChatRoomView(LoginRequiredMixin, View):
    def get(self, request, room_name, *args, **kwargs):
        chat_room = get_object_or_404(ChatRoom, name=room_name)
        
        context = {
            'chat_room': chat_room,
            'room_name': room_name
        }
        return render(request, 'chat/room.html', context)