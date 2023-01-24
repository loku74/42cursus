/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_f2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:11:22 by lbourniq          #+#    #+#             */
/*   Updated: 2022/11/30 17:44:36 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_f2(t_llist *head, char c)
{
	int	temp;

	if (head && head->next)
	{
		temp = head->num;
		head->num = head->next->num;
		head->next->num = temp;
		if (c == 'a')
			ft_printf("sa\n");
		else if (c == 'b')
			ft_printf("sb\n");
	}
}
