#include "ft_string.h"

/*
** [tab] [sep] [tab] [sep]
*/

char *concat_2dchar_in_buffer(char *buffer, char **tab_string, int size_tab_string, char *sep)
{
	int c;

	c = 1;
	ft_strcpy(buffer, tab_string[0]);
	ft_strcat(buffer, sep);
	while (c < size_tab_string)
	{
		ft_strcat(buffer, tab_string[c]);
		ft_strcat(buffer, " ");
		c++;
	}
	return (buffer);
}
