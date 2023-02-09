NAME = PhoneBook

# Colors
GREEN = \033[1;32m
PURPLE = \033[1;35m
NC = \033[0m

# Headers
HEADER = .

# Compiler and flags
CC = c++
CFLAGS = -Wall -Wextra -Werror -I$(HEADER) -std=c++98
RM = rm
RM_FLAGS = -rf
MAKE_FLAGS = --no-print-directory

# SRCS Files and objs
SRCS = PhoneBook.cpp \
		Contact.cpp \
		main.cpp
OBJS = $(SRCS:.cpp=.o)

# .cpp .o rule
%.o: %.cpp Makefile
	@$(CC) $(CFLAGS) -c $< -o $@

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

.PHOHNY: all re fclean clean
