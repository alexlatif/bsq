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

	binfo.error = 0;
	if (((header = ft_get_header(&binfo, fd))))
	{
		matrix = get_board_matrix(fd, &binfo);
		if (!binfo.no_obs)
			matrix = solve_empty(matrix, binfo);
		else
			matrix = solve_matrix(matrix, binfo);
		if (!binfo.error)
			print_board(matrix);
		free_board(matrix);
	}
	else
		ft_exit(ERR_VAL_BOARD, NULL);
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
		if (fd > -1)
		{
			solve_map(fd);
			if (close(fd) < 0)
				ft_exit(ERR_FILE, NULL);
		}
		else
			ft_exit(ERR_FILE, NULL);
		i++;
	}
	return (0);
}
