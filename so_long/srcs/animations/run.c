/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:34:45 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/20 09:17:30 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	move(t_mlx *mlx, int frame)
{
	if (mlx->left == 1 && mlx->run_l == 1)
	{
		update_sprite(mlx, mlx->running_l[frame]);
		if (check_left_collision(mlx))
		{
			mlx->sprite_x -= 5;
			mlx->steps++;
		}
	}
	else if (mlx->left == 0 && mlx->run_r == 1)
	{
		update_sprite(mlx, mlx->running_r[frame]);
		if (check_right_collision(mlx))
		{
			mlx->sprite_x += 5;
			mlx->steps++;
		}
	}
	update_window(mlx);
}

void	run(t_mlx *mlx)
{
	static int	counter = 0;
	static int	frame = 0;

	counter++;
	if (counter % 664 == 0)
	{
		frame++;
		if (frame == 6)
			frame = 0;
	}
	if (counter % 111 == 0 && mlx->jumping == 0 && mlx->falling == 0)
		move(mlx, frame);
	if (counter == COUNTER_MAX)
		counter = 0;
}
