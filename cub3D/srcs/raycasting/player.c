/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibernot <tibernot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:09:06 by lbourniq          #+#    #+#             */
/*   Updated: 2023/02/13 11:36:25 by tibernot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	update_angle(t_player *player)
{
	if (player->move_fov_left == TRUE)
	{
		player->angle -= (double)(ONE_DEGREE * ANGLE_SPEED);
		if (player->angle < 0.0)
			player->angle += (double)PI_2;
	}
	if (player->move_fov_right == TRUE)
	{
		player->angle += (double)(ONE_DEGREE * ANGLE_SPEED);
		if (player->angle > (double)PI_2)
			player->angle -= (double)PI_2;
	}
}

static void	update_player_position(t_player *player, t_data *data)
{
	if (player->forward == TRUE)
		move_forward(player, data);
	if (player->back == TRUE)
		move_back(player, data);
	if (player->right == TRUE)
		move_right(player, data);
	if (player->left == TRUE)
		move_left(player, data);
}

void	update_player(t_player *player, t_data *data)
{
	update_angle(player);
	update_player_position(player, data);
}
