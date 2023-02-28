/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibernot <tibernot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:03:09 by lbourniq          #+#    #+#             */
/*   Updated: 2023/02/27 17:35:42 by tibernot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

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
				player->x = (double)(x + 0.5);
				player->y = (double)(y + 0.5);
			}
			x++;
		}
		y++;
	}
}

static void	set_player_angle(t_data *data, t_player *player)
{
	if (data->spawn == 'N')
		player->angle = PI3;
	else if (data->spawn == 'E')
		player->angle = 0;
	else if (data->spawn == 'W')
		player->angle = PI;
	else if (data->spawn == 'S')
		player->angle = PI2;
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
