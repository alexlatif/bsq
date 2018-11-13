
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
	char **matrix;
	int i;
	int j;
	char c;
	int elem;
	
	i = 0;
	elem = 0;
	matrix = malloc(sizeof(char*) * (lines + 1));
	while (i < lines)
	{
		j = 0;
		if (elem == 0)
		{
			matrix[i] = malloc(sizeof(char) * (20));
			while (read(fd, &c, 1) && c != '\n')
			{
				matrix[i][j] = c;
				j++;
				elem++;
			}
			matrix[i][j] = '\0';
		}
		else
		{
			matrix[i] = malloc(sizeof(char) * (elem + 1));
			while (read(fd, &c, 1) && c != '\n')
			{
				matrix[i][j] = c;
				j++;
			}
			matrix[i][j] = '\0';
		}
		i++;
	}
	matrix[i] = 0;
	return (matrix);
}
