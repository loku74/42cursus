/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:08:52 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/20 09:31:36 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <errno.h>
# include <strings.h>

# define COUNTER_MAX 111111

typedef struct s_mlx {
	char	**map;
	char	**map_c;
	char	*idle_r[4];
	char	*idle_l[4];
	char	*running_r[6];
	char	*running_l[6];
	char	*jumping_r[8];
	char	*jumping_l[8];
	char	*falling_r[2];
	char	*falling_l[2];
	char	*coin[6];
	char	*portal[6];
	void	*back;
	void	*wall;
	void	*grass;
	void	*dirt;
	void	*portal_sprite;
	char	*strsteps;
	int		sprite_h;
	int		sprite_w;
	int		sprite_y;
	int		sprite_x;
	int		win_y;
	int		win_x;
	int		run_r;
	int		run_l;
	int		left;
	int		idle;
	int		pixel;
	int		steps;
	int		jumping;
	int		curr_jumping;
	int		falling;
	int		jump_frame;
	int		map_fd;
	int		map_width;
	int		map_height;
	int		finish;
	int		collectibles_found;
	int		collectibles;
	int		collectibles_collected;
	int		exit_path;
	void	*sprite;
	void	*coin_sprite;
	void	*asset;
	void	*mlx;
	void	*win;
}				t_mlx;

// set function(s)
void	set_all(t_mlx *mlx);
void	set_idle_right(t_mlx *mlx);
void	set_idle_left(t_mlx *mlx);
void	set_window(t_mlx *mlx);
void	set_sprite(t_mlx *mlx);
void	set_running_right(t_mlx *mlx);
void	set_running_left(t_mlx *mlx);
void	set_jumping_r(t_mlx *mlx);
void	set_jumping_l(t_mlx *mlx);
void	set_falling_r(t_mlx *mlx);
void	set_falling_l(t_mlx *mlx);
void	set_assets(t_mlx *mlx);
void	set_map(t_mlx *mlx);
void	set_coin(t_mlx *mlx);
void	set_init(t_mlx *mlx);
void	set_portal(t_mlx *mlx);

// update function(s)
void	update_sprite(t_mlx *mlx, char *frame);
void	update_window(t_mlx *mlx);
void	update_coin(t_mlx *mlx, char *frame);
void	update_portal(t_mlx *mlx, char *frame);

// animation function(s)
void	idle(t_mlx *mlx);
void	run(t_mlx *mlx);
void	jump(t_mlx *mlx);
void	fall(t_mlx *mlx);
void	coin_animation(t_mlx *mlx);
void	portal_animation(t_mlx *mlx);

// parsing function(s)
void	errexit(t_mlx *mlx, char *error_message);
void	parsing(t_mlx *mlx);
void	check_rectangular_form(t_mlx *mlx);
void	check_input_error(int argc, char **argv, t_mlx *mlx);
void	check_map(t_mlx *mlx);
void	check_map_format(t_mlx *mlx);
void	check_map_surroundings(t_mlx *mlx);
void	path_finding(t_mlx *mlx, int y, int x);

// collision function(s)
int		check_right_collision(t_mlx *mlx);
int		check_left_collision(t_mlx *mlx);
int		check_top_collision(t_mlx *mlx);
void	check_falling(t_mlx *mlx);
void	check_coin_collision(t_mlx *mlx);
void	check_portal_collision(t_mlx *mlx);

#endif