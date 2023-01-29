# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 14:44:35 by lbourniq          #+#    #+#              #
#    Updated: 2023/01/28 15:09:15 by lbourniq         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# Colors
GREEN = \033[1;32m
PURPLE = \033[1;35m
NC = \033[0m

# Header(s)
HEADER_DIR = ./includes/

HEADER_NAME = so_long.h

HEADER = $(addprefix $(HEADER_DIR), $(HEADER_NAME))

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(HEADER) #-fsanitize=address

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

SET_DIR = $(addprefix $(SRCS_DIR), set/)
MAIN_DIR = $(addprefix $(SRCS_DIR), main/)
ANIMATIONS_DIR = $(addprefix $(SRCS_DIR), animations/)
UPDATE_DIR = $(addprefix $(SRCS_DIR), update/)
PARSING_DIR = $(addprefix $(SRCS_DIR), parsing/)
COLLISION_DIR = $(addprefix $(SRCS_DIR), collision/)

# SRCS Files
MAIN_SRCS = so_long.c
MAIN_FILES = $(addprefix $(MAIN_DIR), $(MAIN_SRCS))

SET_SRCS = set_sprite.c\
			set_window.c\
			set_running.c\
			set_idle.c\
			set_jumping.c\
			set_falling.c\
			set_assets.c\
			set_all.c\
			set_map.c\
			set_coin.c\
			set_init.c\
			set_portal.c

SET_FILES = $(addprefix $(SET_DIR), $(SET_SRCS))

ANIMATIONS_SRCS = idle.c\
					run.c\
					jump.c\
					fall.c\
					coin_animation.c\
					portal_animation.c
ANIMATIONS_FILES = $(addprefix $(ANIMATIONS_DIR), $(ANIMATIONS_SRCS))

UPDATE_SRCS = update_sprite.c\
				update_window.c\
				update_coin.c\
				update_portal.c
UPDATE_FILES = $(addprefix $(UPDATE_DIR), $(UPDATE_SRCS))

PARSING_SRCS = parsing.c\
				display_error_message.c\
				check_rectangular_form.c\
				check_input_error.c\
				check_map.c\
				check_map_format.c\
				check_map_surroundings.c\
				path_finding.c
PARSING_FILES = $(addprefix $(PARSING_DIR), $(PARSING_SRCS))

COLLISION_SRCS = check_right_collision.c\
					check_left_collision.c\
					check_falling.c\
					check_top_collision.c\
					check_coin_collision.c\
					check_portal_collision.c
COLLISION_FILES = $(addprefix $(COLLISION_DIR), $(COLLISION_SRCS))

ALL_SRCS = $(MAIN_FILES) $(SET_FILES) $(ANIMATIONS_FILES) $(UPDATE_FILES) $(PARSING_FILES) $(COLLISION_FILES)
OBJS = $(ALL_SRCS:.c=.o)

# .c.o rule
%.o: %.c Makefile $(HEADER) $(LIBFT)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(MLX_LIB)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) $(MLX_LIB) $(LIBFT) -o $(NAME)
	@echo "${GREEN}-> so_long executable compiled successfully${NC}"

clean:
	@make -C ./libft/. clean
	@make -C ./mlx/. clean
	@$(RM) $(RM_FLAGS) $(OBJS)
	@echo "${PURPLE}-> All so_long objs files and MinilibX objs files removed successfully${NC}"

fclean:
	@make -C ./libft/ fclean
	@make -C ./mlx/. clean
	@$(RM) $(RM_FLAGS) $(OBJS) $(NAME)
	@echo "${PURPLE}-> All so_long objs files, MinilibX objs files and so_long executable removed successfully${NC}"

re: 
	@make fclean
	@make $(NAME)

bonus:
	@make $(NAME)

.PHONY: all re fclean clean makelibft bonus  
