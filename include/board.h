
#ifndef BOARD_H
# define BOARD_H

typedef struct		s_board
{
	unsigned int	lines;
	char			empty;
	char			obstacle;
	char			full;
}					t_board;

char		**get_board_matrix(char *file, int lines);
void		print_board(char **board);
int			check_valid_top_line(char *str);

#endif