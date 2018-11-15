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
#include "list_methods.h"
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

int		create_fline_list(t_list **fline, int fd)
{
	int		width;
	char	c;

	width = 0;
	while (read(fd, &c, 1) > 0 && c != '\n')
	{
		if (!width)
			*fline = ft_create_elem(c);
		else
			ft_list_push_back(fline, c);
		width++;
	}
	return (width);
}

char	*get_arr_from_link(char *str, t_list *fline, t_board binfo)
{
	int		i;

	i = 0;
	while (fline)
	{
		if (!check_valid_char(fline->data, binfo))
			ft_exit(ERR_VAL_BOARD);
		str[i++] = fline->data;
		fline = fline->next;
	}
	str[i] = '\0';
	return (str);
}

char	*get_matrix_arr(char *str, t_board binfo, int fd, int width)
{
	int		j;
	char	c;

	j = 0;
	while (read(fd, &c, 1) > 0 && c != '\n')
	{
		if (!check_valid_char(c, binfo))
			ft_exit(ERR_VAL_BOARD);
		str[j++] = c;
	}
	if (j != width)
		ft_exit(ERR_VAL_BOARD);
	str[j] = '\0';
	return (str);
}

char	**get_board_matrix(int fd, t_board binfo)
{
	char		**matrix;
	t_list		*fline;
	int			width;
	char		c;
	int			i;

	i = 0;
	width = create_fline_list(&fline, fd);
	matrix = malloc(sizeof(char*) * binfo.lines + 1);
	while (i < binfo.lines)
	{
		matrix[i] = malloc(sizeof(char) * width + 1);
		if (i == 0)
			matrix[i] = get_arr_from_link(matrix[i], fline, binfo);
		else
			matrix[i] = get_matrix_arr(matrix[i], binfo, fd, width);
		i++;
	}
	if (read(fd, &c, 1))
		ft_exit(ERR_VAL_BOARD);
	matrix[i] = 0;
	return (matrix);
}
