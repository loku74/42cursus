/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_ft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:20:41 by lbourniq          #+#    #+#             */
/*   Updated: 2022/11/28 18:11:56 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_ft(t_llist **head1, t_llist **head2, char c)
{
	t_llist	*temp;

	if (head1 == NULL || *head1 == NULL)
		return ;
	temp = *head1;
	*head1 = (*head1)->next;
	temp->next = NULL;
	ft_llst_addfront(head2, temp);
	if (c == 'a')
		ft_printf("pa\n");
	else if (c == 'b')
		ft_printf("pb\n");
}
