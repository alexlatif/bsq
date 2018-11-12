
#include <stdio.h>
#include <stdlib.h>

void	ft_exit(int status, char *message)
{
	printf("ERROR: %d, %s", status, message);
	exit(status);
}
