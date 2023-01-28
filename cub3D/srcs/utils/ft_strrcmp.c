/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:05:46 by lbourniq          #+#    #+#             */
/*   Updated: 2023/01/24 15:05:47 by lbourniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_bool	ft_strrcmp(char *s1, char *s2, int n)
{
	int	i;
	int	j;
	int	index;

	index = 0;
	i = (int)ft_strlen(s1) - 1;
	j = (int)ft_strlen(s2) - 1;
	while (index < n AND (s1[i] == s2[j]) AND s1[i] AND s2[j])
	{
		i--;
		j--;
		index++;
	}
	if (n != index)
		return (FALSE);
	return (TRUE);
}
