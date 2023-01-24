/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shiftdown.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:27:06 by lbourniq          #+#    #+#             */
/*   Updated: 2022/11/30 15:32:27 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_shiftdown(t_llist **head, char c)
{
	t_llist	*first_node;
	t_llist	*last_node;
	t_llist	*previous_last_node;

	if ((*head) == NULL || (*head)->next == NULL)
		return ;
	first_node = *head;
	previous_last_node = *head;
	while (previous_last_node->next->next)
		previous_last_node = previous_last_node->next;
	last_node = previous_last_node->next;
	previous_last_node->next = NULL;
	last_node->next = first_node;
	ft_llst_addfront(head, last_node);
	if (c == 'a')
		ft_printf("rra\n");
	else if (c == 'b')
		ft_printf("rrb\n");
}
