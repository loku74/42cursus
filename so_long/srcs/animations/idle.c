/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idle.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:51:56 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/19 14:27:55 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	idle(t_mlx *mlx)
{
	static int	counter = 0;
	static int	frame = 0;

	counter++;
	if (counter % 1111 != 0)
		return ;
	if (mlx->left == 1)
		update_sprite(mlx, mlx->idle_l[frame]);
	else
		update_sprite(mlx, mlx->idle_r[frame]);
	update_window(mlx);
	frame++;
	if (frame == 4)
		frame = 0;
	if (counter == COUNTER_MAX)
		counter = 0;
}
