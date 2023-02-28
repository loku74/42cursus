# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 11:29:55 by lbourniq          #+#    #+#              #
#    Updated: 2023/01/24 17:09:30 by lbourniq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
GREEN = \033[1;32m
PURPLE = \033[1;35m
CYAN = \033[1;36m
YELLOW = \033[1;33m
NC = \033[0m

# Name of the lib
NAME = libft.a

# Headers
HEADERS_DIR = ./includes/
LIBFT_HEADER = libft.h
FT_PRINTF_HEADER = ft_printf.h
GNL_HEADER = get_next_line.h
HEADERS = $(LIBFT_HEADER) $(FT_PRINTF_HEADER) $(GNL_HEADER)
ALL_HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS))

# Compiler, ar and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(HEADERS_DIR)
AR = ar
AR_FLAGS = rcs
RM = rm
RM_FLAGS = -rf
RANLIB = ranlib

# Libft directories and files
LIBFT_DIR = ./libft/

FT_IS_FILES = ft_isalnum.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isdigit.c\
				ft_isprint.c
FT_IS_SRCS = $(addprefix ft_is/, $(FT_IS_FILES))

FT_LST_FILES = ft_lstadd_back.c\
				ft_lstadd_front.c\
				ft_lstclear.c\
				ft_lstdelone.c\
				ft_lstiter.c\
				ft_lstlast.c\
				ft_lstmap.c\
				ft_lstnew.c\
				ft_lstsize.c
FT_LST_SRCS = $(addprefix ft_lst/, $(FT_LST_FILES))

FT_MEM_FILES = ft_memchr.c\
				ft_memcmp.c\
				ft_memcpy.c\
				ft_memmove.c\
				ft_memset.c
FT_MEM_SRCS = $(addprefix ft_mem/, $(FT_MEM_FILES))

FT_PUT_FILES = ft_putchar_fd.c\
				ft_putendl_fd.c\
				ft_putnbr_fd.c\
				ft_putstr_fd.c
FT_PUT_SRCS = $(addprefix ft_put/, $(FT_PUT_FILES))

FT_STR_FILES = ft_strchr.c\
				ft_strdup.c\
				ft_striteri.c\
				ft_strjoin.c\
				ft_strlcat.c\
				ft_strlcpy.c\
				ft_strlen.c\
				ft_strmapi.c\
				ft_strncmp.c\
				ft_strnstr.c\
				ft_strrchr.c\
				ft_strtrim.c
FT_STR_SRCS = $(addprefix ft_str/, $(FT_STR_FILES))

FT_UTILS_FILES = ft_atoi.c\
					ft_bzero.c\
					ft_calloc.c\
					ft_itoa.c\
					ft_split.c\
					ft_substr.c\
					ft_tolower.c\
					ft_toupper.c\
					ft_is_in.c
FT_UTILS_SRCS = $(addprefix ft_utils/, $(FT_UTILS_FILES))

LIBFT_ALL_SRCS_FILES = $(FT_IS_SRCS) $(FT_LST_SRCS) $(FT_MEM_SRCS) $(FT_PUT_SRCS) $(FT_STR_SRCS) $(FT_UTILS_SRCS)
LIBFT_SRCS_FILES = $(addprefix $(LIBFT_DIR), $(LIBFT_ALL_SRCS_FILES))
LIBFT_OBJS_FILES = $(LIBFT_SRCS_FILES:.c=.o)

# Ft_printf directory and files
FT_PRINTF_DIR = ./ft_printf/

FT_PRINTF_FILES = ft_printf.c\
					ft_treat_char.c\
					ft_treat_hexa.c\
					ft_treat_int.c\
					ft_treat_ptr.c\
					ft_treat_str.c\
					ft_treat_uint.c
					
FT_PRINTF_SRCS_FILES = $(addprefix $(FT_PRINTF_DIR), $(FT_PRINTF_FILES)) 
FT_PRINTF_OBJS_FILES = $(FT_PRINTF_SRCS_FILES:.c=.o)

# Get_next_line directory and files
GNL_DIR = ./gnl/
GNL_FILES = get_next_line.c\
					get_next_line_utils.c
GNL_SRCS_FILES = $(addprefix $(GNL_DIR), $(GNL_FILES))
GNL_OBJS_FILES = $(GNL_SRCS_FILES:.c=.o)

# all
all: $(NAME)

$(NAME): $(LIBFT_OBJS_FILES) $(FT_PRINTF_OBJS_FILES) $(GNL_OBJS_FILES)
	@$(AR) $(AR_FLAGS) $(NAME) $(LIBFT_OBJS_FILES) \
								$(FT_PRINTF_OBJS_FILES) \
								$(GNL_OBJS_FILES)
	@$(RANLIB) $(NAME)
	@printf "${GREEN}-> $(NAME) compiled successfully${NC}\n"

%.o: %.c Makefile $(ALL_HEADERS)
	@printf "${YELLOW}-> Compiling: ${CYAN}$<${YELLOW}...${NC}"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "${GREEN} OK!${NC}\n"

clean: 
	@$(RM) $(RM_FLAGS) $(LIBFT_OBJS_FILES) \
	$(FT_PRINTF_OBJS_FILES) \
	$(GNL_OBJS_FILES)
	@printf "${PURPLE}-> All libft objs files removed successfully${NC}\n"

fclean:
	@$(RM) $(RM_FLAGS) $(NAME) $(LIBFT_OBJS_FILES) \
	$(FT_PRINTF_OBJS_FILES) \
	$(GNL_OBJS_FILES)
	@printf "${PURPLE}-> $(NAME) and objs files removed successfully${NC}\n"

re: fclean all

.PHONY: clean fclean re all
