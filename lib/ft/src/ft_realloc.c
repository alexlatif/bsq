
#include <stdlib.h>
#include "strings.h"
#include <stdio.h>

char		*ft_realloc(char *o_string, char ch, int width)
{
	char		*temp;

	temp = malloc((width + 2) * sizeof(char));
	if (o_string)
		temp = ft_strcpy(temp, o_string, width);
	temp[width - 1] = ch;
	free(o_string);
	return (temp);
}
