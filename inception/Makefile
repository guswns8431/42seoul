# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/27 20:12:23 by hyson             #+#    #+#              #
#    Updated: 2022/06/28 17:15:32 by hyson            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DOCKER_COMPOSE_FILE	= 	./srcs/docker-compose.yml

all: init start

init:
	mkdir -p ${HOME}/data/wordpress ${HOME}/data/mariadb
	sudo chmod 777 /etc/hosts
	sudo echo "127.0.0.1 hyson.42.fr" >> /etc/hosts
start:
	docker-compose -f $(DOCKER_COMPOSE_FILE) up --build -d
stop:
	docker-compose -f $(DOCKER_COMPOSE_FILE) down

clean: stop
	docker rmi -f $$(docker images -qa)
	docker system prune -f
	docker volume prune -f

re: clean all

.PHONY : all re clean
