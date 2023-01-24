/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_idle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:18:26 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/13 16:09:15 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	set_idle_right(t_mlx *mlx)
{
	mlx->idle_r[0] = "Adventurer-xpm/idle_right/adventurer-idle_r_01.xpm";
	mlx->idle_r[1] = "Adventurer-xpm/idle_right/adventurer-idle_r_02.xpm";
	mlx->idle_r[2] = "Adventurer-xpm/idle_right/adventurer-idle_r_03.xpm";
	mlx->idle_r[3] = "Adventurer-xpm/idle_right/adventurer-idle_r_04.xpm";
}

void	set_idle_left(t_mlx *mlx)
{
	mlx->idle_l[0] = "Adventurer-xpm/idle_left/adventurer-idle_l_01.xpm";
	mlx->idle_l[1] = "Adventurer-xpm/idle_left/adventurer-idle_l_02.xpm";
	mlx->idle_l[2] = "Adventurer-xpm/idle_left/adventurer-idle_l_03.xpm";
	mlx->idle_l[3] = "Adventurer-xpm/idle_left/adventurer-idle_l_04.xpm";
}
