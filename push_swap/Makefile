# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 14:48:15 by lbourniq          #+#    #+#              #
#    Updated: 2022/12/03 08:43:31 by lbourniq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# Colors
GREEN = \033[1;32m
PURPLE = \033[1;35m
NC = \033[0m

# Headers
HEADER = push_swap.h
LIBFT_INCLUDES_DIR = ./libft/includes/
LIBFT_INCLUDES_FILES = libft.h ft_printf.h get_next_line.h
LIBFT_HEADERS = $(addprefix $(LIBFT_INCLUDES_DIR), $(LIBFT_INCLUDES_FILES))

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(HEADER)
RM = rm
RM_FLAGS = -rf

# SRCS Files and objs
SRCS = push_swap.c\
		ft_llst_addback.c\
		ft_llst_addfront.c\
		ft_create_list_a.c\
		ft_swap_f2.c\
		ft_create_new_llist.c\
		ft_push_ft.c\
		ft_shiftup.c\
		ft_shiftdown.c\
		ft_free.c\
		ft_tab_sort.c\
		ft_llstsize.c\
		ft_radix_sort.c\
		ft_base2.c\
		ft_is_sorted.c\
		ft_basic_sort.c
OBJS = $(SRCS:.c=.o)

# .c.o rule
%.o: %.c Makefile $(LIBFT_HEADERS) $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

all: makelibft $(NAME)

makelibft:
	@make -C ./libft/.

$(NAME): libft/libft.a $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)
	@echo "${GREEN}-> push_swap executable compiled successfully${NC}"

clean:
	@make -C ./libft/. clean
	@$(RM) $(RM_FLAGS) $(OBJS)
	@echo "${PURPLE}-> All push_swap objs files removed successfully${NC}"

fclean :
	@make -C ./libft/. fclean
	@$(RM) $(RM_FLAGS) $(NAME) $(OBJS)
	@echo "${PURPLE}-> push_swap executable and push_swap objs files removed successfully${NC}"

re: fclean all

.PHOHNY: all re fclean clean
