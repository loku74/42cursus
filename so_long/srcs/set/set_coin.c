/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_coin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:53:26 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/17 14:27:08 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	set_coin(t_mlx *mlx)
{
	mlx->coin[0] = "Adventurer-xpm/coin/coin_01.xpm";
	mlx->coin[1] = "Adventurer-xpm/coin/coin_02.xpm";
	mlx->coin[2] = "Adventurer-xpm/coin/coin_03.xpm";
	mlx->coin[3] = "Adventurer-xpm/coin/coin_04.xpm";
	mlx->coin[4] = "Adventurer-xpm/coin/coin_05.xpm";
	mlx->coin[5] = "Adventurer-xpm/coin/coin_06.xpm";
	update_coin(mlx, mlx->coin[0]);
}
