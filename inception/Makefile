# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/27 20:12:23 by hyson             #+#    #+#              #
#    Updated: 2022/07/02 01:15:17 by hyson            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DOCKER_COMPOSE_FILE	= 	./srcs/docker-compose.yml
MARIADB			= 	mariadb
WORDPRESS		=	wordpress
NGINX			=	nginx
MARIADB_CONTAINER	=	srcs_mariadb_1

all: init start

init:
	sudo mkdir -p ${HOME}/data/wordpress ${HOME}/data/mariadb
	sudo chmod 777 /etc/hosts
	sudo echo "127.0.0.1 hyson.42.fr" >> /etc/hosts
start:
	sudo docker-compose -f ${DOCKER_COMPOSE_FILE} up --build -d
stop:
	sudo docker-compose -f ${DOCKER_COMPOSE_FILE} down

clean:
	sudo docker-compose -f ${DOCKER_COMPOSE_FILE} down -v --rmi all --remove-orphans
	sudo rm -rf ${HOME}/data
	sudo rm -f .setup
	sudo docker system prune --volumes --all --force
	sudo docker network prune --force
	sudo docker volume prune --force

re: clean all

ps:
	sudo docker-compose -f ${DOCKER_COMPOSE_FILE} ps

access_mariadb:
	sudo docker-compose -f ${DOCKER_COMPOSE_FILE} exec ${MARIADB} /bin/bash

access_wordpress:
	sudo docker-compose -f ${DOCKER_COMPOSE_FILE} exec ${WORDPRESS} /bin/bash

access_nginx:
	sudo docker-compose -f ${DOCKER_COMPOSE_FILE} exec ${NGINX} /bin/bash

delete_mariadb:
	sudo docker rm -f ${MARIADB_CONTAINER}

delete_db:
	sudo rm -rf /home/hyson/data/mariadb/wordpress

.PHONY : all re clean start stop init ps access_mariadb access_wordpress access_nginx delete_db delete_local_data
