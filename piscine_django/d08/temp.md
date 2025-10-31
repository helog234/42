Absolument. Voici un guide conceptuel pour aborder ce projet final, exercice par exercice, en se concentrant sur les technologies et les logiques à mettre en place, sans donner de code.

[cite\_start]L'objectif global de ce projet est de construire une application web dynamique en une seule fois[cite: 39]. [cite\_start]Vous commencerez par une authentification moderne sans rechargement de page (AJAX) [cite: 51][cite\_start], puis vous construirez une application de chat complète en temps réel (WebSockets)[cite: 82, 104, 113].

[cite\_start]La contrainte principale est de n'utiliser que **JQuery** comme bibliothèque JavaScript[cite: 38].

-----

## Configuration Initiale du Projet

Avant de commencer l'exercice 00, vous devez :

1.  [cite\_start]Créer votre machine virtuelle et la configurer[cite: 21, 22].
2.  [cite\_start]Créer un projet Django unique nommé `d09`[cite: 50].
3.  [cite\_start]Penser à générer un fichier `requirements.txt` à la fin[cite: 42].

-----

## Exercice 00 : AJAX my formulah\!

[cite\_start]Cet exercice consiste à créer un système de connexion et de déconnexion sur une seule page, `/account` [cite: 52][cite\_start], sans jamais la recharger[cite: 56, 63].

### Concepts Clés à Maîtriser

**Backend (Django)**

  * [cite\_start]**Vues conditionnelles :** Votre vue `/account` doit savoir si l'utilisateur est déjà connecté (`request.user.is_authenticated`) ou non, pour afficher le bon contenu[cite: 53, 57].
  * [cite\_start]**Formulaires Django :** Utilisez le `AuthenticationForm` qui vous est offert[cite: 68]. Il gère la validation du login et du mot de passe.
  * **Authentification :** Utilisez les fonctions `login()` et `logout()` de `django.contrib.auth` pour gérer la session de l'utilisateur.
  * [cite\_start]**Réponses JSON :** Puisque la communication se fait par AJAX[cite: 51], vos vues (surtout celles qui traitent le POST) ne doivent pas renvoyer du HTML, mais un `JsonResponse`.
      * Pour une connexion réussie, renvoyez un JSON (ex: `{'success': True, 'user': request.user.username}`).
      * [cite\_start]Pour une connexion échouée, renvoyez les erreurs du formulaire (ex: `{'success': False, 'errors': form.errors.as_json()}`)[cite: 54].
      * [cite\_start]La déconnexion doit aussi renvoyer un JSON de succès[cite: 58].

**Frontend (JQuery)**

  * [cite\_start]**Interception d'événements :** Vous devez utiliser `$.on('submit', ...)` pour intercepter l'envoi du formulaire de connexion [cite: 53] [cite\_start]et `$.on('click', ...)` pour le bouton de déconnexion[cite: 58].
  * **`event.preventDefault()` :** C'est la fonction **cruciale** pour empêcher le formulaire de se soumettre normalement et de recharger la page.
  * [cite\_start]**Requêtes AJAX :** Utilisez la fonction `$.ajax()` (ou son raccourci `$.post()`) pour envoyer les données du formulaire au serveur en méthode **POST**[cite: 53, 58].
  * **Gestion du CSRF Token :** N'oubliez pas d'inclure le `{% csrf_token %}` dans votre template et de le récupérer avec JQuery pour l'envoyer dans les en-têtes de votre requête AJAX. Sans cela, vos requêtes POST échoueront.
  * **Manipulation du DOM :** En fonction de la réponse JSON du serveur (dans le `.done()` ou `.fail()` de votre appel AJAX) :
      * [cite\_start]Cachez le formulaire et affichez le message "Logged as..."[cite: 55, 57].
      * [cite\_start]Affichez les erreurs de validation sous les champs du formulaire[cite: 54].
      * [cite\_start]Cachez le message "Logged as..." et ré-affichez le formulaire après déconnexion[cite: 59, 62].

-----

## Exercice 01 : Chat de base

[cite\_start]Ici, vous abandonnez AJAX pour les **WebSockets**[cite: 82]. [cite\_start]Vous allez créer une nouvelle application `chat` [cite: 77] [cite\_start]avec plusieurs salons de discussion[cite: 78].

### Concepts Clés à Maîtriser

