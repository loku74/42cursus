/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:55:42 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/18 17:38:54 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	print_exit_error(t_mlx *mlx, int count_exit)
{
	if (count_exit == 0)
		errexit(mlx, "The map must contain an exit");
	else if (count_exit > 1)
		errexit(mlx, "The map must contain not more than 1 exit");
}

static void	print_player_error(t_mlx *mlx, int count_player)
{
	if (count_player == 0)
		errexit(mlx, "The map must contain a player spawn");
	else if (count_player > 1)
		errexit(mlx, "The map must contain not more than 1 player spawn");
}

static void	print_collectibles_error(t_mlx *mlx, int count_collectibles)
{
	if (count_collectibles == 0)
		errexit(mlx, "The map must a least contain 1 collectible");
}

static int	check_c(int c, int *count_p, int *count_e, int *count_c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P')
	{
		if (c == 'C')
			(*count_c)++;
		else if (c == 'E')
			(*count_e)++;
		else if (c == 'P')
			(*count_p)++;
		return (1);
	}
	return (0);
}

void	check_map_format(t_mlx *mlx)
{
	int	i;
	int	k;
	int	count_e;
	int	count_p;
	int	count_c;

	i = 0;
	count_e = 0;
	count_p = 0;
	count_c = 0;
	while (mlx->map[i])
	{
		k = 0;
		while (mlx->map[i][k])
		{
			if (!check_c(mlx->map[i][k], &count_p, &count_e, &count_c))
				errexit(mlx, "The map must only contains 0, 1, E, C and P");
			k++;
		}
		i++;
	}
	print_exit_error(mlx, count_e);
	print_player_error(mlx, count_p);
	print_collectibles_error(mlx, count_c);
	mlx->collectibles = count_c;
}
