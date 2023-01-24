/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:21:48 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/19 17:38:14 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	portal_animation(t_mlx *mlx)
{
	static int	counter = 0;
	static int	frame = 1;

	if (mlx->collectibles_collected != mlx->collectibles_found)
		return ;
	else
		mlx->finish = 1;
	counter++;
	if (counter % 1111 != 0)
		return ;
	update_portal(mlx, mlx->portal[frame]);
	frame++;
	if (frame == 5)
		frame = 1;
	if (counter == COUNTER_MAX)
		counter = 0;
}
