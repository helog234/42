# backend/Dockerfile

FROM python:3.9-slim

# Définir le répertoire de travail
WORKDIR /app

# Installer les dépendances système
RUN apt-get update && apt-get install -y \
    build-essential \
    libpq-dev \
    netcat-openbsd \
    procps \ 
    curl \ 
    && rm -rf /var/lib/apt/lists/*

# Copier les fichiers de dépendances
COPY requirements.txt /app/

# Installer les dépendances Python
RUN pip install --no-cache-dir -r requirements.txt

# Copier le reste de l'application
COPY . /app/

# Copier le script d'attente
COPY wait-for-it.sh /wait-for-it.sh
RUN chmod +x /wait-for-it.sh

# Exposer le port sur lequel l'application va écouter
EXPOSE 8000

# Commande pour démarrer l'application avec le script d'attente
CMD ["/wait-for-it.sh", "db:5432", "--", "gunicorn", "backend.wsgi:application", "--bind", "0.0.0.0:8000", "--log-level=debug"]

