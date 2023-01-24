/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:10:21 by lbourniq          #+#    #+#             */
/*   Updated: 2022/11/30 15:07:33 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_verif_int(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	result = 0;
	sign = 1;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1])
	{
		if (str[i] == '-')
			sign = -1;
		str++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result != ((result * 10 + sign * (str[i] - 48)) / 10))
			return (0);
		result = result * 10 + sign * (str[i] - 48);
		i++;
	}
	if (ft_strlen(str) == 0 || str[i])
		return (0);
	return (1);
}

static int	ft_check_dup(t_llist **head, t_llist *node)
{
	t_llist	*temp;

	temp = *head;
	while (temp)
	{
		if (temp != node && temp->num == node->num)
			return (1);
		temp = temp->next;
	}
	return (0);
}

t_llist	*ft_create_list_a(int argc, char **argv)
{
	t_llist	*head;
	t_llist	*node;
	int		i;
	int		j;
	char	**tab;

	i = 0;
	head = NULL;
	while (++i < argc)
	{
		tab = ft_split(argv[i], ' ');
		j = 0;
		while (tab[j] != NULL)
		{
			node = ft_create_new_llist(ft_atoi(tab[j]));
			if (head == NULL)
				head = node;
			ft_llst_addback(&head, node);
			if (!node || !ft_verif_int(tab[j]) || ft_check_dup(&head, node))
				return (ft_free_all(&head, tab), NULL);
			j++;
		}
		free_tab(tab);
	}
	return (head);
}
