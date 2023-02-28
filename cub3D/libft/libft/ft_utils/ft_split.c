/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:26:08 by lbourniq          #+#    #+#             */
/*   Updated: 2023/02/24 18:18:04 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	*free_all(char **tab, size_t nelem)
{
	size_t	i;

	i = 0;
	while (i < nelem)
		free(tab[i++]);
	free(tab);
	return (NULL);
}

static size_t	next_c(const char *str, const char *charset)
{
	unsigned int	i;
	unsigned int	k;

	i = 0;
	while (str[i])
	{
		k = 0;
		while (charset[k])
		{
			if (str[i] == charset[k])
				return (i);
			k++;
		}
		i++;
	}
	return (i);
}

static unsigned int	count_words(char const *str, char *charset)
{
	size_t			i;
	unsigned int	count;

	count = 1;
	i = 0;
	while (ft_is_in(str[i], charset))
		i++;
	if (i == ft_strlen(str))
		return (count);
	while (i < ft_strlen(str))
	{
		if (!ft_is_in(str[i], charset))
		{
			count++;
			while (i < ft_strlen(str))
			{
				if (ft_is_in(str[i], charset))
					break ;
				i++;
			}
		}
		i++;
	}
	return (count);
}

static char	**ft_strsplit(char **tab, char const *s, char *set)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (i < ft_strlen(s))
	{
		if (next_c(&s[i], set))
		{
			tab[j] = (char *)malloc(sizeof(char) * (next_c(&s[i], set) + 1));
			if (!tab[j])
				return (free_all(tab, j));
			k = 0;
			while (next_c(&s[i], set))
				tab[j][k++] = s[i++];
			tab[j++][k] = '\0';
		}
		i++;
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char *charset)
{
	char			**tab;

	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * ((count_words(s, charset))));
	if (!tab)
		return (NULL);
	return (ft_strsplit(tab, s, charset));
}
