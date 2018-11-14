
#ifndef BOARD_INFO_H
# define BOARD_INFO_H

typedef struct		s_board
{
	unsigned int	lines;
	char			empty;
	char			obstacle;
	char			full;
}					t_board;

int			check_valid_char(char c, t_board binfo);
t_board		get_binfo(char *fline);

#endif
