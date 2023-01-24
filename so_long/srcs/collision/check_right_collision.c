/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_right_collision.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:35:26 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/18 15:00:32 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_right_collision(t_mlx *mlx)
{
	int	x;
	int	y;

	x = mlx->sprite_x;
	y = mlx->sprite_y;
	if (x + 100 < mlx->map_width * 100)
	{
		if (mlx->map[(y + 74) / 100][x / 100 + 1] == '1')
		{
			if (x % 100 > 25)
				return (0);
		}
		if (mlx->map[(y + 37) / 100][x / 100 + 1] == '1')
		{
			if (x % 100 > 25)
				return (0);
		}
	}
	return (1);
}
