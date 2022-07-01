# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/27 20:12:23 by hyson             #+#    #+#              #
#    Updated: 2022/07/01 18:07:55 by hyson            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DOCKER_COMPOSE_FILE	= 	./srcs/docker-compose.yml
ENV_PATH		=	./srcs/.env

all: init start

init:
	mkdir -p ${HOME}/data/wordpress ${HOME}/data/mariadb
	sudo chmod 777 /etc/hosts
	sudo echo "127.0.0.1 hyson.42.fr" >> /etc/hosts
start:
	docker-compose -f ${DOCKER_COMPOSE_FILE} --env-file ${ENV_PATH} up --build -d
stop:
	docker-compose -f ${DOCKER_COMPOSE_FILE} --env-file ${ENV_PATH} down

clean:
	docker-compose -f ./srcs/docker-compose.yml down -v --rmi all --remove-orphans
	docker system prune -f

re: clean all

.PHONY : all re clean start stop init
