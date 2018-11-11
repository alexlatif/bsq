
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "board.h"

int		_find_filepath(int ac, char **av)
{
	int index;

	index = 1;
	while (index < ac)
	{
		if (av[index][0] != '-')
			return (index);
		index++;
	}
	// TODO: prog_exit "Usage: ./bsq [BOARD FILE]\n" 
	return (0);
}

t_board	*_get_board_info(char *file)
{
    FILE		*fp;
	char		line_buff[5];
	char		*str;
	t_board		*board_info;

	if (!(board_info = malloc(sizeof(t_board))))
		return NULL; // ERR
    fp = fopen(file, "r");
    if (fp == NULL)
        return NULL; // ERR
	fgets ( line_buff, sizeof line_buff, fp );
	str = &line_buff[0];
	// FIXME: if string is not len 4 and first in not num
	board_info->lines = atoi(&str[0]);
	board_info->free = str[1];
	board_info->obst = str[2];
	board_info->sqr = str[3];
	// FIXME: FREE SHIT!
	// free(str);
	// free(line_buff);
	fclose(fp);
	return (board_info);
}

int     main(int ac, char **av)
{
	int			file_indx;
	char		**board;
	t_board		*board_info;

	if (ac < 2)
	{
		printf("NO FILE\n"); // TODO: prog_exit "Usage: ./bsq [BOARD FILE]\n"
		return (0);
	}
	// 1) find file path
	file_indx = _find_filepath(ac, av);

	// 2) get the board info
	board_info = _get_board_info(av[file_indx]);
	printf("lines: %d\n", board_info->lines);
	printf("free: %c\n", board_info->free);
	printf("obst: %c\n", board_info->obst);
	printf("sqr: %c\n", board_info->sqr);

	// 3) get board matrix
	board = get_board_matrix(av[file_indx], board_info->lines);
	printf("New Board\n");
	print_board(board);

	// 4) solve -> show board -> show solving message
	// 5) print results
	// 6) free board
	return (0);
}
