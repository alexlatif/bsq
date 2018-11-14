
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

char    **get_board_matrix(int fd, t_board binfo)
{
    char	    	**matrix;
	char			c;
    unsigned int	i;
    unsigned int	j;
	unsigned int	width;

    width = 0;
	matrix = malloc(sizeof(char*) * (binfo.lines + 1));
    matrix[0] = NULL;
    while (read(fd, &c, 1) && c != '\n')
    {
		if (!check_valid_char(c, binfo))
			ft_exit(ERR_VAL_BOARD);
        matrix[0] = ft_realloc(matrix[0], c, ++width);
    }
    i = 1;
    while (i < binfo.lines)
    {
        j = 0;
        matrix[i] = malloc(sizeof(char) * (width + 1));
        while (read(fd, &c, 1) && c != '\n')
        {
			if (!check_valid_char(c, binfo))
				ft_exit(ERR_VAL_BOARD);
            matrix[i][j++] = c;
        }
		if (j != width)
			ft_exit(ERR_VAL_BOARD);
        matrix[i][j] = '\0';
        i++;
    }
	if (read(fd, &c, 1))
		ft_exit(ERR_VAL_BOARD);
    matrix[i] = 0;
    return (matrix);
}
