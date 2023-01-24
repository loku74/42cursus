/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 11:31:24 by lbourniq          #+#    #+#             */
/*   Updated: 2022/11/30 15:06:10 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
}

void	ft_free_all(t_llist **head, char **tab)
{
	t_llist	*temp;

	if (head != NULL)
	{
		while (*head != NULL)
		{
			temp = *head;
			(*head) = (*head)->next;
			free(temp->index);
			free(temp);
		}
	}
	if (tab)
		free_tab(tab);
}
