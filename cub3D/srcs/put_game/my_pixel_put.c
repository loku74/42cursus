/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibernot <tibernot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:01:13 by lbourniq          #+#    #+#             */
/*   Updated: 2023/02/28 11:57:58 by tibernot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	*(int *)(img->addr + (y * img->line_length
				+ x * img->bits_per_pixel)) = color;
}
