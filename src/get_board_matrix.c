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

char	**get_matrix(char *buff, t_board binfo)
{
	char	**matrix;
	int		i;
	int		j;
	int		width;
	int		start;

	i = 0;
	matrix = malloc(sizeof(char*) * (binfo.lines + 1));
	while (buff[i] != '\n')
		i++;
	i += 1;
	start = i;
	while (buff[i] != '\n')
		i++;
	width = i - start;
	i = 0;
	while (i < binfo.lines)
	{
		j = 0;
		if (!check_valid_char(buff[start], binfo))
			ft_exit(ERR_VAL_BOARD);
		matrix[i] = malloc(sizeof(char) * (width + 1));
		while (buff[start] != '\n' && buff[start])
			matrix[i][j++] = buff[start++];
		if (j != width)
			ft_exit(ERR_VAL_BOARD);
		matrix[i][j] = '\0';
		start++;
		i++;
	}
	return (matrix);
}
