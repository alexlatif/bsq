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

char	*get_header(int fd)
{
	int		i;
	char	c;
	char	*fline;

	if (!(fline = malloc(sizeof(char) * FLINE_MAX_SIZE)))
		ft_exit(ERR_MALLOC_BOARD_INFO);
	i = 0;
	while (read(fd, &c, 1) && c != '\n')
	{
		fline[i] = c;
		i++;
	}
	fline[i] = '\0';
	return (fline);
}

char	*stdin_map(char *filename)
{
	int		fd;
	char	c;

	fd = open(filename, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1)
		ft_exit(ERR_FILE);
	while (read(STDIN_FILENO, &c, 1) > 0)
		ft_fputchar(fd, c);
	if (close(fd) < 0)
		ft_exit(ERR_FILE);
	return (filename);
}

void	solve_map(char *filename)
{
	int			fd;
	char		*header;
	char		**matrix;
	t_board		binfo;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_exit(ERR_FILE);
	header = get_header(fd);
	if (!check_valid_top_line(header))
		ft_exit(ERR_VAL_BOARD);
	binfo = get_binfo(header);
	matrix = get_board_matrix(fd, binfo);
	matrix = solve_matrix(matrix, binfo);
	print_board(matrix);
	if (close(fd) < 0)
		ft_exit(ERR_FILE);
}

int		main(int argc, char *argv[])
{
	char	*filename;
	int		i;

	i = 1;
	if (argc == 1)
	{
		filename = stdin_map("42");
		if (!filename)
			ft_exit(ERR_FILE);
		solve_map(filename);
		return (0);
	}
	while (i < argc)
	{
		filename = argv[i];
		solve_map(filename);
		i++;
	}
	return (0);
}
