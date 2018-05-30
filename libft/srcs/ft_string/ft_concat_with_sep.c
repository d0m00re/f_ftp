#include <stdlib.h>
#include "ft_string.h"

char *ft_concat_with_sep(char *s1, char *s2, char *sep)
{
	char *tmp;
	size_t total_size;

	total_size = ft_strlen(s1) + ft_strlen(s2) + 2;
	tmp = malloc(sizeof(char) * total_size);
	ft_strcpy(tmp, s1);
	ft_strcat(tmp, sep);
	ft_strcat(tmp, s2);
	return (tmp);
}