**Backend (Django + Channels)**

  * [cite\_start]**Django Models :** Vous avez besoin d'un modèle pour stocker les noms des salons de discussion (`ChatRoom`, par exemple)[cite: 79].
  * [cite\_start]**Django Views :** Une vue pour lister les salons [cite: 78] [cite\_start]et une autre pour afficher la page d'un salon spécifique[cite: 80]. [cite\_start]Pensez à protéger l'accès aux salons uniquement aux utilisateurs connectés [cite: 83] (avec le décorateur `@login_required` par exemple).
  * **Django Channels :** C'est la bibliothèque Django pour gérer les WebSockets. Vous devrez l'installer (`pip install channels`).
  * **ASGI :** Configurer votre projet pour qu'il utilise l'ASGI (dans `settings.py` et `asgi.py`) au lieu du WSGI.
  * **Routing (Channels) :** Créer un `routing.py` (similaire à `urls.py`) pour diriger les connexions WebSocket (`ws://...`) vers un "Consumer".
  * **Consumers :** C'est l'équivalent d'une vue Django, mais pour les WebSockets. Vous créerez une classe (ex: `ChatConsumer`) qui hérite de `WebsocketConsumer` ou `AsyncWebsocketConsumer`.
  * **Méthodes du Consumer :**
      * [cite\_start]`connect()` : S'exécute quand un utilisateur se connecte[cite: 94]. C'est ici que vous l'accepterez et l'ajouterez à un "groupe" (un groupe par salon).
      * `disconnect()` : S'exécute quand il part. (Sera utile à l'ex03).
      * [cite\_start]`receive()` : S'exécute quand le serveur reçoit un message du client[cite: 86]. C'est ici que vous récupérez le message et le renvoyez à *tout le groupe*.
  * **Channel Layers (Groupes) :** C'est le concept central. [cite\_start]Pour que tout le monde dans *un même salon* reçoive le message[cite: 87], vous devez :
    1.  Dans `connect()`, ajouter l'utilisateur à un groupe (ex: `chat_nom_du_salon`).
    2.  Dans `receive()`, envoyer le message reçu à ce nom de groupe (broadcast).
    3.  [cite\_start]Envoyer le message "a rejoint le chat" au groupe dans la méthode `connect()`[cite: 94].

