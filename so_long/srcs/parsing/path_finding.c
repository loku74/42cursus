/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 09:03:40 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/17 13:45:00 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	path_finding(t_mlx *mlx, int y, int x)
{
	if (mlx->map_c[y][x] == '1')
		return ;
	else if (mlx->map_c[y][x] == 'C')
		mlx->collectibles_found++;
	else if (mlx->map_c[y][x] == 'E')
		mlx->exit_path = 1;
	mlx->map_c[y][x] = '1';
	path_finding(mlx, y, x + 1);
	path_finding(mlx, y, x - 1);
	path_finding(mlx, y + 1, x);
	path_finding(mlx, y - 1, x);
}
