/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 09:04:56 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/08 15:53:48 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	free_all(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
}

static int	count_words(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] != '\0' && str[i] != ' ')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			return (3);
		i++;
	}
	return (2);
}

static char	*ft_first_split(char *str)
{
	char	**strs;
	char	*res;

	strs = ft_split(str, ' ');
	res = ft_strdup(strs[0]);
	free_all(strs);
	return (res);
}

static char	*ft_second_split(char *str)
{
	char	*res;
	int		i;

	i = 0;
	while (*str && *str == ' ')
		str++;
	while (*str && *str != ' ')
		str++;
	if (*str)
		str++;
	res = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (res == NULL)
		return (NULL);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	return (res);
}

char	**ft_pipex_split(char *str)
{
	char	**res;
	int		strs;

	strs = count_words(str);
	res = (char **)malloc(sizeof(char *) * strs);
	if (res == NULL)
		return (NULL);
	if (strs == 2)
	{
		free(res);
		return (ft_split((const char *)str, ' '));
	}
	res[0] = ft_first_split(str);
	res[1] = ft_second_split(str);
	res[2] = NULL;
	return (res);
}
