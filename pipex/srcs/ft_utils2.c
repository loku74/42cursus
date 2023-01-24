/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:23:53 by lbourniq          #+#    #+#             */
/*   Updated: 2023/01/22 12:11:04 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	is_in(char *str, char *charset)
{
	int	i;
	int	k;

	i = 0;
	while (str[i])
	{
		k = 0;
		while (charset[k])
		{
			if (str[i] == charset[k])
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}

char	*ft_pipex_strrchr(char *s, int c)
{
	int	i;

	i = ((size_t)ft_strlen(s)) - 1;
	if ((char)c == '\0')
		return ((char *)(s + i + 1));
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i + 1));
		i--;
	}
	return (s);
}
