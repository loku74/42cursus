/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup_no_nl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:47:51 by lbourniq          #+#    #+#             */
/*   Updated: 2023/01/25 17:47:52 by lbourniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char	*strdup_no_nl(const char *str)
{
	char	*ret;
	int		i;

	ret = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (str AND str[i] AND str[i] != '\n')
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
