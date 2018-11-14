/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_board_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 23:36:53 by alatif            #+#    #+#             */
/*   Updated: 2018/11/13 23:36:57 by alatif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "board_info.h"
#include "utils.h"

void	print_board(char **board)
{
	int		i;

	i = 0;
	while (board[i] != 0)
	{
		ft_putstr(board[i++]);
		ft_putchar('\n');
	}
}

int		*get_width(char *buff)
{
	int		*arr;
	int		i;

	i = 0;
	arr = malloc(2);
	while (buff[i] != '\n')
		i++;
	i += 1;
	arr[0] = i;
	while (buff[i] != '\n')
		i++;
	arr[1] = i - arr[0];
	return (arr);
}

char	**get_matrix(char *buff, t_board binfo)
{
	char	**matrix;
	int		*arr;
	int		j;
	int		i;

	i = 0;
	matrix = malloc(sizeof(char*) * (binfo.lines + 1));
	arr = get_width(buff);
	while (i < binfo.lines)
	{
		j = 0;
		if (!check_valid_char(buff[arr[0]], binfo))
			ft_exit(ERR_VAL_BOARD);
		matrix[i] = malloc(sizeof(char) * (arr[1] + 1));
		while (buff[arr[0]] != '\n' && buff[arr[0]])
			matrix[i][j++] = buff[arr[0]++];
		if (j != arr[1])
			ft_exit(ERR_VAL_BOARD);
		matrix[i][j] = '\0';
		arr[0]++;
		i++;
	}
	return (matrix);
}
