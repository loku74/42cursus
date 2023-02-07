# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 12:54:07 by lbourniq          #+#    #+#              #
#    Updated: 2023/02/04 16:26:35 by lbourniq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

# colors
GREEN = \033[1;32m
PURPLE = \033[1;35m
NC = \033[0m

# compiler and flags
CC = cc
CC_FLAGS = -Wall -Wextra -Werror
P_THREAD_FLAG = -pthread

# commands
RM = rm
RM_FLAGS = -rf

# header dir(s) and file(s)
HEADER_DIR = ./includes/
HEADER_FILE = philosophers.h
HEADER = $(addprefix $(HEADER_DIR), $(HEADER_FILE))

# srcs dir(s) and file(s)
SRCS_DIR = ./srcs/
SRCS_FILES = philosophers.c\
				parsing.c\
				routine.c\
				utils.c\
				init.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS = $(SRCS:.c=.o)

%.o: %.c Makefile $(HEADER)
	@$(CC) $(CC_FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CC_FLAGS) $(P_THREAD_FLAG) -I$(HEADER) $(OBJS) -o $(NAME)
	@echo "$(GREEN)philo executable compiled succesfully $(NC)"

clean:
	@$(RM) $(RM_FLAGS) $(OBJS)
	@echo "$(PURPLE) All philosophers objs files removed succesfully $(NC)"

fclean:
	@$(RM) $(RM_FLAGS) $(OBJS)
	@$(RM) $(RM_FLAGS) $(NAME)
	@echo "$(PURPLE)All philosophers objs files and philo executable removed succesfully $(NC)"

re:
	@make fclean
	@make $(NAME)

.PHONY: all re clean fclean
