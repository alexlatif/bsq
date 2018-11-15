/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_board_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 23:36:37 by alatif            #+#    #+#             */
/*   Updated: 2018/11/13 23:36:40 by alatif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "board_info.h"
#include "utils.h"

t_board		get_binfo(char *fline)
{
	int			size;
	t_board		binfo;

	binfo.lines = ft_atoi(fline);
	size = ft_strlen(fline);
	binfo.empty = fline[size - 3];
	binfo.obstacle = fline[size - 2];
	binfo.full = fline[size - 1];
	return (binfo);
}

int			check_valid_char(char c, t_board binfo)
{
	if (c == binfo.empty || c == binfo.full || c == binfo.obstacle)
		return (1);
	return (0);
}
