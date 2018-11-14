
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
	if (str[i] == str[i + 1] || str[i] == str[i + 2] ||
	str[i + 2] == str[i + 1])
		return (0);
	return (1);
}

int			check_valid_char(char c, t_board binfo)
{
	if (c == binfo.empty || c == binfo.full || c == binfo.obstacle)
		return (1);
	return (0);
}
