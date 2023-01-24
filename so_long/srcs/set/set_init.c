/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:46:00 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/19 15:32:51 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	set_init(t_mlx *mlx)
{
	mlx->map = NULL;
	mlx->map_c = NULL;
	mlx->sprite = NULL;
	mlx->coin_sprite = NULL;
	mlx->win = NULL;
	mlx->portal_sprite = NULL;
	mlx->finish = 0;
	mlx->back = NULL;
	mlx->wall = NULL;
	mlx->grass = NULL;
	mlx->dirt = NULL;
	mlx->steps = 0;
}
