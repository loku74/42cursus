/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:22:12 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/19 17:28:55 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	move(t_mlx *mlx, int frame)
{
	mlx->sprite_y += 5;
	if (mlx->left == 1)
	{
		update_sprite(mlx, mlx->falling_l[frame]);
		if (mlx->run_l == 1 && check_left_collision(mlx))
		{
			mlx->sprite_x -= 5;
			mlx->steps++;
		}
	}
	else
	{
		update_sprite(mlx, mlx->falling_r[frame]);
		if (mlx->run_r == 1 && check_right_collision(mlx))
		{
			mlx->sprite_x += 5;
			mlx->steps++;
		}
	}
	mlx->steps++;
	update_window(mlx);
}

void	fall(t_mlx *mlx)
{
	static int	counter = 0;
	static int	frame = 0;

	counter++;
	if (counter % 331 == 0 && mlx->jumping == 0)
	{
		frame++;
		if (frame == 2)
			frame = 0;
	}
	if (counter % 111 == 0 && mlx->jumping == 0)
		move(mlx, frame);
	if (counter == COUNTER_MAX)
		counter = 0;
}
