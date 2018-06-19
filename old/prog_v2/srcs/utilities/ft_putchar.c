#include "utilities.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putchar_fd(char c, int fd)
{
	write(2, &c, 1);
}
