# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbourniq <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 09:49:28 by lbourniq          #+#    #+#              #
#    Updated: 2023/01/24 09:49:30 by lbourniq         ###   ########lyon.fr    #
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

HEADER_NAMES = cub3D.h ft_macros.h

HEADERS = $(addprefix $(HEADER_DIR), $(HEADER_NAMES))

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(HEADER_DIR)

# MinilibX lib and flags
UNAME_S = $(shell uname -s)

ifeq ($(UNAME_S), Linux)
    MLX_DIR		=	./mlx_linux/
    MLX_FLAGS	=	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
    MLX_CCFLAGS	=	-I/usr/include -Imlx_linux -O3
else
    MLX_DIR		=	./mlx/
    MLX_FLAGS	=	-Lmlx -lmlx -framework OpenGL -framework AppKit
    MLX_CCFLAGS	=	-Imlx
endif

# Other command(s) and flags
RM = rm
RM_FLAGS = -rf

# Libft srcs and dir
LIBFT_DIR = ./libft/
LIBFT_NAME = libft.a

LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))

# SRCS Directories
SRCS_DIR = ./srcs/

PARSING_DIR = $(addprefix $(SRCS_DIR), parsing/)
UTILS_DIR = $(addprefix $(SRCS_DIR), utils/)
FREE_DIR = $(addprefix $(SRCS_DIR), free/)
RAYCASTING_DIR = $(addprefix $(SRCS_DIR), raycasting/)

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
				strdup_no_nl.c \
				check.c \
				is_in.c \
				get.c \
				set.c
UTILS_FILES = $(addprefix $(UTILS_DIR), $(UTILS_SRCS))

FREE_SRCS = free.c
FREE_FILES = $(addprefix $(FREE_DIR), $(FREE_SRCS))

RAYCASTING_SRCS = my_pixel_put.c \
					2d.c \
					player.c \
					set_ray.c
RAYCASTING_FILES = $(addprefix $(RAYCASTING_DIR), $(RAYCASTING_SRCS))

ALL_SRCS = $(MAIN_FILE) $(PARSING_FILES) $(UTILS_FILES) $(FREE_FILES) $(RAYCASTING_FILES)
OBJS = $(ALL_SRCS:.c=.o)

# .c.o rule
%.o: %.c Makefile $(HEADERS)
	@printf "${YELLOW}-> Compiling: ${CYAN}$<${YELLOW}...${NC}"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "${GREEN} OK!${NC}\n"

all: $(NAME)

makelibft:
	@make -C $(LIBFT_DIR)

makemlx:
	@make -C $(MLX_DIR)

$(NAME): makelibft makemlx $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -lm $(MLX_DIR)libmlx.a $(LIBFT) -o $(NAME)
	@printf "${GREEN}-> cub3D executable compiled successfully${NC}\n"

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@$(RM) $(RM_FLAGS) $(OBJS)
	@printf "${PURPLE}-> All cub3D objs files removed successfully${NC}\n"


fclean:
	@make -C $(LIBFT_DIR) fclean
	@make -C $(MLX_DIR) clean
	@$(RM) $(RM_FLAGS) $(OBJS) $(NAME)
	@printf "${PURPLE}-> All cub3D objs files and $(NAME) executable removed successfully${NC}\n"

re:
	@make fclean
	@make $(NAME)

.PHONY: all re fclean clean makelibft
