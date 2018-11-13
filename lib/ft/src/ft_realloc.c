
#include <stdlib.h>
#include "strings.h"

char		*ft_realloc(char *o_string, char ch, int width)
{
	char		*temp;

	temp = malloc((width + 1) * sizeof(char));
	temp = ft_strcpy(temp, o_string, width - 1);
	temp[width - 1] = ch;
	free(o_string);
	return (temp);
}
