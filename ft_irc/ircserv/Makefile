# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tibernot <tibernot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/17 13:55:24 by tibernot          #+#    #+#              #
#    Updated: 2023/05/15 13:58:42 by tibernot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#colors

BLACK		= \033[0m\033[30m
RED			= \033[0m\033[31m
GREEN		= \033[0m\033[32m
YELLOW		= \033[0m\033[33m
BLUE		= \033[0m\033[34m
MAGENTA		= \033[0m\033[35m
CYAN		= \033[0m\033[36m
WHITE		= \033[0m\033[37m
BOLDBLACK	= \033[1m\033[30m
BOLDRED		= \033[1m\033[31m
BOLDGREEN	= \033[1m\033[32m
BOLDYELLOW	= \033[1m\033[33m
BOLDBLUE	= \033[1m\033[34m
BOLDMAGENTA	= \033[1m\033[35m
BOLDCYAN	= \033[1m\033[36m
BOLDWHITE	= \033[1m\033[37m
BOLDWHITE	= \033[1m\033[37m

NAME 			= 	ircserv
CC 				= 	c++

SRC_FOLDER		=	srcs/
INC_FOLDER		=	includes/
OBJS_FOLDER		=	.objs/

SRC_FILES		=	main.cpp \
					print_errors.cpp \
					bad_input.cpp \
					Server.cpp \
					Channel.cpp \
					User.cpp \
					quit.cpp \
					part.cpp \
					join.cpp \
					privmsg.cpp \
					notice.cpp \
					kick.cpp \
					mode.cpp \
					invite.cpp \
					topic.cpp \
					parsing.cpp \
					login.cpp \
					who.cpp \
					irc_server_commands.cpp \

INCLUDES_FILES	=	colors.hpp \
					utils.hpp \
					Server.hpp \
					Channel.hpp \
					User.hpp \
					parsing.hpp \
					replies.hpp \
					errors.hpp \

SRC 			= 	$(addprefix $(SRC_FOLDER), $(SRC_FILES))
INCLUDES 		= 	$(addprefix $(INC_FOLDER), $(INCLUDES_FILES))

OBJ 			= 	${SRC_FILES:.cpp=.o}
CFLAGS 			= -Wall -Werror -Wextra -std=c++98 -g3
OBJS			= 	$(addprefix $(OBJS_FOLDER), $(OBJ))

all : $(NAME)

$(NAME) : $(OBJS_FOLDER) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo -e "$(CYAN)$(CC) $(BOLDGREEN)$(CFLAGS) $(BLACK)-o $(MAGENTA)$(NAME) $(YELLOW)$(OBJS) $(WHITE)"

$(OBJS_FOLDER)%.o : $(SRC_FOLDER)%.cpp $(INCLUDES) Makefile
	@$(CC) $(CFLAGS) -o $@ -c $< -I $(INC_FOLDER)
	@echo -e "$(CYAN)$(CC) $(BOLDGREEN)$(CFLAGS) $(BLACK)-o $(YELLOW)$@ $(BLACK)-c $(BOLDBLUE)$< $(BLACK)-I $(RED)$(INC_FOLDER) $(WHITE)"


$(OBJS_FOLDER):
	@mkdir $(OBJS_FOLDER)
	@echo -e "$(BLUE)mkdir $(YELLOW)$(OBJS_FOLDER) $(WHITE)"

clean :
	@-rm -rf $(OBJS_FOLDER)
	@echo -e "$(BOLDRED)-rm $(RED)-rf  $(YELLOW)$(OBJS_FOLDER) $(WHITE)"
fclean : clean
	@-rm -f $(NAME)
	@echo -e "$(BOLDRED)-rm $(RED)-f  $(MAGENTA)$(NAME) $(WHITE)"

re : fclean all

.PHONY: all clean fclean re
