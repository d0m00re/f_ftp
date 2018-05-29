#include "ft_display.h"

int ft_put(char *name, char *data)
{
	int c;

	c = 0;
	ft_putstr(name);
	ft_putchar(':');
	ft_putstr(data);
	ft_putchar(':');
	return (1);
}
