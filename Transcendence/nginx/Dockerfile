# Étape 1 : Construire le frontend
FROM node:18 AS build

# Définir le répertoire de travail
WORKDIR /app

# Copier les fichiers de package et installer les dépendances
COPY ./frontend/package*.json ./
RUN npm install

# Copier le reste du code source du frontend
COPY ./frontend/ ./

# Construire le frontend
RUN npm run build

# Étape 2 : Préparer l'image Nginx
FROM nginx:alpine

# Copier les fichiers construits du frontend vers le répertoire servi par Nginx
COPY --from=build /app/dist /usr/share/nginx/html

# Copier la configuration Nginx personnalisée
COPY ./nginx/nginx.conf /etc/nginx/nginx.conf

# Générer les certificats SSL auto-signés (optionnel)
RUN apk add --no-cache openssl && \
    mkdir -p /etc/ssl/private && \
    openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
      -keyout /etc/ssl/private/transcendence.key \
      -out /etc/ssl/certs/transcendence.crt \
      -subj "/C=FR/ST=Paris/L=Paris/O=YourCompany/OU=IT/CN=localhost"

# Exposer les ports 80 et 443
EXPOSE 80 443

# Démarrer Nginx
CMD ["nginx", "-g", "daemon off;"]
