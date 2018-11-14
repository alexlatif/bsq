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

#define BUFF_SIZE 1024

char	*get_buff(int fd)
{
	char	*buff;
	int		bytes;
	int		i;

	if (!(buff = malloc(1024)))
		return (NULL);
	i = 0;
	while ((bytes = read(fd, &(buff[i]), 1)) > 0)
		i++;
	buff[i] = '\0';
	return (buff);
}

char	*get_header(char *buff)
{
	char	*head;
	int		i;

	i = 0;
	if (!(head = malloc(15)))
		return (NULL);
	while (buff[i] != '\n' && buff[i])
	{
		head[i] = buff[i];
		i++;
	}
	head[i] = '\0';
	if (!check_valid_top_line(head))
		ft_exit(ERR_VAL_BOARD);
	return (head);
}

void	solve_map(char *buff)
{
	char		*header;
	char		**matrix;
	t_board		binfo;

	header = get_header(buff);
	binfo = get_binfo(header);
	matrix = get_matrix(buff, binfo);
	matrix = solve_matrix(matrix, binfo);
	print_board(matrix);
}

int		main(int argc, char *argv[])
{
	char	*buff;
	int		fd;
	int		i;

	i = 1;
	if (argc == 1)
	{
		buff = get_buff(0);
		solve_map(buff);
		return (0);
	}
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
			ft_exit(ERR_FILE);
		buff = get_buff(fd);
		solve_map(buff);
		if (close(fd) < 0)
			ft_exit(ERR_FILE);
		i++;
	}
	return (0);
}
