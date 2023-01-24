/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_falling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:55:25 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/15 17:38:59 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	set_falling_r(t_mlx *mlx)
{
	mlx->falling_r[0] = "Adventurer-xpm/fall_right/adventurer-fall_r_01.xpm";
	mlx->falling_r[1] = "Adventurer-xpm/fall_right/adventurer-fall_r_02.xpm";
}

void	set_falling_l(t_mlx *mlx)
{
	mlx->falling_l[0] = "Adventurer-xpm/fall_left/adventurer-fall_l_01.xpm";
	mlx->falling_l[1] = "Adventurer-xpm/fall_left/adventurer-fall_l_02.xpm";
}
