/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 08:58:08 by lbourniq          #+#    #+#             */
/*   Updated: 2022/11/25 17:24:33 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	check_char(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	i;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && check_char(set, s1[start]))
		start++;
	while (end > 0 && s1[end] && check_char(set, s1[end]))
		end--;
	if (end < start)
		return (ft_strdup("\0"));
	res = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!res)
		return (NULL);
	while (start < end + 1)
		res[i++] = s1[start++];
	res[i] = '\0';
	return (res);
}
