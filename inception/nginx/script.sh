#!bin/bash

mv ./tmp/default /etc/nginx/sites-available/default
openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/server_pkey.pem -out /etc/ssl/certs/server.crt -subj "/C=KR/ST=Seoul/L=YangCheon-gu/O=42/OU=42Seoul/CN=hyson.42.fr"

nginx -g 'daemon off;'
