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
#include <stdlib.h>

int		find_swipe(char **matrix, char obstacle, int *arr, int swipe)
{
	int		i;
	int		j;

	if (matrix[arr[0]][arr[1]] == obstacle)
		return (-1);
	if (matrix[0][arr[1] + 1 + swipe] && matrix[arr[0] + 1 + swipe])
	{
		i = arr[0];
		while (i < arr[0] + 1 + swipe)
		{
			if (matrix[i++][arr[1] + 1 + swipe] == obstacle)
				return (swipe);
		}
		j = arr[1];
		while (j <= arr[1] + 1 + swipe)
		{
			if (matrix[i][j++] == obstacle)
				return (swipe);
		}
		swipe++;
		return (find_swipe(matrix, obstacle, arr, swipe));
	}
	else
		return (swipe);
}

t_snap	find_snapshot(char **matrix, t_board binfo)
{
	t_snap			snapshot;
	int				*arr;
	int				swipe;

	snapshot.swipe = -1;
	arr = malloc(2);
	arr[0] = 0;
	while (arr[0] < binfo.lines)
	{
		arr[1] = 0;
		while (matrix[arr[0]][arr[1]] != '\0')
		{
			swipe = find_swipe(matrix, binfo.obstacle, arr, 0);
			if (swipe > snapshot.swipe)
			{
				snapshot.x = arr[1];
				snapshot.y = arr[0];
				snapshot.swipe = swipe;
			}
			arr[1]++;
		}
		arr[0]++;
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
