FROM nginx:alpine

RUN apk update && apk add --no-cache nginx openssl

RUN mkdir -p /etc/nginx/ssl

# Copier les certificats SSL (si vous les générez)
# COPY certs/transcendence.crt /etc/ssl/certs/transcendence.crt
# COPY certs/transcendence.key /etc/ssl/private/transcendence.key

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
  -keyout /etc/ssl/private/transcendence.key \
  -out /etc/ssl/certs/transcendence.crt \
  -subj "/C=$COUNTRY/ST=$STATE/L=$CITY/O=$ORGANIZATION/OU=$ORGANIZATIONAL_UNIT/CN=$COMMON_NAME"

COPY nginx.conf /etc/nginx/nginx.conf

EXPOSE 80 443

CMD ["nginx", "-g", "daemon off;"]
