/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:29:38 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/20 09:17:21 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	coin_animation(t_mlx *mlx)
{
	static int	counter = 0;
	static int	frame = 0;

	counter++;
	if (counter % 911 != 0)
		return ;
	update_coin(mlx, mlx->coin[frame]);
	frame++;
	if (frame == 6)
		frame = 0;
	if (counter == COUNTER_MAX)
		counter = 0;
}
