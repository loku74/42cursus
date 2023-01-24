/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:29:11 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/18 18:29:30 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	update_sprite(t_mlx *mlx, char *frame)
{
	if (mlx->sprite != NULL)
		mlx_destroy_image(mlx->mlx, mlx->sprite);
	mlx->sprite = mlx_xpm_file_to_image(
			mlx->mlx,
			frame,
			&mlx->sprite_h,
			&mlx->sprite_w
			);
}
