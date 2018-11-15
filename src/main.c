/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 23:37:04 by alatif            #+#    #+#             */
/*   Updated: 2018/11/13 23:37:07 by alatif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "board_methods.h"
#include "board_info.h"
#include "utils.h"

int		ft_get_header(t_board *binfo, int fd)
{
	char		head[15];
	int			digits;
	int			n;
	int			i;

	i = 0;
	while (read(fd, &(head[i]), 1) > 0 && head[i] != '\n' && i < 14)
		i++;
	binfo->full = head[i - 1];
	binfo->obstacle = head[i - 2];
	binfo->empty = head[i - 3];
	head[i - 3] = '\0';
	binfo->lines = ft_atoi(head);
	digits = 1;
	n = binfo->lines;
	while (n >= 10 && digits++)
		n /= 10;
	if (binfo->full == binfo->empty || binfo->full == binfo->obstacle ||
	binfo->obstacle == binfo->empty || binfo->lines < 1 || digits + 3 != i)
		return (0);
	return (1);
}

void	free_board(char **matrix)
{
	int i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	solve_map(int fd)
{
	int			header;
	char		**matrix;
	t_board		binfo;

	if (!(header = ft_get_header(&binfo, fd)))
		ft_exit(ERR_VAL_BOARD);
	matrix = get_board_matrix(fd, binfo);
	matrix = solve_matrix(matrix, binfo);
	//print_board(matrix);
	free_board(matrix);
}

int		main(int argc, char *argv[])
{
	int		fd;
	int		i;

	i = 1;
	if (argc == 1)
	{
		solve_map(0);
		return (0);
	}
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
			ft_exit(ERR_FILE);
		solve_map(fd);
		if (close(fd) < 0)
			ft_exit(ERR_FILE);
		i++;
	}
	return (0);
}
