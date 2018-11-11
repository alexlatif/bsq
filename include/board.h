
#ifndef BOARD_H
# define BOARD_H

typedef struct		s_board
{
	unsigned int	lines;
	char			free;
	char			obst;
	char			sqr;
}					t_board;

char		**get_board_matrix(char *file, int lines);
void		print_board(char **board);

#endif