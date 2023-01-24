/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:19:15 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/18 17:39:31 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	parsing(t_mlx *mlx)
{
	mlx->exit_path = 0;
	mlx->collectibles_found = 0;
	check_map(mlx);
	path_finding(mlx, mlx->sprite_y, mlx->sprite_x);
	if (mlx->collectibles != mlx->collectibles_found)
		errexit(mlx, "No path found between the player and all collectible(s)");
	if (mlx->exit_path == 0)
		errexit(mlx, "No path found between the player and the exit");
}
