/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:17:06 by lbourniq          #+#    #+#             */
/*   Updated: 2023/01/25 17:17:07 by lbourniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	len_split(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
		i++;
	return (i);
}

int	len_dict(t_dict *dict)
{
	int	i;

	i = 0;
	while (dict != NULL)
	{
		dict = dict->next;
		i++;
	}
	return (i);
}
