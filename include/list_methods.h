/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_methods.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:38:55 by alatif            #+#    #+#             */
/*   Updated: 2018/11/14 16:38:57 by alatif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_METHODS_H
# define LIST_METHODS_H

# include "fline_list.h"

void		print_list(t_list *list);
t_list		*ft_create_elem(char data);
void		ft_list_push_back(t_list **begin_list, char data);

#endif
