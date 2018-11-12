
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "board_info.h"

int			check_valid_top_line(char *str)
{
	int		i;

	i = 0;
	while (str[i] >= 33 && str[i] <= 126)
		i++;
	if (i != 4)
		return (0);
	if (atoi(&str[0]) < 1)
		return (0);
	if (str[1] == str[2] || str[1] == str[3] || str[2] == str[3])
		return (0);
	return (1);
}

int			check_valid_board(char **board, t_board *board_info)
{
	unsigned int	lines;
	int				len;
	int				i;

	lines = 0;
	len = 0;
	while (board[lines])
		lines++;
	if (board_info->lines != lines)
		return (0); // ERR board lines
	while (board[0][len] != '\0')
		len++;
	while (lines--)
	{
		i = 0;
		while (board[lines][i + 1] != '\0')
        {
            if (board[lines][i] != board_info->empty &&
            board[lines][i] != board_info->obstacle)
                return (0);
            i++;
        }
		if (len != i + 1)
			return (0); // ERR board cols
	}
	return (1);
}
