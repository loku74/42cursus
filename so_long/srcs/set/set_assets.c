/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_assets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:39:37 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/17 14:10:20 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	set_back(t_mlx *mlx)
{
	mlx->back = mlx_xpm_file_to_image(
			mlx->mlx,
			"Adventurer-xpm/assets/back.xpm",
			&mlx->pixel,
			&mlx->pixel);
}

static void	set_grass(t_mlx *mlx)
{
	mlx->grass = mlx_xpm_file_to_image(
			mlx->mlx,
			"Adventurer-xpm/assets/grass.xpm",
			&mlx->pixel,
			&mlx->pixel);
}

static void	set_dirt(t_mlx *mlx)
{
	mlx->dirt = mlx_xpm_file_to_image(
			mlx->mlx,
			"Adventurer-xpm/assets/dirt.xpm",
			&mlx->pixel,
			&mlx->pixel);
}

static void	set_wall(t_mlx *mlx)
{
	mlx->wall = mlx_xpm_file_to_image(
			mlx->mlx,
			"Adventurer-xpm/assets/wall.xpm",
			&mlx->pixel,
			&mlx->pixel);
}

void	set_assets(t_mlx *mlx)
{
	set_back(mlx);
	set_wall(mlx);
	set_dirt(mlx);
	set_grass(mlx);
	set_coin(mlx);
}
