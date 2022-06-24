FROM debian:buster

RUN apt-get update && apt-get install -y \
	    mariadb-client	\
	    php7.3		\
	    php-fpm		\
	    php-cli		\
	    wget		\
	    curl		\
	    php-mysql		\
	    php-mbstring	\
	    php-xml		\
	    sendmail		\
	    vim

COPY ./script.sh ./tmp
COPY ./config/wp-config.php ./tmp
COPY ./config/www.conf ./tmp
RUN chmod +x ./tmp/script.sh
ENTRYPOINT [ "./tmp/script.sh" ]
#CMD ["/usr/sbin/php-fpm7.3", "--nodaemonize"]
