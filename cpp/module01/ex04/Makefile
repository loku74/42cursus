NAME = replace

# Colors
GREEN = \033[1;32m
PURPLE = \033[1;35m
CYAN = \033[1;36m
YELLOW = \033[1;33m
NC = \033[0m

# Headers
HEADER_DIR = ./
HEADER_NAMES =
HEADERS = $(addprefix $(HEADER_DIR), $(HEADER_NAMES))

# Compiler and flags
CC = c++
CFLAGS = -Wall -Wextra -Werror -I$(HEADER_DIR) -std=c++98 #-fsanitize=address
RM = rm
RM_FLAGS = -rf
MAKE_FLAGS = --no-print-directory

# SRCS Files and objs
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

# .cpp .o rule
%.o: %.cpp Makefile $(HEADERS)
	@printf "${YELLOW}-> Compiling: ${CYAN}$<${YELLOW}...${NC}"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "${GREEN} OK!${NC}\n"

all:
	@make $(NAME) $(MAKE_FLAGS)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@printf "${GREEN}-> $(NAME) executable compiled successfully${NC}\n"

clean:
	@$(RM) $(RM_FLAGS) $(OBJS)
	@printf "${PURPLE}-> All $(NAME) objs files removed successfully${NC}\n"

fclean :
	@$(RM) $(RM_FLAGS) $(NAME) $(OBJS)
	@printf "${PURPLE}-> $(NAME) executable and $(NAME) objs files removed successfully${NC}\n"

re: fclean all

.PHONY: all re fclean clean