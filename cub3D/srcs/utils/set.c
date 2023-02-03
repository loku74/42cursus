/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:09:52 by lbourniq          #+#    #+#             */
/*   Updated: 2023/02/03 19:09:54 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_exit	set_mlx(t_data *data, t_mlx *mlx)
{
	mlx->img_width = get_map_width(data);
	mlx->img_height = get_map_height(data);
	mlx->win = mlx_new_window(mlx->mlx, mlx->img_width * SCALE, \
	mlx->img_height * SCALE, WINDOW_NAME);
	if (mlx->win == NULL)
		return (r_error(MLX_WIN_FAIL));
	mlx->img = mlx_new_image(mlx->mlx, mlx->img_width * SCALE, \
	mlx->img_height * SCALE);
	if (mlx->img == NULL)
		return (r_error(MLX_IMG_FAIL));
	mlx->img_addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, \
	&mlx->line_length, &mlx->endian);
	if (mlx->img_addr == NULL)
		return (r_error(MLX_GETAD_FAIL));
	return (SUCCESS);
}

static void	set_player_coord(t_data *data, t_player *player)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (is_in(data->map[y][x], PLAYER_SPAWN))
			{
				data->spawn = data->map[y][x];
				player->x = (double)(x * SCALE + PLAYER_SCALE);
				player->y = (double)(y * SCALE + PLAYER_SCALE);
			}
			x++;
		}
		y++;
	}
}

static void	set_player_angle(t_data *data, t_player *player)
{
	if (data->spawn == 'N')
		player->angle = 3 * PI / 2;
	else if (data->spawn == 'E')
		player->angle = (double)(2 * PI);
	else if (data->spawn == 'W')
		player->angle = PI;
	else if (data->spawn == 'S')
		player->angle = PI / 2;
	player->dx = cos(player->angle);
	player->dy = sin(player->angle);
}

void	set_player(t_data *data, t_player *player)
{
	player->right = FALSE;
	player->left = FALSE;
	player->forward = FALSE;
	player->back = FALSE;
	player->move_fov_left = FALSE;
	player->move_fov_right = FALSE;
	set_player_coord(data, player);
	set_player_angle(data, player);
}
