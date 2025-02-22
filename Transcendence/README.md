# ft_transcendance

## Environment Configuration

put them here files in da root

### .env.dev
```python
DEBUG=
SECRET_KEY=
DJANGO_ALLOWED_HOSTS=localhost 127.0.0.1 [::1]
SQL_ENGINE=django.db.backends.postgresql
SQL_DATABASE=hello_django_dev
SQL_USER=hello_django
SQL_PASSWORD=hello_django
SQL_HOST=db
SQL_PORT=5432
DATABASE=postgres
EMAIL_HOST_USER=
EMAIL_HOST_PASSWORD=
OAUTH2_CLIENT_ID=
OAUTH2_CLIENT_SECRET=
OAUTH2_AUTHORIZATION_URL=https://api.intra.42.fr/oauth/authorize
OAUTH2_TOKEN_URL=https://api.intra.42.fr/oauth/token
OAUTH2_USER_INFO_URL=https://api.intra.42.fr/v2/me
OAUTH2_REDIRECT_URI=https://profile.intra.42.fr/
```

### .env.prod
```python
DEBUG=False
SECRET_KEY=change_me
FINAL_HOST=10.11.6.1
# FINAL_HOST=localhost
DJANGO_ALLOWED_HOSTS=localhost 127.0.0.1 [::1] asgiserver FIXME_FINAL_HOST *.local *.lan
SQL_ENGINE=django.db.backends.postgresql
SQL_DATABASE=hello_django_prod
SQL_USER=hello_django
SQL_PASSWORD=hello_django
SQL_HOST=db
SQL_PORT=5432
DATABASE=postgres
EMAIL_HOST_USER=
EMAIL_HOST_PASSWORD=
OAUTH2_CLIENT_ID=
OAUTH2_CLIENT_SECRET=
OAUTH2_AUTHORIZATION_URL=https://api.intra.42.fr/oauth/authorize
OAUTH2_TOKEN_URL=https://api.intra.42.fr/oauth/token
OAUTH2_USER_INFO_URL=https://api.intra.42.fr/v2/me
OAUTH2_REDIRECT_URI=https://FIXME_FINAL_HOST:2000/api/oauth/callback/
OAUTH2_STATE=MF7saAjNjAxFMaco4C15tgateauSiPasDeRetry
```

### .env.prod.db
```python
POSTGRES_USER=hello_django
POSTGRES_PASSWORD=hello_django
POSTGRES_DB=hello_django_prod
SQL_HOST=localhost
SQL_PORT=5432
```

## Building and running

### Dev version
- `$ docker-compose up --build` or `$ docker-compose up -d --build` to run in detach mode
- Go to `localhost:8000`

### Prod version

- `$ docker-compose -f docker-compose.prod.yml up --build` or `$ docker-compose -f docker-compose.prod.yml up -d --build` to run in detach mode
- `$ docker-compose -f docker-compose.prod.yml exec web python manage.py makemigrations` to setup the models
- `$ docker-compose -f docker-compose.prod.yml exec web python manage.py migrate --noinput` to migrate
- `$ docker-compose -f docker-compose.prod.yml exec web python manage.py collectstatic --no-input --clear` to copy over the static files
- Go to `localhost:2000`


## Testing

#### Register user without 2FA

- localhost:8000/api/register/
- POST
```
{
    "username": "Emma",
    "email": "emma@mail.com",
    "password": "soda1234"
}
```

#### Register user with 2FA email or QR app auth

- localhost:8000/api/register/
- POST
```
{
    "username": "Emma",
    "email": "emma@mail.com",
    "password": "soda1234",
	"enable_2fa": "email" or "totp"
}
```

#### Login user with or without 2FA 

- localhost:8000/api/login/
- POST
```
{
    "username": "Emma",
    "password": "soda1234"
}
```

#### Login user who chose "totp" 2FA but want's to use email instead

- localhost:8000/api/login/
- POST
```
{
    "username": "Emma",
    "password": "soda1234",
    "2fa_method": "email"
}
```

#### Verifying OTP for 2FA

- localhost:8000/api/otp/verif/
- POST
```
{
    "username": "Emma",
    "otp": "636847"
}
```

#### Logout 

- localhost:8000/api/logout/
- POST

#### Ask for friendship (using user_id)

- localhost:8000/api/friendships/
- POST
```
{
    "to_user": "2"
}
```

#### Accept friendship

- localhost:8000/api/friendships/{friendship_id}/accept_friendship/
- PUT

#### Get list of friendship requests

- localhost:8000/api/friendships/
- GET

#### Get list of users

- localhost:8000/api/users/
- GET

#### Get user details

- localhost:8000/api/users/{user_id}/
- GET

## Useful commands
- `$ docker-compose -f docker-compose.prod.yml exec web python manage.py createsuperuser` to create an admin user
