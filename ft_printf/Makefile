# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbourniq <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 15:12:28 by lbourniq          #+#    #+#              #
#    Updated: 2022/11/20 09:29:52 by lbourniq         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

#Standard

NAME = libftprintf.a
LIBFTNAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
AR_FLAGS = rcs
RM = rm
RM_FLAGS = -rf
HEADER = ft_printf.h

SRCS = ft_printf.c\
	   ft_treat_char.c\
	   ft_treat_str.c\
	   ft_treat_ptr.c\
	   ft_treat_int.c\
	   ft_treat_uint.c\
	   ft_treat_hexa.c

#Directories

SRCS_DIR = ./srcs/
INCLUDES_DIR = ./includes/
LIBFT_DIR = ./libft/
HEADER_FILES = $(addprefix $(INCLUDES_DIR), $(HEADER))
INCLUDES = -I$(HEADER_FILES)

#Files

SRCS_FILES = $(addprefix $(SRCS_DIR), $(SRCS))
OBJS_FILES = $(SRCS_FILES:.c=.o)

# Rules

%.o: %.c $(HEADER_FILES) libft/libft.h Makefile libft/Makefile
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS_FILES)
	make -C $(LIBFT_DIR)
	cp libft/libft.a .
	mv libft.a $(NAME)
	$(AR) $(AR_FLAGS) $(NAME) $(OBJS_FILES)
	ranlib $(NAME)


clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(RM_FLAGS) $(OBJS_FILES)

fclean: clean
	$(RM) $(RM_FLAGS) $(NAME)
	$(RM) $(RM_FLAGS) libft/$(LIBFTNAME)

re: fclean all

.PHONY: clean fclean re all
