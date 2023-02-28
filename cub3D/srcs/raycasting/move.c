/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinax <ratinax@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:19:46 by lbourniq          #+#    #+#             */
/*   Updated: 2023/02/17 17:11:15 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	set_pos(t_player *player, t_data *data, double dx, double dy)
{
	double	x;
	double	y;

	x = player->x + (dx * (double)PLAYER_SPEED);
	y = player->y + (dy * (double)PLAYER_SPEED);
	if (is_in(data->map[(int)(y + 0.2)][(int)(x + 0.2)], " 1"))
		return ;
	if (is_in(data->map[(int)(y + 0.2)][(int)(x - 0.2)], " 1"))
		return ;
	if (is_in(data->map[(int)(y - 0.2)][(int)(x + 0.2)], " 1"))
		return ;
	if (is_in(data->map[(int)(y - 0.2)][(int)(x - 0.2)], " 1"))
		return ;
	player->x = x;
	player->y = y;
}

void	move_forward(t_player *player, t_data *data)
{
	set_pos(player, data, cos(player->angle), sin(player->angle));
}

void	move_back(t_player *player, t_data *data)
{
	set_pos(player, data, -cos(player->angle), -sin(player->angle));
}

void	move_right(t_player *player, t_data *data)
{
	set_pos(player, data, -sin(player->angle), cos(player->angle));
}

void	move_left(t_player *player, t_data *data)
{
	set_pos(player, data, sin(player->angle), -cos(player->angle));
}
