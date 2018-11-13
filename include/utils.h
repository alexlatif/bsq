
#ifndef UTILS_H
# define UTILS_H

# define ERR_MALLOC_BOARD_INFO "allocating memory to board info in main.c\n"
# define ERR_MALLOC_BOARD_ROW "error in allocating array row memory get_board_matrix.c\n"
# define ERR_MALLOC_BOARD "allocating memory to board in get_board_matrix.c\n"
# define ERR_FILE_BOARD_INFO "no file delimiter in getting board info in main.c\n"
# define ERR_FILE_BOARD "no file delimiter in creating board in get_board_matrix.c\n"
# define ERR_FT_BOARD_INFO "error in get_board_info in main.c\n"
# define ERR_VAL_BOARD "invalid board in main.c\n"
# define ERR_VAL_BOARD_TL "invalid board info in check_valid_top_line.c\n"


void	ft_exit(int status, char *message);

#endif
