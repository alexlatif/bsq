
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "board_methods.h"
#include "board_info.h"
#include "utils.h"

char	*get_fline(int fd)
{
	int		i;
	char	c;
	char	*fline;

	if (!(fline = malloc(sizeof(char) * FLINE_MAX_SIZE)))
		ft_exit(12, ERR_MALLOC_BOARD_INFO);
	i = 0;
	while (read(fd, &c, 1) && c != '\n')
	{
		fline[i] = c;
		i++;
	}
	fline[i] = '\0';
	return (fline);
}

t_board		get_binfo(char *fline)
{
	int     size;
    t_board	binfo;

	binfo.lines = ft_atoi(fline);
    size = ft_strlen(fline);
    binfo.empty = fline[size - 3];
    binfo.obstacle = fline[size - 2];
    binfo.full = fline[size - 1];
	return (binfo);
}

int		main(int ac, char **av)
{
	t_board		binfo;
	char		**board;
	char		*fline;
	int			fd;

	if (ac == 1)
	{
		// FIXME: read from stdin
		// TODO: prog_exit "Usage: ./bsq [BOARD FILE]\n"
	}

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_exit(12, ERR_FILE);
	fline = get_fline(fd);
	if (!check_valid_top_line(fline))
		return (2, ERR_VAL_BOARD_INFO);
	binfo = get_binfo(fline);
	
	// TODO: remove
	printf("lines: %d\n", binfo.lines);
	printf("free: %c\n", binfo.empty);
	printf("obst: %c\n", binfo.obstacle);
	printf("sqr: %c\n", binfo.full);


	board = get_board_matrix(fd, binfo.lines);
	if (!check_valid_board(board, binfo))
		ft_exit(1, ERR_VAL_BOARD);
	ft_putstr("New Board\n");
	print_board(board);

	// 4) solve -> show board -> show solving message
	// 5) print results

	// 6) free board
	if (close(fd) < 0)
	{
		ft_putstr("close() failed\n");
		return (1);
	}
	return (0);
}
