
#include <stdlib.h>
#include "puts.h"

void	ft_exit(int status, char *message)
{
	ft_putstr("ERROR: ");
	ft_putnbr(status);
	ft_putstr(", ");
	ft_putstr(message);
	exit(status);
}
