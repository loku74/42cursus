/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_jumping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:55:53 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/15 15:41:19 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	set_jumping_r(t_mlx *mlx)
{
	mlx->jumping_r[0] = "Adventurer-xpm/jump_right/adventurer-jump_r_01.xpm";
	mlx->jumping_r[1] = "Adventurer-xpm/jump_right/adventurer-jump_r_02.xpm";
	mlx->jumping_r[2] = "Adventurer-xpm/jump_right/adventurer-jump_r_03.xpm";
	mlx->jumping_r[3] = "Adventurer-xpm/jump_right/adventurer-jump_r_04.xpm";
	mlx->jumping_r[4] = "Adventurer-xpm/jump_right/adventurer-jump_r_05.xpm";
	mlx->jumping_r[5] = "Adventurer-xpm/jump_right/adventurer-jump_r_06.xpm";
	mlx->jumping_r[6] = "Adventurer-xpm/jump_right/adventurer-jump_r_07.xpm";
	mlx->jumping_r[7] = "Adventurer-xpm/jump_right/adventurer-jump_r_08.xpm";
}

void	set_jumping_l(t_mlx *mlx)
{
	mlx->jumping_l[0] = "Adventurer-xpm/jump_left/adventurer-jump_l_01.xpm";
	mlx->jumping_l[1] = "Adventurer-xpm/jump_left/adventurer-jump_l_02.xpm";
	mlx->jumping_l[2] = "Adventurer-xpm/jump_left/adventurer-jump_l_03.xpm";
	mlx->jumping_l[3] = "Adventurer-xpm/jump_left/adventurer-jump_l_04.xpm";
	mlx->jumping_l[4] = "Adventurer-xpm/jump_left/adventurer-jump_l_05.xpm";
	mlx->jumping_l[5] = "Adventurer-xpm/jump_left/adventurer-jump_l_06.xpm";
	mlx->jumping_l[6] = "Adventurer-xpm/jump_left/adventurer-jump_l_07.xpm";
	mlx->jumping_l[7] = "Adventurer-xpm/jump_left/adventurer-jump_l_08.xpm";
}
