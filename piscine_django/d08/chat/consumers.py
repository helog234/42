from channels.generic.websocket import AsyncWebsocketConsumer
import json
import logging
from .models import ChatRoom, ChatMessage
from channels.db import database_sync_to_async

logger = logging.getLogger(__name__)
connected_users = {}

class ChatConsumer(AsyncWebsocketConsumer):
    async def connect(self):
        self.room_name = self.scope['url_route']['kwargs']['room_name']
        self.room_group_name = f'chat_{self.room_name}'
        self.user = self.scope['user']
        await self.channel_layer.group_add(
            self.room_group_name,
            self.channel_name
        )
        
        await self.accept()
        # Add user to the connected users list
        if self.room_name not in connected_users:
            connected_users[self.room_name] = []

        connected_users[self.room_name].append(self.user.username)
        await self.channel_layer.group_send(
            self.room_group_name,
            {
                'type': 'connected_users_list',
                'users': connected_users[self.room_name]
            }
        )

        try:
            chat_room = await database_sync_to_async(ChatRoom.objects.get)(name=self.room_name)
            last_messages = await database_sync_to_async(
                lambda: list(
                    ChatMessage.objects
                    .filter(room=chat_room)
                    .select_related('user')
                    .order_by('-timestamp')[:3]
                )
            )()
            
            last_messages.reverse()
            
            for message in last_messages:
                await self.send(text_data=json.dumps({
                    'message': message.content,
                    'username': message.user.username
                }))
        except ChatRoom.DoesNotExist:
            logger.error(f"ChatRoom {self.room_name} does not exist")
        
        await self.channel_layer.group_send(
            self.room_group_name,
            {
                'type': 'user_activity',
                'activity': f"{self.user.username} has joined the chat",
                'username': 'System'
            }
        )
        logger.info(f"{self.user.username} has joined {self.room_name}")

    async def disconnect(self, close_code):
        
        if self.room_name in connected_users and self.user.username in connected_users[self.room_name]:
            connected_users[self.room_name].remove(self.user.username)
            await self.channel_layer.group_send(
                self.room_group_name,
                {
                    'type': 'connected_users_list',
                    'users': connected_users[self.room_name]
                }
            )
        await self.channel_layer.group_send(
            self.room_group_name,
            {
                'type': 'user_activity',
                'activity': f"{self.user.username} has left the chat",
                'username': 'System'
            }
        )
        
        await self.channel_layer.group_discard(
            self.room_group_name,
            self.channel_name
        )

    async def receive(self, text_data):
        data = json.loads(text_data)
        message = data['message']

        try:
            chat_room = await database_sync_to_async(ChatRoom.objects.get)(name=self.room_name)
            await database_sync_to_async(ChatMessage.objects.create)(
                room=chat_room,
                user=self.user,
                content=message
            )
        except ChatRoom.DoesNotExist:
            logger.error(f"ChatRoom {self.room_name} does not exist")
            return
        
        await self.channel_layer.group_send(
            self.room_group_name,
            {
                'type': 'chat_message',
                'message': message,
                'username': self.user.username,
            }
        )

    async def chat_message(self, event):
        message = event['message']
        username = event['username']

        await self.send(text_data=json.dumps({
            'message': message,
            'username': username
        }))
        
    async def connected_users_list(self, event):
        users = event['users']
        await self.send(text_data=json.dumps({
            'connected_users': users
        }))
        
    async def user_activity(self, event):
        username = event['username']
        activity = event['activity']

        await self.send(text_data=json.dumps({
            'username': username,
            'activity': activity
        }))
