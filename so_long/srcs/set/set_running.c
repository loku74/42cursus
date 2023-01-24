/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_running.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:52:22 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/13 16:06:30 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	set_running_right(t_mlx *mlx)
{
	mlx->running_r[0] = "Adventurer-xpm/run_right/adventurer-run_r_01.xpm";
	mlx->running_r[1] = "Adventurer-xpm/run_right/adventurer-run_r_02.xpm";
	mlx->running_r[2] = "Adventurer-xpm/run_right/adventurer-run_r_03.xpm";
	mlx->running_r[3] = "Adventurer-xpm/run_right/adventurer-run_r_04.xpm";
	mlx->running_r[4] = "Adventurer-xpm/run_right/adventurer-run_r_05.xpm";
	mlx->running_r[5] = "Adventurer-xpm/run_right/adventurer-run_r_06.xpm";
}

void	set_running_left(t_mlx *mlx)
{
	mlx->running_l[0] = "Adventurer-xpm/run_left/adventurer-run_l_01.xpm";
	mlx->running_l[1] = "Adventurer-xpm/run_left/adventurer-run_l_02.xpm";
	mlx->running_l[2] = "Adventurer-xpm/run_left/adventurer-run_l_03.xpm";
	mlx->running_l[3] = "Adventurer-xpm/run_left/adventurer-run_l_04.xpm";
	mlx->running_l[4] = "Adventurer-xpm/run_left/adventurer-run_l_05.xpm";
	mlx->running_l[5] = "Adventurer-xpm/run_left/adventurer-run_l_06.xpm";
}
