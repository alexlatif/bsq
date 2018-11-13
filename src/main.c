
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "board_methods.h"
#include "board_info.h"
#include "utils.h"

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
	// prog_exit "Usage: ./bsq [BOARD FILE]\n" 
	return (0);
}

t_board	*_get_board_info(char *file)
{
    FILE		*fp;
	char		line_buff[6];
	char		*str;
	t_board		*board_info;

	if (!(board_info = malloc(sizeof(t_board))))
		ft_exit(12, ERR_MALLOC_BOARD_INFO);
    fp = fopen(file, "r");
    if (fp == NULL)
        ft_exit(9, ERR_FILE_BOARD_INFO);
	fgets ( line_buff, sizeof line_buff, fp );
	str = &line_buff[0];
	if (!check_valid_top_line(str))
		ft_exit(1, ERR_VAL_BOARD_TL); 
	board_info->lines = ft_atoi(&str[0]);
	board_info->empty = str[1];
	board_info->obstacle = str[2];
	board_info->full = str[3];
	// FIXME: FREE!
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
		// FIXME: read from stdin
		// TODO: prog_exit "Usage: ./bsq [BOARD FILE]\n"
		printf("NO FILE\n");
		while (read(0, &buf, sizeof(buf)) > 0)
		{
		};
		return (0);
	}
	file_indx = _find_filepath(ac, av);
	board_info = _get_board_info(av[file_indx]);
	if (!board_info)
		ft_exit(1, ERR_FT_BOARD_INFO);
	
	// to remove
	printf("lines: %d\n", board_info->lines);
	printf("free: %c\n", board_info->empty);
	printf("obst: %c\n", board_info->obstacle);
	printf("sqr: %c\n", board_info->full);


	board = get_board_matrix(av[file_indx], board_info->lines);
	if (!check_valid_board(board, board_info))
		ft_exit(1, ERR_VAL_BOARD);
	printf("New Board\n");
	print_board(board);

	// 4) solve -> show board -> show solving message
	// 5) print results
	// 6) free board
	return (0);
}
