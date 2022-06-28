FROM debian:buster

RUN apt-get update && apt-get install -y	\
	    mariadb-server		 	\
	    vim

COPY ./config/50-server.cnf /etc/mysql/mariadb.conf.d/
COPY ./config/init_mariadb.sql ./tmp
COPY ./script.sh ./tmp

RUN chmod +x ./tmp/script.sh
CMD [ "./tmp/script.sh" ]
