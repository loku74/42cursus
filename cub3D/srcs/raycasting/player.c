/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:09:06 by lbourniq          #+#    #+#             */
/*   Updated: 2023/02/03 19:09:28 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	update_angle(t_player *player)
{
	if (player->move_fov_left == TRUE)
	{
		player->angle -= ANGLE_SPEED;
		if (player->angle < 0)
			player->angle += 2 * PI;
		player->dx = cos(player->angle);
		player->dy = sin(player->angle);
	}
	if (player->move_fov_right == TRUE)
	{
		player->angle += ANGLE_SPEED;
		if (player->angle > 2 * PI)
			player->angle -= 2 * PI;
		player->dx = cos(player->angle);
		player->dy = sin(player->angle);
	}
}

static void	update_position(t_player *player)
{
	if (player->forward == TRUE)
	{
		player->y += player->dy * PLAYER_SPEED;
		player->x += player->dx * PLAYER_SPEED;
	}
	if (player->back == TRUE)
	{
		player->y -= player->dy * PLAYER_SPEED;
		player->x -= player->dx * PLAYER_SPEED;
	}
	if (player->right == TRUE)
	{
		player->y += player->dx * PLAYER_SPEED;
		player->x -= player->dy * PLAYER_SPEED;
	}
	if (player->left == TRUE)
	{
		player->y -= player->dx * PLAYER_SPEED;
		player->x += player->dy * PLAYER_SPEED;
	}
}

void	update_player(t_player *player)
{
	update_angle(player);
	update_position(player);
}
