
#ifndef BOARD_INFO_H
# define BOARD_INFO_H

# define ERR_MAP ("No valid map in file \"%s\"\n")
# define ERR_MALLOC ("Out of memory! malloc() failed...\n")

typedef struct		s_board
{
	unsigned int	lines;
	char			empty;
	char			obstacle;
	char			full;
}					t_board;

#endif
