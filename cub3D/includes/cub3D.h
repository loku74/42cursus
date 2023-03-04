/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinax <ratinax@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:54:05 by lbourniq          #+#    #+#             */
/*   Updated: 2023/03/01 12:20:56 by ratinax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include "../mlx_linux/mlx.h"
# include "keycodes.h"
# include "ft_macros.h"
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <math.h>
# include <stdint.h>

# define WINDOW_NAME    "cub3D"
# define PLAYER_SPEED   0.2
# define ANGLE_SPEED	5
# define PI				3.14159265359
# define PI2            1.57079632679
# define PI3            4.71238898038
# define PI_2			6.28318530718
# define MAX_RAY_LEN	1000000000
# define ONE_DEGREE		0.01745329251
# define WINDOW_X		1920
# define WINDOW_Y		1080
# define EXTENSION_LEN  4
# define N_IDENTIFIERS	6
# define N_TEXTURES		4
# define N_COLORS		2
# define RGB_CONSTANT	3
# define FLOOR			0
# define CEILING		1
# define NO				0
# define SO				1
# define WE				2
# define EA				3
# define R				0
# define G				1
# define B				2
# define ELEMENT_COUNT	2
# define RED			"\033[1;31m"
# define YELLOW			"\033[1;33m"
# define NC				"\033[0m"
# define MLX_INIT_FAIL	"MLX init failed"
# define MLX_WIN_FAIL	"MLX couldn't create a window"
# define MLX_IMG_FAIL	"MLX couldn't create an image"
# define VALID_CHARS	"01 NSEW"
# define PLAYER_SPAWN	"NSEW"
# define FREE_SPACES	"NSEW0"
# define MALLOC_ERROR	"Malloc Error"
# define PARSING_ERROR	"Couldn't parse map identifiers"
# define RGB_ERROR		"Invalid RGB input"
# define IMG_ERROR		"Path to texture not valid or has the wrong extension"
# define MISSING_IDS	"Some map identifiers are missing"
# define MAP_MISSING	"Map not found"
# define INVALID_MAP	"Map content cannot contain empty lines"
# define INVALID_CHARS	"Map content contains invalid characters"
# define SPAWN_COUNT_ER	"Map content has to contain (only) 1 player spawn"
# define MAP_SURR_ER	"The map has to be surrounded by walls (1)"

typedef struct s_data		t_data;
typedef struct s_dict		t_dict;
typedef struct s_player		t_player;
typedef struct s_mlx		t_mlx;
typedef struct s_ray		t_ray;
typedef struct s_wall		t_wall;
typedef struct s_img		t_img;
typedef struct s_textures	t_textures;
typedef struct s_wall_img	t_wall_img;
typedef enum e_mode			t_mode;

enum e_mode
{
	VERTICAL,
	HORIZONTAL
};

struct s_ray
{
	double	x;
	double	y;
	double	angle;
	double	xo;
	double	yo;
	t_mode	mode;
};

struct s_wall
{
	double	size;
	double	angle;
	double	x;
	double	y;
	t_mode	orientation;
};

struct s_player
{
	t_bool	forward;
	t_bool	back;
	t_bool	right;
	t_bool	left;
	t_bool	move_fov_left;
	t_bool	move_fov_right;
	double	x;
	double	y;
	double	dx;
	double	dy;
	double	angle;
};

struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

struct s_mlx
{
	void	*mlx;
	void	*win;
	int		img_width;
	int		img_height;
};

struct s_dict
{
	char			*key;
	char			*value;
	struct s_dict	*next;
};

struct	s_textures
{
	void	*img;
	int		img_width;
	int		img_height;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		max_addr;
};

struct s_data
{
	t_dict		*head;
	t_player	player;
	t_mlx		*mlx;
	t_wall		*walls;
	double		*angles;
	char		spawn;
	t_textures	**textures;
	int			**colors;
	char		**map;
	int			map_fd;
	t_img		*img_background;
	t_img		*img_walls;
	uint32_t	ceiling_color;
	uint32_t	floor_color;
};

struct s_wall_img
{
	int			line_h;
	double		y;
	double		x;
	t_textures	*img;
	double		up_of_line;
};

// --- INITIALIZE ---

// [init_imgs.c]
int			init_imgs(t_data *d);
t_img		*init_img(t_data *d, int widht, int height);

// [set.c]
t_exit		set_mlx(t_data *data, t_mlx *mlx);
t_exit		set_walls(t_data *data);
void		set_all(t_data *data, t_mlx *mlx);

// [set_ray.c]
void		set_horizontal_ray(t_ray *ray, t_player *player);
void		set_vertical_ray(t_ray *ray, t_player *player);

// --- PARSING ---
t_exit		parsing(t_data *data, char **argv, int argc);
t_exit		get_identifiers(t_data *data);
t_exit		check_identifiers(t_data *data);
t_exit		get_map(t_data *data);
t_exit		check_map(t_data *data);

// --- UTILS ---

// [dict.c]
t_dict		*create_new_dict(void);
t_exit		add_dict(t_dict *head, char *key_in, char *value_in);
char		*get_value(t_dict *head, char *key);
void		clear_dict(t_dict *head);

// [error.c]
void		print_error_message(void);
void		print_file_error_message(char *file);
void		print_args_error_message(int argc);
void		print_file_format_error(void);
t_exit		r_error(char *str);

// [get.c]
int			get_map_width(t_data *data);
int			get_map_height(t_data *data);
double		get_y_nearest(t_player *player, t_ray *ray);
double		get_x_nearest(t_player *player, t_ray *ray);

// [check.c]
t_exit		check_num(char *num);
t_exit		check_rgb(char *rgb);
t_exit		check_all(t_data *data, char **argv, int argc);

// [len.c]
int			len_split(char **split);
int			len_dict(t_dict *dict);

// [*.c]
void		ft_putstr_color_fd(char *str, char *color, int fd, int newline);
t_bool		ft_strrcmp(char *s1, char *s2, int n);
t_bool		is_in(char c, char const *charset);

// --- FREE ---
void		free_split(char **str_split);
void		free_all(t_data *data);
void		destroy_mlx(t_mlx *mlx);
void		destroy_image(void *mlx_ptr, t_img *img);
void		destroy_all_images(t_data *d);

// --- RAYCASTING ---
void		raycasting(t_data *data);
void		update_player(t_player *player, t_data *data);

// [raycasting.c]
double		get_ray_dist(t_ray *ray, t_data *data, \
			t_player *player, t_mlx *mlx);
void		set_player(t_data *data, t_player *player);

// [move.c]
void		move_forward(t_player *player, t_data *data);
void		move_back(t_player *player, t_data *data);
void		move_right(t_player *player, t_data *data);
void		move_left(t_player *player, t_data *data);

// --- PUT_GAME ---
void		put_walls(t_data *d);
void		init_background(t_data *d);

uint32_t	create_trgb(unsigned char t, unsigned char r, unsigned char g, \
			unsigned char b);

// [my_pixel_put]
void		my_pixel_put(t_img *img, int x, int y, int color);

// [put_background.c]
void		put_background(t_data *d, int lineH, int up_of_line, int x);

// [get_thing_to_put.c]
t_textures	*get_texture_to_put(t_data *d, t_wall wall, t_wall_img *wall_img);
uint32_t	pixel_to_put(t_textures *img, int pixel_addr);

// [get_put_walls_data.c]
int			get_nb_rays(int i, t_wall *walls);
#endif
