
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

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
		return NULL; // ERR
	while (len--)
		res[len] = data[len];
	res[end] = '\0';
	return (res);
}

int			check_valid_top_line(char *str)
{
	int		i;

	i = 0;
	while (str[i] >= 33 && str[i] <= 126)
		i++;
	printf("i: %d\n", i);
	if (i != 4)
		return (0);
	if (atoi(&str[0]) < 1)
		return (0);
	if (str[1] == str[2] || str[1] == str[3] || str[2] == str[3])
		return (0);
	return (1);
}

void		print_board(char **board)
{
	int		i;

	i = 0;
	if (board[i] == 0)
		printf("EMPTY BOARD\n");
	else
	{
		while (board[i] != 0)
			printf("%s\n", board[i++]);
	}
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
