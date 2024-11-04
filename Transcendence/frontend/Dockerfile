# Étape 1 : Construction des fichiers frontend
FROM node:18 AS build

# Définir le répertoire de travail
WORKDIR /app

# Copier package.json et package-lock.json
COPY ../package*.json ./

# Nettoyer le cache npm pour éviter les conflits
RUN npm cache clean --force

# Installer les dépendances
RUN npm install

# Copier tout le code source
COPY . .

# Construire le projet
RUN npm run build

# Étape 2 : Servir avec NGINX
FROM nginx:alpine

# Copier les fichiers construits du frontend
COPY --from=build /app/dist /usr/share/nginx/html

# Configurer NGINX
COPY nginx/nginx.conf /etc/nginx/nginx.conf

# Exposer le port 80
EXPOSE 80

# Lancer NGINX
CMD ["nginx", "-g", "daemon off;"]
