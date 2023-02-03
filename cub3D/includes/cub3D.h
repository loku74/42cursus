/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:54:05 by lbourniq          #+#    #+#             */
/*   Updated: 2023/01/24 09:54:06 by lbourniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"
# include "../mlx_linux/mlx.h"
# include "keycodes.h"
# include "ft_macros.h"
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <math.h>

# define WINDOW_NAME    "cub3D"
# define PI				3.14159265359
# define SCALE			50
# define PLAYER_SCALE	15
# define PLAYER_SPEED	1
# define ANGLE_SPEED	0.0174533
# define WINDOW_X       1920
# define WINDOW_Y       1080
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
# define MLX_GETAD_FAIL	"MLX couldn't get an image address"
# define VALID_CHARS	"01 NSEW"
# define PLAYER_SPAWN	"NSEW"
# define FREE_SPACES	"NSEW0"
# define MALLOC_ERROR	"Malloc Error"
# define RGB_ERROR		"Invalid RGB input"
# define IMG_ERROR		"Path to texture not valid or has the wrong extension"
# define MISSING_IDS	"Some map identifiers are missing"
# define MAP_MISSING	"Map not found"
# define INVALID_MAP	"Map content cannot contain empty lines"
# define INVALID_CHARS	"Map content contains invalid characters"
# define SPAWN_COUNT_ER	"Map content has to contain (only) 1 player spawn"
# define MAP_SURR_ER	"The map has to be surrounded by walls (1)"

typedef struct s_data	t_data;
typedef struct s_dict	t_dict;
typedef struct s_player	t_player;
typedef struct s_mlx	t_mlx;
typedef struct s_ray	t_ray;

struct s_ray
{
	double	x;
	double	y;
	double 	angle;
	double	xo;
	double	yo;
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
	double 	y;
	double	dx;
	double	dy;
	double 	angle;
};

struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
};

struct s_dict
{
	char			*key;
	char			*value;
	struct s_dict	*next;
};

struct s_data
{
	t_dict		*head;
	t_player	player;
	t_mlx		*mlx;
	char 		spawn;
	void		**textures;
	int			**colors;
	char		**map;
	int			map_fd;
};

// --- PARSING ---
t_exit	parsing(t_data *data, char **argv, int argc);
t_exit	get_identifiers(t_data *data);
t_exit	check_identifiers(t_data *data);
t_exit	get_map(t_data *data);
t_exit	check_map(t_data *data);

// --- UTILS ---

// [dict.c]
t_dict	*create_new_dict(void);
t_exit	add_dict(t_dict *head, char *key_in, char *value_in);
char	*get_value(t_dict *head, char *key);
void	clear_dict(t_dict *head);

// [error.c]
void	print_error_message(void);
void	print_file_error_message(char *file);
void	print_args_error_message(int argc);
void	print_file_format_error(void);
t_exit	r_error(char *str);

// [get.c]
int		get_map_width(t_data *data);
int		get_map_height(t_data *data);
double	get_y_nearest(t_player *player);

// [check.c]
t_exit	check_num(char *num);
t_exit	check_rgb(char *rgb);

// [len.c]
int		len_split(char **split);
int		len_dict(t_dict *dict);

// [set.c]
t_exit	set_mlx(t_data *data, t_mlx *mlx);
void	set_player(t_data *data, t_player *player);

// [*.c]
void	ft_putstr_color_fd(char *str, char *color, int fd, int newline);
t_bool	ft_strrcmp(char *s1, char *s2, int n);
char	*strdup_no_nl(const char *str);
t_bool	is_in(char c, char const *charset);

// --- FREE ---
void	free_textures(t_data *data, int k, t_bool destroy_img);
void	free_colors(t_data *data);
void	free_split(char **str_split);

// --- RAYCASTING ---
void	my_pixel_put(t_mlx *mlx, int x, int y, int color);
void	draw_2d(t_data *data, t_mlx *mlx);
void	update_player(t_player *player);

// [set_ray.c]
t_bool	set_horizontal_ray(t_ray *ray, t_player *player);

#endif
