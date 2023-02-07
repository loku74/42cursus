# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 15:09:18 by lbourniq          #+#    #+#              #
#    Updated: 2022/12/26 17:04:19 by lbourniq         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = pipex

# Colors
GREEN = \033[1;32m
PURPLE = \033[1;35m
NC = \033[0m

# Header(s)
HEADER_DIR = ./includes/

HEADER_NAME = pipex.h

HEADER = $(addprefix $(HEADER_DIR), $(HEADER_NAME))

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm
RM_FLAGS = -rf

# --- SRCS files and objs ---
# Mandatory
SRCS_DIR = ./srcs/

SRCS_FILES = pipex.c\
	ft_check.c\
	ft_create.c\
	ft_exit.c\
	ft_free.c\
	ft_execute.c\
	ft_close.c\
	ft_utils.c\
	ft_utils2.c

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS = $(SRCS:.c=.o)

# .c.o rule (mandatory part)
$(SRCS_DIR)%.o: $(SRCS_DIR)%.c Makefile $(HEADER) ./libft/libft.a
	@$(CC) $(CFLAGS) -I$(HEADER_DIR) -c $< -o $@

all: makelibft $(NAME)

makelibft:
	@make -C ./libft/.

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)
	@echo "${GREEN}-> pipex executable compiled successfully${NC}"

clean:
	@make -C ./libft/. clean
	@$(RM) $(RM_FLAGS) $(OBJS)
	@echo "${PURPLE}-> All pipex objs files removed successfully${NC}"

fclean :
	@make -C ./libft/. fclean
	@$(RM) $(RM_FLAGS) $(NAME) $(OBJS)
	@echo "${PURPLE}-> pipex executable and pipex objs removed successfully${NC}"

re: fclean all

.PHONY: all re fclean clean makelibft bonus
