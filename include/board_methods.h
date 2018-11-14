
#ifndef BOARD_METHODS_H
# define BOARD_METHODS_H
#include "board_info.h"

char		**get_board_matrix(int fd, t_board binfo);
void		print_board(char **board);
int			check_valid_top_line(char *str);
char	    **solve_matrix(char **matrix, t_board binfo);

#endif
