/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 05:00:26 by alatif            #+#    #+#             */
/*   Updated: 2018/11/14 05:00:29 by alatif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snap.h"
#include "board_info.h"
#include <stdio.h>

int		find_swipe(char **matrix, char obstacle, int x, int y, int swipe)
{
	int		i;
	int		j;

	if (matrix[y][x] == obstacle)
		return (-1);
	if (matrix[0][x + 1 + swipe] && matrix[y + 1 + swipe])
	{
		i = y;
		while (i < y + 1 + swipe)
		{
			if (matrix[i++][x + 1 + swipe] == obstacle)
				return (swipe);
		}
		j = x;
		while (j <= x + 1 + swipe)
		{
			if (matrix[i][j++] == obstacle)
				return (swipe);
		}
		swipe++;
		return (find_swipe(matrix, obstacle, x, y, swipe));
	}
	else
		return (swipe);
}

t_snap	find_snapshot(char **matrix, t_board binfo)
{
	t_snap			snapshot;
	int				i;
	int				j;
	int				swipe;

	snapshot.swipe = -1;
	i = 0;
	while (i < binfo.lines)
	{
		j = 0;
		while (matrix[i][j] != '\0')
		{
			swipe = find_swipe(matrix, binfo.obstacle, j, i, 0);
			if (swipe > snapshot.swipe)
			{
				snapshot.x = j;
				snapshot.y = i;
				snapshot.swipe = swipe;
			}
			j++;
		}
		i++;
	}
	return (snapshot);
}

char	**fill_matrix(char **matrix, t_snap snapshot, char full)
{
	int		i;
	int		j;

	i = snapshot.y;
	while (i <= snapshot.y + snapshot.swipe)
	{
		j = snapshot.x;
		while (j <= snapshot.x + snapshot.swipe)
		{
			matrix[i][j] = full;
			j++;
		}
		i++;
	}
	return (matrix);
}

char	**solve_matrix(char **matrix, t_board binfo)
{
	t_snap			snapshot;

	snapshot = find_snapshot(matrix, binfo);
	printf("arr[%d][%d] = %d swipes\n", snapshot.y, snapshot.x, snapshot.swipe);
	fill_matrix(matrix, snapshot, binfo.full);
	return (matrix);
}
