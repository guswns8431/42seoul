FROM debian:buster

ENV AUTOINDEX 1

RUN apt-get update && apt-get install -y \
		nginx \
		openssl \
		vim \
		php-fpm \
		mariadb-server \
		php-mysql \
		wget 

COPY ./srcs/run.sh ./tmp
COPY ./srcs/default ./tmp
COPY ./srcs/config.inc.php ./tmp
COPY ./srcs/query.sql ./tmp
COPY ./srcs/wp-config.php ./tmp

EXPOSE 80 443

CMD bash ./tmp/run.sh
