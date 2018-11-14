
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_fputchar(int fd, char c)
{
	write(fd, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_putnbr(int nbr)
{
	long	n;

	n = nbr;
	if (nbr < 0)
	{
		ft_putchar('-');
		n *= -1;
	}

	if (n >= 10)
		ft_putnbr(n / 10);

	ft_putchar(n % 10 + '0');
}
