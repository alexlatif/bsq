
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "board_info.h"
#include "utils.h"

int			check_valid_top_line(char *str)
{
	int		i;
	int		end;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (ft_atoi(str) < 0)
		return (0);
	end = i;
	while (str[end] != '\0')
		end++;
	if ((end - i) != 3)
		return (0);
	if (str[end - 3] == str[end - 2] || str[end - 3] == str[end - 1] ||
	str[end - 2] == str[end - 1])
		return (0);
	return (1);
}

int			get_board_lines(char **board)
{
	int		lines;

	lines = 0;
	while (board[lines])
		lines++;
	return (lines);
}

int			check_valid_board(char **board, t_board board_info)
{
	unsigned int	lines;
	int				len;
	int				i;

	len = 0;
	lines = get_board_lines(board);
	if (board_info.lines != lines)
		return (0);
	while (board[0][len] != '\0')
		len++;
	while (lines--)
	{
		i = 0;
		while (board[lines][i + 1] != '\0')
		{
			if (board[lines][i] != board_info.empty &&
			board[lines][i] != board_info.obstacle)
				return (0);
			i++;
		}
		if (len != i + 1)
			return (0);
	}
	return (1);
}
