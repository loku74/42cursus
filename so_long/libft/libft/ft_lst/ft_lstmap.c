/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:30:30 by lbourniq          #+#    #+#             */
/*   Updated: 2022/11/25 17:24:54 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*temp;

	result = NULL;
	if (f)
	{
		while (lst)
		{
			temp = ft_lstnew(f(lst->content));
			if (!temp)
			{
				ft_lstclear(&result, del);
				return (NULL);
			}
			ft_lstadd_back(&result, temp);
			lst = lst->next;
		}
	}
	return (result);
}
