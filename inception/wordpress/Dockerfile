FROM debian:buster

RUN apt-get update && apt-get install -y \
	    mariadb-client	\
	    php7.3		\
	    php-fpm		\
	    wget		\
	    php-mysql		\
	    vim

COPY ./script.sh ./tmp
COPY ./config/wp-config.php ./tmp
COPY ./config/www.conf ./tmp
RUN chmod +x ./tmp/script.sh
ENTRYPOINT [ "./tmp/script.sh" ]
