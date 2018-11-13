
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "board_info.h"
#include "utils.h"

void		print_board(char **board)
{
	int		i;

	i = 0;
	while (board[i] != 0)
	{
		ft_putstr(board[i++]);
		ft_putchar('\n');
	}
}

char		**get_board_matrix(int fd, int lines)
{
	char		**matrix;
	char		ch;
	int			i;
	int			width;
	
	i = 0;
	matrix = malloc(sizeof(char*) * (lines + 1));
	while (i < lines)
	{
		width = 0;
		matrix[i] = 0;
		while (read(fd, &ch, 1) > 0)
		{
			if (ch != '\n')
				width++;
			if (ch == '\n')
				break ;
			matrix[i] = ft_realloc(matrix[i], ch, width);
		}
		i++;
	}
	matrix[i] = 0;
	return (matrix);
}
