/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_coin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:02:37 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/18 18:29:53 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	update_coin(t_mlx *mlx, char *frame)
{
	if (mlx->coin_sprite != NULL)
		mlx_destroy_image(mlx->mlx, mlx->coin_sprite);
	mlx->coin_sprite = mlx_xpm_file_to_image(
			mlx->mlx,
			frame,
			&mlx->pixel,
			&mlx->pixel
			);
}
