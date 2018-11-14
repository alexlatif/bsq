
#include <stdlib.h>
#include "strings.h"
#include <stdio.h>

char    *ft_realloc(char *str, char c, int width)
{
    char    *temp;

    temp = malloc(sizeof(char) * (width + 1));
    temp = ft_strcpy(temp, str, width - 1);
    temp[width - 1] = c;
    temp[width] = '\0';
    return (temp);
}
