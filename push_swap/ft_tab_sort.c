/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 13:21:23 by lbourniq          #+#    #+#             */
/*   Updated: 2022/11/27 15:11:51 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_create_tab(t_llist *head)
{
	int	i;
	int	*tab;
	int	size;

	size = ft_llstsize(head);
	tab = (int *)malloc(sizeof(int) * size);
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		tab[i] = head->num;
		head = head->next;
		i++;
	}
	return (tab);
}

static void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	*ft_sort(t_llist *head)
{
	int	*tab;
	int	size;
	int	i;
	int	j;

	tab = ft_create_tab(head);
	if (tab == NULL)
		return (NULL);
	size = ft_llstsize(head);
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[j] < tab[i])
				ft_swap(&tab[j], &tab[i]);
			j++;
		}
		i++;
	}
	return (tab);
}
