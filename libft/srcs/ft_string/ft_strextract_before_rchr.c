#include "ft_string.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *ft_strextract_before_rchr(char *str, char sep)
{
	size_t len;
	char *new;
	char *ref_end;
	size_t counter;

	counter = 0;
	if (!(ref_end = ft_strrchr(str, sep)))
		return (0);
	len = (size_t)(ref_end - str);	
	printf("zu : %zu\n", len);
	new = malloc(sizeof(char) * (len + 1));
	while (counter < len)
	{
		new[counter] = str[counter];
		counter++;
	}
	new[counter] = 0;
	return (new);
}
/*
int main()
{
	char *str = "str/salope/pd";
	char *ret;

	ret = ft_strextract_before_rch(str, '/');
	printf("ret : %s\n", ret);
	return (1);
}
*/
