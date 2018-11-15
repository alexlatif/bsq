/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fline_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:38:45 by alatif            #+#    #+#             */
/*   Updated: 2018/11/14 16:38:48 by alatif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLINE_LIST_H
# define FLINE_LIST_H

typedef struct s_list	t_list;

struct		s_list
{
	char	data;
	t_list	*next;
};

#endif
