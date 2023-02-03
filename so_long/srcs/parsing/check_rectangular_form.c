/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rectangular_form.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:26:40 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/18 17:39:12 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_rectangular_form(t_mlx *mlx)
{
	int		temp;
	int		i;
	int		k;

	k = 0;
	temp = 0;
	while (mlx->map[k])
	{
		i = 0;
		while (mlx->map[k][i] && mlx->map[k][i] != '\n')
		{
			if (mlx->map[k][i] == 'P')
			{
				mlx->sprite_x = i;
				mlx->sprite_y = k;
			}
			i++;
		}
		if (k != 0 && temp != i)
			errexit(mlx, "The map has to be rectangular");
		temp = i;
		k++;
	}
}
