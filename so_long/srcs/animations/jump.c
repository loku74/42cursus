/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:59:35 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/20 09:32:09 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	move(t_mlx *mlx, int frame)
{
	if (mlx->left == 1)
	{
		update_sprite(mlx, mlx->jumping_l[frame]);
		if (mlx->run_l == 1 && check_left_collision(mlx))
		{
			mlx->sprite_x -= 5;
			mlx->steps++;
		}
	}
	else
	{
		update_sprite(mlx, mlx->jumping_r[frame]);
		if (mlx->run_r == 1 && check_right_collision(mlx))
		{
			mlx->sprite_x += 5;
			mlx->steps++;
		}
	}
	if (check_top_collision(mlx) == 0)
	{
		mlx->sprite_y -= 5;
		mlx->steps++;
	}
	update_window(mlx);
}

void	jump(t_mlx *mlx)
{
	static int	counter = 0;

	counter++;
	if (counter % 331 == 0)
		mlx->jump_frame++;
	if (mlx->jump_frame == 8)
	{
		mlx->jump_frame = 0;
		if (mlx->curr_jumping == 0)
			mlx->jumping = 0;
		if (mlx->run_r == 0 && mlx->run_l == 0 && mlx->curr_jumping == 0)
			mlx->idle = 1;
	}
	if (counter % 111 == 0 && mlx->jumping == 1)
		move(mlx, mlx->jump_frame);
	if (counter == COUNTER_MAX)
		counter = 0;
}
