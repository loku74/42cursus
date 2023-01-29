/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:12:21 by lbourniq          #+#    #+#             */
/*   Updated: 2023/01/28 16:12:23 by lbourniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	count_comma(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	return (count);
}

t_exit	check_rgb(char *rgb)
{
	int	i;
	int	len_rgb;

	i = 0;
	len_rgb = (int)ft_strlen(rgb);
	if (ft_isdigit(rgb[i]) == FALSE OR ft_isdigit(rgb[len_rgb - 1]) == FALSE)
		return (r_error(RGB_ERROR));
	if (count_comma(rgb) != 2)
		return (r_error(RGB_ERROR));
	return (SUCCESS);
}
