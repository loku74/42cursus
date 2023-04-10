PROJECT_NAME = Inception

all: up

up:
	@docker-compose -f ./srcs/docker-compose.yml --project-name ${PROJECT_NAME} up --detach 

down:
	@docker-compose -f ./srcs/docker-compose.yml --project-name ${PROJECT_NAME} down

build:
	@docker-compose -f srcs/docker-compose.yml --project-name ${PROJECT_NAME} up --detach --build 

logs:
	@docker-compose -f srcs/docker-compose.yml --project-name ${PROJECT_NAME} logs

.PHONY: all up down build logs
