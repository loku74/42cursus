/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:51:40 by lbourniq          #+#    #+#             */
/*   Updated: 2022/11/25 18:01:03 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	int		i;

	if (!ft_strlen(s) || !len || start > ft_strlen(s))
		return (ft_strdup("\0"));
	if (len >= ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	if (start <= ft_strlen(s))
	{
		while (s[start] && len--)
			res[i++] = s[start++];
	}
	res[i] = '\0';
	return (res);
}
