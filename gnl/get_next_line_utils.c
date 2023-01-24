/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:08:49 by lbourniq          #+#    #+#             */
/*   Updated: 2022/11/25 10:55:05 by lbourniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
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

char	*ft_strchr(char *s, int c)
{
	unsigned int	i;

	i = 0;
	if ((char)c == '\0')
		return ((char *)(s + ft_strlen(s)));
	while (s && s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

char	*ft_strdup(char *str)
{
	char	*ret;
	int		i;

	ret = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (str && str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*add_buf(char *line, char *buf)
{
	char	*res;
	char	*returned;

	res = ft_strdup(line);
	if (!res)
		return (NULL);
	free(line);
	returned = ft_strjoin(res, buf);
	free(res);
	return (returned);
}
