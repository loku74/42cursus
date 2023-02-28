/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinax <ratinax@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:25:08 by lbourniq          #+#    #+#             */
/*   Updated: 2023/02/09 16:35:20 by ratinax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_dict	*create_new_dict(void)
{
	t_dict	*dict;

	dict = (t_dict *)malloc(sizeof(t_dict));
	if (dict == NULL)
		return (NULL);
	dict->key = NULL;
	dict->value = NULL;
	dict->next = NULL;
	return (dict);
}

void	clear_dict(t_dict *head)
{
	t_dict	*temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->key);
		free(temp->value);
		free(temp);
	}
}

t_exit	add_dict(t_dict *head, char *key_in, char *value_in)
{
	char	*key;
	char	*value;

	key = ft_strdup(key_in);
	if (key == NULL)
		return (ERROR);
	value = ft_strdup(value_in);
	if (value == NULL)
		return (free(key), ERROR);
	if (head->key == NULL OR head->value == NULL)
	{
		head->key = key;
		head->value = value;
		return (SUCCESS);
	}
	while (head->next)
		head = head->next;
	head->next = create_new_dict();
	if (head->next == NULL)
		return (free(key), free(value), ERROR);
	head->next->key = key;
	head->next->value = value;
	return (SUCCESS);
}

char	*get_value(t_dict *head, char *key)
{
	while (head)
	{
		if (head->key != NULL AND ft_strncmp(head->key, key, \
		ft_strlen(key)) == 0)
			return (head->value);
		head = head->next;
	}
	return (NULL);
}
