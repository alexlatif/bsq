/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:36:48 by alatif            #+#    #+#             */
/*   Updated: 2018/11/14 16:36:54 by alatif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"

t_list		*ft_create_elem(char data)
{
	t_list		*tmp;

	if (!(tmp = malloc(sizeof(t_list))))
		return (0);
	if (tmp)
	{
		tmp->data = data;
		tmp->next = NULL;
	}
	return (tmp);
}

void	ft_list_push_back(t_list **begin_list, char data)
{
	t_list		*new_node;
	t_list		*current;

	new_node = ft_create_elem(data);
	if (*begin_list == 0)
		(*begin_list) = new_node;
	else
	{
		current = (*begin_list);
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
}
