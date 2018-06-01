#include "server.h"
#include "ft_string.h"
#include "ft_display.h"
#include <stdlib.h>
#include <stdio.h>

int find_builtin(char *str)
{
	printf("->%s|\n", str);
	if (!ft_strcmp(str, "ls"))
		return (LS);
	else if (!ft_strcmp(str, "cd"))
		return (CD);
	else if (!ft_strcmp(str, "get"))
		return (GET);
	else if (!(ft_strcmp(str, "put")))
		return (PUT);
	else if (!ft_strcmp(str, "pwd"))
		return (PWD);
	else if (!ft_strcmp(str, "quit"))
		return (QUIT);
	else if (!ft_strcmp(str, "mkdir"))
		return (MKDIR);
	return (ERROR_CMD);
}
