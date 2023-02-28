/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_imgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibernot <tibernot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:40:25 by ratinax           #+#    #+#             */
/*   Updated: 2023/02/21 17:55:29 by tibernot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	destroy_image(void *mlx_ptr, t_img *img)
{
	if (!img)
		return ;
	mlx_destroy_image(mlx_ptr, img->img);
	free(img);
}

void	destroy_all_images(t_data *d)
{
	destroy_image(d->mlx->mlx, d->img_background);
	destroy_image(d->mlx->mlx, d->img_walls);
}
