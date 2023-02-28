# Colors
GREEN = \033[1;32m
PURPLE = \033[1;35m
NC = \033[0m

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11 -Wno-deprecated-declarations

.c.o:
	@cc $(CFLAGS) -c $< -o $@

.m.o:
	@cc $(CFLAGS) -c $< -o $@

all: $(NOM)

$(NOM):	$(OBJ)
	@ar -rc $(NOM) $(OBJ)
	@ranlib $(NOM)
	@printf "${GREEN}-> MinilibX library compiled successfully${NC}\n"

clean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app

re: clean all
