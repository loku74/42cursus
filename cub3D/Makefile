# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ratinax <ratinax@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 09:49:28 by lbourniq          #+#    #+#              #
#    Updated: 2023/03/01 11:30:56 by ratinax          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

# Colors
GREEN = \033[1;32m
PURPLE = \033[1;35m
CYAN = \033[1;36m
YELLOW = \033[1;33m
NC = \033[0m

# Header(s)
HEADER_DIR = ./includes/

HEADER_NAMES = cub3D.h ft_macros.h keycodes.h

HEADERS = $(addprefix $(HEADER_DIR), $(HEADER_NAMES))

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(HEADER_DIR) #-fsanitize=address -g3#-Ofast
MAKE_FLAG = --no-print-directory

# MinilibX lib and flags
UNAME_S = $(shell uname -s)

ifeq ($(UNAME_S), Linux)
    MLX_DIR		=	./mlx_linux/
    MLX_FLAGS	=	-Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm
else
    MLX_DIR		=	./mlx_mac/
    MLX_FLAGS	=	-Lmlx_mac -framework OpenGL -framework AppKit
endif

MLX_NAME = libmlx.a
MLX_LIB = $(addprefix $(MLX_DIR), $(MLX_NAME))

# Other command(s) and flags
RM = rm
RM_FLAGS = -rf

# Libft srcs and dir
LIBFT_DIR = ./libft/
LIBFT_NAME = libft.a

LIBFT_LIB = $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))

# SRCS Directories
SRCS_DIR = ./srcs/

PARSING_DIR = $(addprefix $(SRCS_DIR), parsing/)
UTILS_DIR = $(addprefix $(SRCS_DIR), utils/)
FREE_DIR = $(addprefix $(SRCS_DIR), free/)
RAYCASTING_DIR = $(addprefix $(SRCS_DIR), raycasting/)
PUT_GAME_DIR = $(addprefix $(SRCS_DIR), put_game/)

# SRCS Files
MAIN_SRCS = cub3D.c
MAIN_FILE = $(addprefix $(SRCS_DIR), $(MAIN_SRCS))

PARSING_SRCS = parsing.c \
				get_identifiers.c \
				check_identifiers.c \
				get_map.c \
				check_map.c
PARSING_FILES = $(addprefix $(PARSING_DIR), $(PARSING_SRCS))

UTILS_SRCS = ft_putstr_color_fd.c \
				ft_strrcmp.c \
				error.c \
				len.c \
				dict.c \
				check.c \
				is_in.c \
				get.c \
				set.c
UTILS_FILES = $(addprefix $(UTILS_DIR), $(UTILS_SRCS))

FREE_SRCS = free.c \
			destroy_mlx.c \
			destroy_imgs.c
FREE_FILES = $(addprefix $(FREE_DIR), $(FREE_SRCS))

RAYCASTING_SRCS = 	2d.c \
					player.c \
					set_ray.c \
					move.c \
					raycasting.c \
					set_player.c
RAYCASTING_FILES = $(addprefix $(RAYCASTING_DIR), $(RAYCASTING_SRCS))

PUT_GAME_SRCS = my_pixel_put.c \
				init_imgs.c \
				put_walls.c \
				create_trgb.c \
				put_background.c \
				get_thing_to_put.c
PUT_GAME_FILES = $(addprefix $(PUT_GAME_DIR), $(PUT_GAME_SRCS))

ALL_SRCS = $(MAIN_FILE) $(PARSING_FILES) $(UTILS_FILES) $(FREE_FILES) $(RAYCASTING_FILES) $(PUT_GAME_FILES)
OBJS = $(ALL_SRCS:.c=.o)

# .c.o rule
%.o: %.c Makefile $(HEADERS)
	@printf "${YELLOW}-> Compiling: ${CYAN}$<${YELLOW}...${NC}"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "${GREEN} OK!${NC}\n"

all: makelibft makemlx
	@make $(NAME) $(MAKE_FLAG)

makelibft:
	@make $(LIBFT_NAME) -C $(LIBFT_DIR) $(MAKE_FLAG)

makemlx:
	@make -C $(MLX_DIR) $(MAKE_FLAG)

$(NAME): $(OBJS) $(MLX_LIB) $(LIBFT_LIB)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME)
	@printf "${GREEN}-> cub3D executable compiled successfully${NC}\n"

clean:
	@make -C $(LIBFT_DIR) clean $(MAKE_FLAG)
	@make -C $(MLX_DIR) clean $(MAKE_FLAG)
	@$(RM) $(RM_FLAGS) $(OBJS)
	@printf "${PURPLE}-> All cub3D objs files removed successfully${NC}\n"


fclean:
	@make -C $(LIBFT_DIR) fclean $(MAKE_FLAG)
	@make -C $(MLX_DIR) clean $(MAKE_FLAG)
	@$(RM) $(RM_FLAGS) $(OBJS) $(NAME)
	@printf "${PURPLE}-> All cub3D objs files and $(NAME) executable removed successfully${NC}\n"

re: fclean all

.PHONY: all re fclean clean makelibft makemlx
