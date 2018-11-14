
int     ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

char    *ft_strcpy(char *dest, char *src, int length)
{
    int i;

    i = 0;
    while (i < length)
    {
        dest[i] = src[i];
        i++;
    }
    return (dest);
}