**Frontend (JQuery + API WebSocket)**

  * **API WebSocket :** JQuery n'a pas de fonction pour les WebSockets. Vous utiliserez l'objet natif JavaScript : `new WebSocket('ws://' + window.location.host + '/ws/chat/room_name/')`.
  * **Événements WebSocket :**
      * `websocket.onopen` : S'exécute lorsque la connexion est établie.
      * `websocket.onmessage` : S'exécute lorsque vous recevez un message *du serveur* (envoyé par le Consumer). [cite\_start]C'est ici que vous utiliserez JQuery pour `.append()` le message (avec le nom d'utilisateur [cite: 92][cite\_start]) à la liste des messages[cite: 87].
      * [cite\_start]`websocket.send()` : Vous lierez l'envoi du formulaire de chat à cette fonction (toujours avec `event.preventDefault()`) pour envoyer le message au serveur[cite: 86]. Le message sera typiquement un JSON (`JSON.stringify({...})`).

-----

## Exercice 02 : Historique

[cite\_start]Vous améliorez le chat pour afficher les 3 derniers messages lors de la connexion[cite: 105].

### Concepts Clés à Maîtriser

**Backend (Django)**

  * **Nouveau Modèle :** Vous devez créer un modèle `ChatMessage` pour stocker les messages. Il doit avoir un contenu (texte), un auteur (`ForeignKey` vers `User`), un salon (`ForeignKey` vers `ChatRoom`) et un `timestamp` (très important pour le tri).
  * **Sauvegarde des messages :** Dans votre `Consumer`, à la méthode `receive()`, avant de diffuser le message au groupe, vous devez le sauvegarder en base de données.
  * **Récupération de l'historique :** Dans votre `Consumer`, à la méthode `connect()`, **avant** d'accepter la connexion ou de joindre le groupe :
    1.  Interrogez la base de données pour récupérer les 3 derniers messages de ce salon (`ChatMessage.objects.filter(room=...).order_by('-timestamp')[:3]`).
    2.  Attention, ils seront du plus récent au plus ancien. [cite\_start]Vous devez les inverser pour les avoir dans le bon ordre (plus ancien au plus récent)[cite: 105].
    3.  Envoyez cette liste de messages (en JSON) *uniquement à l'utilisateur qui vient de se connecter* (en utilisant `self.send(...)` et non un envoi au groupe).

**Frontend (JQuery)**

  * Votre `websocket.onmessage` doit être capable de gérer deux types de messages : un message simple (objet JSON) ou une liste de messages (tableau JSON) venant de l'historique.

-----

## Exercice 03 : Userlist

[cite\_start]Vous ajoutez une liste des utilisateurs connectés qui se met à jour en temps réel[cite: 113].

### Concepts Clés à Maîtriser

**Backend (Django Channels)**

  * **Gestion de l'état :** C'est la partie la plus complexe. Channels ne sait pas nativement *qui* est dans un groupe. Vous devez le suivre vous-même. Une solution simple (sans Redis) est d'utiliser la **session Django** ou le **cache Django** pour stocker une liste de noms d'utilisateurs par salon.
  * **Mise à jour dans `connect()` :**
    1.  Ajoutez le nom de l'utilisateur (`self.scope['user'].username`) à la liste des connectés pour ce salon (dans le cache/session).
    2.  Récupérez la liste *complète* et à jour.
    3.  [cite\_start]Diffusez cette liste complète à *tout le groupe*[cite: 116].
  * **Mise à jour dans `disconnect()` :**
    1.  [cite\_start]Retirez le nom de l'utilisateur de la liste des connectés[cite: 117].
    2.  Diffusez la nouvelle liste mise à jour à *tout le groupe*.
    3.  [cite\_start]Diffusez également le message "\<username\> has left the chat" au groupe[cite: 117].
  * **Types de messages :** Votre communication WebSocket doit devenir plus structurée. Vous devriez envoyer des JSON avec un "type" pour que le frontend sache quoi faire :
      * `{'type': 'chat_message', 'user': '...', 'message': '...'}`
      * `{'type': 'user_list', 'users': ['user1', 'user2']}`
      * `{'type': 'user_join', 'user': '...'}`
      * [cite\_start]`{'type': 'user_leave', 'user': '...'}` [cite: 117]

**Frontend (JQuery)**

  * **`websocket.onmessage` :** Votre fonction doit maintenant être un "routeur". Elle doit lire le `type` du JSON reçu :
      * Si `type == 'chat_message'`, ajouter à la `<div>` des messages.
      * Si `type == 'user_join'` ou `'user_leave'`, ajouter le message système au chat.
      * [cite\_start]Si `type == 'user_list'`, vider la `<div>` de la liste des utilisateurs (`.html('')`) et la reconstruire en bouclant sur la liste `users` reçue[cite: 114, 115].

-----

## Exercice 04 : Scrool

C'est un exercice de finition, principalement CSS et un peu de JQuery.

### Concepts Clés à Maîtriser

**CSS**

  * [cite\_start]**Conteneur fixe :** Donnez à votre `<div>` qui contient les messages une `height` ou `max-height` fixe (ex: `400px`)[cite: 126].
  * **Débordement :** Appliquez la propriété `overflow-y: scroll;` (ou `auto`). [cite\_start]Cela fera apparaître la barre de défilement dès que le contenu dépassera la hauteur fixe[cite: 127].

**JQuery**

  * [cite\_start]**Auto-scroll :** Le but est que la barre soit toujours en bas[cite: 128].
  * À chaque fois que vous ajoutez un nouveau message à la `<div>` des messages (dans votre `websocket.onmessage`), vous devez forcer le scroll à aller en bas.
  * Pour ce faire, sélectionnez votre conteneur (ex: `var chatBox = $('#message-list')`) et réglez sa propriété `scrollTop` pour qu'elle soit égale à sa propriété `scrollHeight` :
      * `chatBox.scrollTop(chatBox[0].scrollHeight);`


# Guide Complet : WebSockets, Channels, Redis et Daphne

## 📚 Table des matières
1. [Les WebSockets - La base](#1-les-websockets)
2. [Django Channels - L'orchestrateur](#2-django-channels)
3. [Channel Layers - Le système de messagerie](#3-channel-layers)
4. [Redis - La boîte aux lettres](#4-redis)
5. [Daphne - Le serveur](#5-daphne)
6. [Comment tout fonctionne ensemble](#6-architecture-complète)
7. [Exemple pratique : Votre chat](#7-exemple-pratique)

---

## 1. Les WebSockets

### 🔍 C'est quoi ?

Un **WebSocket** est un protocole de communication bidirectionnel entre un client (navigateur) et un serveur.

### 📊 HTTP classique vs WebSocket

```
HTTP CLASSIQUE (comme une lettre postale) :
┌─────────┐                               ┌─────────┐
│ Client  │──── Requête (GET/POST) ────→  │ Serveur │
│         │                               │         │
│         │←─── Réponse (HTML/JSON) ────  │         │
└─────────┘                               └─────────┘
           🔒 Connexion fermée après chaque échange

WEBSOCKET (comme un téléphone) :
┌─────────┐                               ┌─────────┐
│ Client  │═══════════════════════════════│ Serveur │
│         │  Connexion OUVERTE en continu │         │
│         │←─────── Messages ─────────────│         │
│         │──────── Messages ─────────→   │         │
└─────────┘                               └─────────┘
           🔓 Connexion reste ouverte
```

### 💻 Code JavaScript (côté client)

```javascript
// Établir une connexion WebSocket
const socket = new WebSocket("ws://localhost:8000/ws/chat/room1/");

// Quand la connexion est ouverte
socket.onopen = function(e) {
    console.log("Connexion établie !");
};

// Quand on reçoit un message
socket.onmessage = function(event) {
    const data = JSON.parse(event.data);
    console.log("Message reçu:", data.message);
};

// Envoyer un message
socket.send(JSON.stringify({
    'message': 'Hello!'
}));

// Quand la connexion se ferme
socket.onclose = function(e) {
    console.log("Connexion fermée");
};
```

### 🎯 Avantages

- ✅ Communication en temps réel
- ✅ Bidirectionnel (client ↔ serveur)
- ✅ Faible latence
- ✅ Économie de bande passante

---

## 2. Django Channels

### 🔍 C'est quoi ?

**Django Channels** étend Django pour gérer les connexions asynchrones et les WebSockets.

### 📁 Architecture de Channels

```
DJANGO CLASSIQUE (WSGI) :
Request → View → Response
          ↓
       (Base de données)

DJANGO CHANNELS (ASGI) :
WebSocket → Consumer → WebSocket
             ↓
          (Channel Layer)
             ↓
       (Base de données)
```

### 🔧 Composants principaux

#### A. Consumer (consumers.py)

Un **Consumer** est comme une **View**, mais pour les WebSockets.

```python
# consumers.py
from channels.generic.websocket import AsyncWebsocketConsumer
import json

class ChatConsumer(AsyncWebsocketConsumer):
    
    # 1️⃣ Quand quelqu'un se connecte
    async def connect(self):
        self.room_name = self.scope['url_route']['kwargs']['room_name']
        self.room_group_name = f'chat_{self.room_name}'
        
        # Rejoindre le "groupe" de la room
        await self.channel_layer.group_add(
            self.room_group_name,  # Nom du groupe
            self.channel_name       # Mon canal unique
        )
        
        # Accepter la connexion
        await self.accept()
    
    # 2️⃣ Quand quelqu'un envoie un message
    async def receive(self, text_data):
        data = json.loads(text_data)
        message = data['message']
        
        # Envoyer le message à TOUT LE GROUPE
        await self.channel_layer.group_send(
            self.room_group_name,
            {
                'type': 'chat_message',  # Appelle la méthode ci-dessous
                'message': message,
                'username': self.scope['user'].username
            }
        )
    
    # 3️⃣ Quand on reçoit un message du groupe
    async def chat_message(self, event):
        message = event['message']
        username = event['username']
        
        # Envoyer au client WebSocket
        await self.send(text_data=json.dumps({
            'message': message,
            'username': username
        }))
    
    # 4️⃣ Quand quelqu'un se déconnecte
    async def disconnect(self, close_code):
        await self.channel_layer.group_discard(
            self.room_group_name,
            self.channel_name
        )
```

#### B. Routing (routing.py)

Le **routing** est comme `urls.py`, mais pour les WebSockets.

```python
# routing.py
from django.urls import path
from . import consumers

websocket_urlpatterns = [
    path('ws/chat/<str:room_name>/', consumers.ChatConsumer.as_asgi()),
]
```

#### C. ASGI Configuration (asgi.py)

```python
# asgi.py
import os
from django.core.asgi import get_asgi_application
from channels.routing import ProtocolTypeRouter, URLRouter
from channels.auth import AuthMiddlewareStack
from chat import routing

os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'myproject.settings')

application = ProtocolTypeRouter({
    "http": get_asgi_application(),  # HTTP normal
    "websocket": AuthMiddlewareStack(  # WebSocket
        URLRouter(
            routing.websocket_urlpatterns
        )
    ),
})
```

---

## 3. Channel Layers

### 🔍 C'est quoi ?

Un **Channel Layer** est un système de messagerie qui permet aux différents Consumers de communiquer entre eux.

### 🤔 Pourquoi on en a besoin ?

**Problème** : Vous avez 3 utilisateurs connectés au même chat. Chacun a sa propre instance de `ChatConsumer`.

```
User A → Consumer Instance A  }
User B → Consumer Instance B  } Comment communiquent-ils ?
User C → Consumer Instance C  }
```

**Solution** : Le Channel Layer !

### 📊 Comment ça marche ?

```
┌─────────────────────────────────────────────────────────┐
│                    CHANNEL LAYER                         │
│                   (Redis en mémoire)                     │
│                                                          │
│   ┌──────────────────────────────────────────┐         │
│   │  Groupe: "chat_room1"                    │         │
│   │  - channel_abc123 (User A)               │         │
│   │  - channel_def456 (User B)               │         │
│   │  - channel_ghi789 (User C)               │         │
│   └──────────────────────────────────────────┘         │
│                                                          │
│   ┌──────────────────────────────────────────┐         │
│   │  Groupe: "chat_room2"                    │         │
│   │  - channel_jkl012 (User D)               │         │
│   │  - channel_mno345 (User E)               │         │
│   └──────────────────────────────────────────┘         │
└─────────────────────────────────────────────────────────┘
```

### 🔧 Opérations principales

#### 1. group_add : Rejoindre un groupe

```python
await self.channel_layer.group_add(
    "chat_room1",      # Nom du groupe
    self.channel_name  # Mon identifiant unique
)
```

#### 2. group_send : Envoyer à tout le groupe

```python
await self.channel_layer.group_send(
    "chat_room1",  # Groupe cible
    {
        'type': 'chat_message',  # Méthode à appeler
        'message': 'Hello!'
    }
)
# → Tous les membres du groupe reçoivent ce message
```

#### 3. group_discard : Quitter un groupe

```python
await self.channel_layer.group_discard(
    "chat_room1",
    self.channel_name
)
```

---

## 4. Redis

### 🔍 C'est quoi ?

**Redis** est une base de données **en mémoire** ultra-rapide qui sert de backend pour le Channel Layer.

### 🎯 Pourquoi Redis ?

Django Channels a besoin de stocker :
- Les groupes (chat_room1, chat_room2, etc.)
- Les membres de chaque groupe
- Les messages en transit

Redis est parfait car :
- ✅ **Ultra-rapide** (en RAM)
- ✅ Supporte les **pub/sub** (publication/souscription)
- ✅ Gère les **expirations** automatiques
- ✅ Très populaire et stable

### 📊 Ce que Redis stocke

```
Redis (en mémoire) :
┌─────────────────────────────────────┐
│ Key: "asgi:group:chat_room1"        │
│ Value: [                            │
│   "channel_abc123",                 │
│   "channel_def456",                 │
│   "channel_ghi789"                  │
│ ]                                   │
├─────────────────────────────────────┤
│ Key: "asgi:group:chat_room2"        │
│ Value: [                            │
│   "channel_jkl012",                 │
│   "channel_mno345"                  │
│ ]                                   │
└─────────────────────────────────────┘
```

### ⚙️ Configuration dans Django

```python
# settings.py
CHANNEL_LAYERS = {
    'default': {
        'BACKEND': 'channels_redis.core.RedisChannelLayer',
        'CONFIG': {
            "hosts": [('127.0.0.1', 6379)],  # Adresse Redis
        },
    },
}
```

### 🔄 Alternative : InMemoryChannelLayer

Pour le **développement** uniquement (pas pour la production) :

```python
CHANNEL_LAYERS = {
    'default': {
        'BACKEND': 'channels.layers.InMemoryChannelLayer'
    }
}
```

⚠️ **Problème** : Ne fonctionne que si vous avez un seul processus serveur (pas de scalabilité).

---

## 5. Daphne

### 🔍 C'est quoi ?

**Daphne** est un serveur ASGI qui peut gérer :
- Les requêtes HTTP classiques
- Les connexions WebSocket
- Le protocole HTTP/2

### 📊 Architecture

```
┌──────────────────────────────────────────┐
│           Port 8000                      │
│              ↓                           │
│    ┌──────────────────┐                 │
│    │     DAPHNE       │                 │
│    │  (Serveur ASGI)  │                 │
│    └──────────────────┘                 │
│            ↓                             │
│    ┌──────────────────┐                 │
│    │   ASGI App       │                 │
│    │  (Django+Channels)│                │
│    └──────────────────┘                 │
│        ↙        ↘                       │
│   HTTP          WebSocket               │
│    ↓               ↓                    │
│  Views         Consumers                │
└──────────────────────────────────────────┘
```

### 🚀 Démarrage

```bash
# Lancer Daphne
daphne -p 8000 myproject.asgi:application

# Options utiles
daphne -p 8000 -b 0.0.0.0 myproject.asgi:application  # Écouter sur toutes les interfaces
daphne -p 8000 --verbosity 2 myproject.asgi:application  # Mode debug
```

### 🔧 Ce que fait Daphne

1. **Écoute** sur le port 8000
2. **Reçoit** les connexions (HTTP ou WebSocket)
3. **Route** vers l'application ASGI appropriée
4. **Maintient** les connexions WebSocket ouvertes
5. **Gère** les protocoles asynchrones

---

## 6. Architecture Complète

### 📊 Flux complet d'un message de chat

```
┌─────────────────────────────────────────────────────────────────┐
│                   ÉTAPE PAR ÉTAPE                               │
└─────────────────────────────────────────────────────────────────┘

1️⃣ USER A envoie "Hello!" dans le chat

   [Browser User A]
        ↓
   socket.send(JSON.stringify({message: "Hello!"}))
        ↓
   ws://localhost:8000/ws/chat/room1/


2️⃣ Daphne reçoit le message WebSocket

   [Daphne Server]
        ↓
   Connexion WebSocket active pour User A
        ↓
   Route vers ChatConsumer


3️⃣ ChatConsumer.receive() est appelé

   [ChatConsumer - Instance de User A]
        ↓
   async def receive(self, text_data):
       data = json.loads(text_data)  # {"message": "Hello!"}
       
       # Envoyer au Channel Layer
       await self.channel_layer.group_send(
           "chat_room1",
           {
               'type': 'chat_message',
               'message': data['message'],
               'username': 'User A'
           }
       )


4️⃣ Channel Layer (Redis) diffuse le message

   [Redis]
        ↓
   Récupère tous les channels du groupe "chat_room1":
   - channel_abc123 (User A)
   - channel_def456 (User B)
   - channel_ghi789 (User C)
        ↓
   Envoie le message à TOUS ces channels


5️⃣ Chaque Consumer reçoit le message

   [ChatConsumer - User A]  [ChatConsumer - User B]  [ChatConsumer - User C]
           ↓                        ↓                         ↓
   async def chat_message(event):
       await self.send(text_data=json.dumps({
           'message': event['message'],
           'username': event['username']
       }))


6️⃣ Chaque navigateur reçoit le message

   [Browser A]              [Browser B]              [Browser C]
        ↓                        ↓                         ↓
   socket.onmessage = function(e) {
       const data = JSON.parse(e.data);
       // Afficher "User A: Hello!"
   }
```

### 🎨 Diagramme visuel complet

```
┌─────────────────────────────────────────────────────────────────────┐
│                           NAVIGATEURS                               │
│  ┌──────────┐        ┌──────────┐        ┌──────────┐             │
│  │ User A   │        │ User B   │        │ User C   │             │
│  │ (Chrome) │        │ (Firefox)│        │ (Safari) │             │
│  └────┬─────┘        └────┬─────┘        └────┬─────┘             │
└───────┼───────────────────┼───────────────────┼────────────────────┘
        │ WebSocket         │ WebSocket         │ WebSocket
        │                   │                   │
┌───────▼───────────────────▼───────────────────▼────────────────────┐
│                        DAPHNE (Port 8000)                           │
│                       Serveur ASGI                                  │
└───────┬───────────────────┬───────────────────┬────────────────────┘
        │                   │                   │
┌───────▼───────────────────▼───────────────────▼────────────────────┐
│                    DJANGO CHANNELS                                  │
│                                                                     │
│  ┌──────────────┐   ┌──────────────┐   ┌──────────────┐          │
│  │ Consumer A   │   │ Consumer B   │   │ Consumer C   │          │
│  │ channel_abc  │   │ channel_def  │   │ channel_ghi  │          │
│  └──────┬───────┘   └──────┬───────┘   └──────┬───────┘          │
│         │                   │                   │                  │
│         └───────────────────┼───────────────────┘                  │
│                             │                                      │
└─────────────────────────────┼──────────────────────────────────────┘
                              │
                              ↓
┌─────────────────────────────────────────────────────────────────────┐
│                      CHANNEL LAYER (Redis)                          │
│                                                                     │
│   ┌───────────────────────────────────────────────┐               │
│   │ Groupe: "chat_room1"                          │               │
│   │ Members:                                      │               │
│   │   • channel_abc123 (User A)                   │               │
│   │   • channel_def456 (User B)                   │               │
│   │   • channel_ghi789 (User C)                   │               │
│   │                                               │               │
│   │ Messages en transit: [...]                    │               │
│   └───────────────────────────────────────────────┘               │
│                                                                     │
└─────────────────────────────────────────────────────────────────────┘
                              │
                              ↓
┌─────────────────────────────────────────────────────────────────────┐
│                       BASE DE DONNÉES                               │
│                     (PostgreSQL/SQLite)                             │
│                                                                     │
│   Tables: User, ChatRoom, Message (optionnel)                      │
└─────────────────────────────────────────────────────────────────────┘
```

---

## 7. Exemple Pratique : Votre Chat

### 📁 Structure de fichiers

```
d08/
├── manage.py
├── d08/
│   ├── __init__.py
│   ├── settings.py
│   ├── urls.py
│   ├── asgi.py  ← Configuration ASGI
│   └── wsgi.py
└── chat/
    ├── __init__.py
    ├── models.py       ← Model ChatRoom
    ├── views.py        ← Views HTTP classiques
    ├── urls.py         ← URLs HTTP
    ├── consumers.py    ← WebSocket Consumers ⭐
    ├── routing.py      ← WebSocket Routing ⭐
    └── templates/
        └── chat/
            ├── lobby.html
            └── room.html
```

### 🔧 Configuration complète

#### 1. settings.py

```python
INSTALLED_APPS = [
    'django.contrib.admin',
    'django.contrib.auth',
    'django.contrib.contenttypes',
    'django.contrib.sessions',
    'django.contrib.messages',
    'django.contrib.staticfiles',
    'channels',  # ← Ajouter
    'chat',
]

# Configuration ASGI
ASGI_APPLICATION = 'd08.asgi.application'

# Configuration du Channel Layer avec Redis
CHANNEL_LAYERS = {
    'default': {
        'BACKEND': 'channels_redis.core.RedisChannelLayer',
        'CONFIG': {
            "hosts": [('127.0.0.1', 6379)],
        },
    },
}
```

#### 2. asgi.py

```python
import os
from django.core.asgi import get_asgi_application
from channels.routing import ProtocolTypeRouter, URLRouter
from channels.auth import AuthMiddlewareStack
from chat import routing

os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'd08.settings')

application = ProtocolTypeRouter({
    "http": get_asgi_application(),
    "websocket": AuthMiddlewareStack(
        URLRouter(
            routing.websocket_urlpatterns
        )
    ),
})
```

#### 3. chat/routing.py

```python
from django.urls import path
from . import consumers

websocket_urlpatterns = [
    path('ws/chat/<str:room_name>/', consumers.ChatConsumer.as_asgi()),
]
```

#### 4. chat/consumers.py

```python
from channels.generic.websocket import AsyncWebsocketConsumer
import json

class ChatConsumer(AsyncWebsocketConsumer):
    async def connect(self):
        self.room_name = self.scope['url_route']['kwargs']['room_name']
        self.room_group_name = f'chat_{self.room_name}'
        self.user = self.scope['user']

        # Rejoindre le groupe
        await self.channel_layer.group_add(
            self.room_group_name,
            self.channel_name
        )
        
        await self.accept()

        # Notifier l'arrivée
        await self.channel_layer.group_send(
            self.room_group_name,
            {
                'type': 'chat_message',
                'message': f"{self.user.username} has joined the chat",
                'username': 'System'
            }
        )

    async def disconnect(self, close_code):
        # Notifier le départ
        await self.channel_layer.group_send(
            self.room_group_name,
            {
                'type': 'chat_message',
                'message': f"{self.user.username} has left the chat",
                'username': 'System'
            }
        )
        
        # Quitter le groupe
        await self.channel_layer.group_discard(
            self.room_group_name,
            self.channel_name
        )

    async def receive(self, text_data):
        data = json.loads(text_data)
        message = data['message']

        # Diffuser à tout le groupe
        await self.channel_layer.group_send(
            self.room_group_name,
            {
                'type': 'chat_message',
                'message': message,
                'username': self.user.username,
            }
        )

    async def chat_message(self, event):
        # Envoyer au WebSocket client
        await self.send(text_data=json.dumps({
            'message': event['message'],
            'username': event['username']
        }))
```

#### 5. chat/templates/chat/room.html

```html
<script>
    const roomName = "{{ room_name }}";
    const chatSocket = new WebSocket(
        'ws://' + window.location.host + '/ws/chat/' + roomName + '/'
    );

    // Réception de messages
    chatSocket.onmessage = function(e) {
        const data = JSON.parse(e.data);
        const messageElement = document.createElement('div');
        messageElement.innerHTML = '<strong>' + data.username + ':</strong> ' + data.message;
        document.querySelector('#chat-messages').appendChild(messageElement);
    };

    // Envoi de messages
    document.querySelector('#chat-form').onsubmit = function(e) {
        e.preventDefault();
        const messageInput = document.querySelector('#message-input');
        const message = messageInput.value;
        
        chatSocket.send(JSON.stringify({
            'message': message
        }));
        
        messageInput.value = '';
    };
</script>
```

### 🚀 Démarrer l'application

```bash
# Terminal 1 : Démarrer Redis
redis-server
# ou
brew services start redis

# Terminal 2 : Démarrer Django avec Daphne
daphne -p 8000 d08.asgi:application
```

---

## 📊 Résumé en une image

```
┌────────────────────────────────────────────────────────────────┐
│                        VOTRE CHAT                              │
└────────────────────────────────────────────────────────────────┘

1. 🌐 WEBSOCKET
   - Protocole de communication bidirectionnel
   - Connexion persistante entre navigateur et serveur

2. 📡 DJANGO CHANNELS
   - Extension de Django pour gérer les WebSockets
   - Consumers = Views pour WebSockets
   - Routing = URLs pour WebSockets

3. 📬 CHANNEL LAYER
   - Système de messagerie entre Consumers
   - Permet les groupes (chatrooms)
   - group_add, group_send, group_discard

4. 💾 REDIS
   - Base de données en mémoire ultra-rapide
   - Backend du Channel Layer
   - Stocke les groupes et leurs membres

5. 🚀 DAPHNE
   - Serveur ASGI
   - Gère HTTP + WebSockets
   - Maintient les connexions ouvertes

┌────────────────────────────────────────────────────────────────┐
│                    FLUX D'UN MESSAGE                           │
└────────────────────────────────────────────────────────────────┘

User A (Browser)
    ↓ WebSocket
Daphne (Serveur ASGI)
    ↓
Consumer A (receive)
    ↓
Channel Layer (Redis) → group_send("chat_room1", message)
    ↓
[Consumer A, Consumer B, Consumer C] → chat_message(event)
    ↓
[Browser A, Browser B, Browser C] → Affichage du message
```

---

## 🎯 Points clés à retenir

1. **WebSocket** = téléphone (connexion ouverte)
2. **HTTP** = lettre postale (connexion fermée après chaque échange)
3. **Consumer** = View pour WebSockets
4. **Channel Layer** = Système de messagerie
5. **Redis** = Boîte aux lettres ultra-rapide
6. **Daphne** = Serveur capable de gérer les WebSockets
7. **group_send** = Diffusion à tous les membres d'un groupe

---

## 🧪 Pour tester votre compréhension

Essayez de répondre à ces questions :

1. Pourquoi `python manage.py runserver` ne fonctionne pas pour les WebSockets ?
   → Car c'est un serveur WSGI (synchrone), pas ASGI

2. Que se passe-t-il quand User A envoie un message ?
   → Consumer A → Redis → [Consumer A, B, C] → [Browser A, B, C]

3. À quoi sert `self.channel_name` ?
   → Identifiant unique de la connexion WebSocket d'un utilisateur

4. Pourquoi Redis et pas SQLite pour le Channel Layer ?
   → Redis est en RAM (ultra-rapide) et supporte pub/sub

5. Que fait `group_send` ?
   → Envoie un message à tous les membres d'un groupe

---

**Félicitations ! Vous comprenez maintenant toute l'architecture ! 🎉**