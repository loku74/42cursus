/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shiftup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:15:56 by lbourniq          #+#    #+#             */
/*   Updated: 2022/11/29 17:24:57 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_shiftup(t_llist **head, char c)
{
	t_llist	*first_node;

	if ((*head) == NULL || (*head)->next == NULL)
		return ;
	first_node = *head;
	(*head) = (*head)->next;
	first_node->next = NULL;
	ft_llst_addback(head, first_node);
	if (c == 'a')
		ft_printf("ra\n");
	else if (c == 'b')
		ft_printf("rb\n");
}
