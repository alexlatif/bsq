
#ifndef UTILS_H
# define UTILS_H

# define ERR_MALLOC_BOARD_INFO "allocating memory to board info in main.c\n"

# define ERR_MALLOC_BOARD_ROW "error in allocating array row memory get_board_matrix.c\n"
# define ERR_MALLOC_BOARD "allocating memory to board in get_board_matrix.c\n"

# define ERR_FILE "file delimiter error in main\n"
# define ERR_VAL_BOARD "invalid board in main.c\n"
# define ERR_VAL_BOARD_INFO "invalid board info in check_valid_top_line.c\n"
# define FLINE_MAX_SIZE 15

char	*ft_strcpy(char *dest, char *src, int length);
char	*ft_realloc(char *o_string, char ch, int width);
void	ft_exit(int status, char *message);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_atoi(char *str);
int    	ft_strlen(char *str);

#endif
