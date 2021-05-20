FROM debian:buster

ENV AUTOINDEX 1

RUN apt-get update
RUN apt-get upgrade
RUN apt-get install -y nginx
RUN apt-get install -y openssl
RUN apt-get install -y vim
RUN apt-get install -y php-fpm
RUN apt-get install -y mariadb-server php-mysql
RUN apt-get install -y wget

COPY ./srcs/run.sh ./tmp
COPY ./srcs/default ./tmp
COPY ./srcs/config.inc.php ./tmp
COPY ./srcs/query.sql ./tmp
COPY ./srcs/wp-config.php ./tmp

EXPOSE 80 443

CMD bash ./tmp/run.sh
