/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_portal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:14:02 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/18 18:47:23 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	update_portal(t_mlx *mlx, char *frame)
{
	if (mlx->portal_sprite != NULL)
		mlx_destroy_image(mlx->mlx, mlx->portal_sprite);
	mlx->portal_sprite = mlx_xpm_file_to_image(
			mlx->mlx,
			frame,
			&mlx->pixel,
			&mlx->pixel
			);
}
