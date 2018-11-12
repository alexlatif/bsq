
#ifndef BOARD_METHODS_H
# define BOARD_METHODS_H
#include "board_info.h"

char		**get_board_matrix(char *file, int lines);
void		print_board(char **board);
int			check_valid_top_line(char *str);
int			check_valid_board(char **board, t_board *board_info);

#endif
