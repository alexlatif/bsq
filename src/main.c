
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
	char		line_buff[6];
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
	if (!check_valid_top_line(str))
		return NULL; // ERR
	board_info->lines = atoi(&str[0]);
	board_info->empty = str[1];
	board_info->obstacle = str[2];
	board_info->full = str[3];
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
	char 		buf[1];
	  
	if (ac < 2)
	{

		while (read(0, &buf, sizeof(buf)) > 0)
		{
		}

		printf("here\n");
		// sz = read(0, &c, 10); 
  		// printf("returned that"
        //  " %d bytes  were read.\n", sz); 
  		// c[sz] = '\0'; 
  		// printf("Those bytes are as follows: %s\n", c);
		// printf("NO FILE\n"); // TODO: prog_exit "Usage: ./bsq [BOARD FILE]\n"
		return (0);
	}
	// 1) find file path
	file_indx = _find_filepath(ac, av);

	// 2) get the board info
	board_info = _get_board_info(av[file_indx]);
	if (!board_info)
		return (0);
	printf("lines: %d\n", board_info->lines);
	printf("free: %c\n", board_info->empty);
	printf("obst: %c\n", board_info->obstacle);
	printf("sqr: %c\n", board_info->full);

	// 3) get board matrix
	board = get_board_matrix(av[file_indx], board_info->lines);
	printf("New Board\n");
	print_board(board);

	// 4) solve -> show board -> show solving message
	// 5) print results
	// 6) free board
	return (0);
}
