
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "board_info.h"

char		*_create_arr_line(char *data)
{
	char	*res;
	int		len;
	int		end;

	len = 0;
	while (data[len] != '\0')
		len++;
	len = (len + 1);
	end = len;
	if (!(res = malloc(sizeof(char) * end)))
		return NULL; // ERR in allocating line memory
	while (len--)
		res[len] = data[len];
	res[end] = '\0';
	return (res);
}

void		print_board(char **board)
{
	int		i;

	i = 0;
	while (board[i] != 0)
		printf("%s\n", board[i++]);
}

char		**get_board_matrix(char *file, int lines)
{
	FILE	*fp;
	char	**board;
	char	line_buff[1048];
	int		i;
	int		skip;

	if (! (board = malloc(sizeof(char*) * lines)))
		return NULL; // ERR
	fp = fopen(file, "r");
	if (fp == NULL)
		return NULL; // ERR
	i = 0;
	skip = 0;
	while ( fgets ( line_buff, sizeof line_buff, fp ) != NULL )
	{
		if (skip != 0)
			board [i++] = _create_arr_line(line_buff);
		skip = 1;
	}
	board[i] = 0;
	return (board);
}
