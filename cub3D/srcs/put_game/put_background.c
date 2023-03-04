/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_background.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibernot <tibernot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:53:49 by tibernot          #+#    #+#             */
/*   Updated: 2023/03/03 09:48:36 by tibernot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	put_background(t_data *d, int lineH, int up_of_line, int x)
{
	int	i;
	int	coo_c;
	int	coo_f;
	int	coo;

	i = 0;
	coo_c = x * d->img_background->bits_per_pixel;
	coo_f = x * d->img_background->bits_per_pixel
		+ ((up_of_line + lineH) * d->img_background->line_length);
	coo = 0;
	while (i < up_of_line)
	{
		if (*(uint32_t *)(d->img_background->addr + coo_c + coo)
			!= d->ceiling_color)
			*(int *)(d->img_background->addr + coo_c + coo) = d->ceiling_color;
		if (*(uint32_t *)(d->img_background->addr + coo_f + coo)
			!= d->floor_color)
			*(int *)(d->img_background->addr + coo_f + coo) = d->floor_color;
		coo += d->img_background->line_length;
		i++;
	}
}
