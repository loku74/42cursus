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

HEADER_NAME = cub3D.h

HEADER = $(addprefix $(HEADER_DIR), $(HEADER_NAME))

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(HEADER_DIR)

# MinilibX lib and flags
MLX_DIR = ./mlx/
MLX_LIB_NAME = libmlx.a

MLX_LIB = $(addprefix $(MLX_DIR), $(MLX_LIB_NAME))

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

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

# SRCS Files
MAIN_SRCS = cub3D.c
MAIN_FILE = $(addprefix $(SRCS_DIR), $(MAIN_SRCS))

PARSING_SRCS = parsing.c\
				get_map_info.c\
				dict.c
PARSING_FILES = $(addprefix $(PARSING_DIR), $(PARSING_SRCS))

UTILS_SRCS = ft_putstr_color_fd.c \
				ft_strrcmp.c \
				error.c \
				len.c\
				strdup_no_nl.c
UTILS_FILES = $(addprefix $(UTILS_DIR), $(UTILS_SRCS))

ALL_SRCS = $(MAIN_FILE) $(PARSING_FILES) $(UTILS_FILES)
OBJS = $(ALL_SRCS:.c=.o)

# .c.o rule
%.o: %.c Makefile $(HEADER) $(LIBFT)
	@printf "${YELLOW}-> Compiling: ${CYAN}$<${YELLOW}...${NC}"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "${GREEN} OK!${NC}\n"

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(NAME): $(LIBFT) $(MLX_LIB) $(OBJS)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) $(MLX_LIB) $(LIBFT) -o $(NAME)
	@printf "${GREEN}-> cub3D executable compiled successfully${NC}\n"

clean:
	@make -C ./libft/. clean
	@make -C ./mlx/. clean
	@$(RM) $(RM_FLAGS) $(OBJS)
	@printf "${PURPLE}-> All cub3D objs files removed successfully${NC}\n"


fclean:
	@make -C ./libft/ fclean
	@make -C ./mlx/. fclean
	@$(RM) $(RM_FLAGS) $(OBJS) $(NAME)
	@printf "${PURPLE}-> All cub3D objs files and $(NAME) executable removed successfully${NC}\n"

re:
	@make fclean
	@make $(NAME)

.PHONY: all re fclean clean makelibft
