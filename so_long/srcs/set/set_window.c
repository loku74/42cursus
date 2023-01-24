/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:50:45 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/17 10:10:02 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	set_window(t_mlx *mlx)
{
	mlx->win_x = mlx->map_width * 100;
	mlx->win_y = mlx->map_height * 100;
}
