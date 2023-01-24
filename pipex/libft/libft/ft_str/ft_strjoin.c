/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 08:54:48 by lbourniq          #+#    #+#             */
/*   Updated: 2022/11/25 17:24:42 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	res_length;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	res_length = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char *)malloc(sizeof(char) * res_length);
	if (!res)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2 && s2[i])
	{
		res[i + ft_strlen(s1)] = s2[i];
		i++;
	}
	res[res_length - 1] = '\0';
	return (res);
}
