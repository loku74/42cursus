/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_left_collision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 09:18:58 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/18 14:57:57 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_left_collision(t_mlx *mlx)
{
	int	x;
	int	y;

	x = mlx->sprite_x;
	y = mlx->sprite_y;
	if (mlx->map[(y + 37) / 100][x / 100] == '1')
	{
		if (x % 100 < 75)
			return (0);
	}
	if (mlx->map[(y + 74) / 100][x / 100] == '1')
	{
		if (x % 100 < 75)
			return (0);
	}
	return (1);
}
