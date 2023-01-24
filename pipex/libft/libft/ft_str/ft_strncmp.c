/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:34:53 by lbourniq          #+#    #+#             */
/*   Updated: 2022/11/25 17:24:38 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n - 1 && (s1[i] == s2[i]) && s1[i] && s2[i])
		i++;
	if (n && n != i)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
