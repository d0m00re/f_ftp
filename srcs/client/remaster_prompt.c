#include "ft_display.h"
#include "ft_string.h"
#include <stdio.h>

void	remaster_prompt(char *str, int size)
{
	if (size < 3)
	{
		ft_putstr("BIG ERROR\n");
		return ;
	}
	if (strncmp(str, "20", 2) == 0)
		ft_putstr("SUCCESS : ");
	else
		ft_putstr("FAIL : ");
	ft_putstr(&(str[4]));
	ft_putstr("\n\n");
}
