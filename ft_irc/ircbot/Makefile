NAME			=	ircbot

C_COMPIL		=	gcc

CPP_COMPIL		=	c++

HEADERS			=	-I includes\

C_SRCS			=

CPP_SRCS		=	srcs/main.cpp \
					srcs/Bot.cpp \

LIB_NAMES		=

BUILD_DIR		=	.build

C_WFLAGS		=	-Wall -Werror -Wextra #-O3
C_DBGFLAGS		=	#-g -fsanitize=address

CPP_WFLAGS		=	-Wall -Werror -Wextra -std=c++98#-O3
CPP_DBGFLAGS	=	#-g -fsanitize=address

OBJS			=	$(C_SRCS:%.c=$(BUILD_DIR)/%.o) $(CPP_SRCS:%.cpp=$(BUILD_DIR)/%.o)

DEPS			=	$(C_SRCS:%.c=$(BUILD_DIR)/%.d) $(CPP_SRCS:%.cpp=$(BUILD_DIR)/%.d)

DEPS_FLAGS		=	-MMD -MP

LIBS			=	$(subst lib,-l,$(notdir $(LIB_NAMES)))
LIB_LD			=	$(foreach lib,$(LIB_NAMES),-L$(lib))
LIB_PATHS		=	$(foreach lib,$(LIB_NAMES),$(lib)/$(notdir $(lib)).a)
LIB_HEADERS		=	$(foreach lib,$(LIB_NAMES),-I$(lib)/includes/)

ADD_FLAGS		=

all: libs $(NAME)

$(NAME)	:	$(LIB_PATHS) $(OBJS)
	$(CPP_COMPIL) $(CPP_WFLAGS) $(CPP_DBGFLAGS) -o $(NAME) $(OBJS) $(LIB_LD) $(LIBS) $(ADD_FLAGS)

libs:
	$(foreach lib, $(LIB_NAMES), make -C $(lib);)

clean:
	$(foreach lib, $(LIB_NAMES), make -C $(lib) clean;)
	@rm -rf $(BUILD_DIR)

fclean:	clean
	$(foreach lib, $(LIB_NAMES), make -C $(lib) fclean;)
	@rm -rf $(NAME)

re:	fclean all

-include $(DEPS)

$(BUILD_DIR)/%.o : %.c Makefile $(LIB_PATHS)
	@mkdir -p $(@D)
	$(C_COMPIL) $(C_WFLAGS) $(C_DBGFLAGS) $(DEPS_FLAGS) $(HEADERS) $(LIB_HEADERS) -c $< -o $@

$(BUILD_DIR)/%.o : %.cpp Makefile $(LIB_PATHS)
	@mkdir -p $(@D)
	$(CPP_COMPIL) $(CPP_WFLAGS) $(CPP_DBGFLAGS) $(DEPS_FLAGS) $(HEADERS) $(LIB_HEADERS) -c $< -o $@

.PHONY: all clean fclean re libs
