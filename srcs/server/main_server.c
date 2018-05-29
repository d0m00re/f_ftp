#include "ft_string.h"
#include "ft_display.h"
#include "server.h"

char    *main_server(char *buf, int size)
{
	int nb_word;
        char *str;
        char **strsp;
        int num_builtins;

        strsp = ft_strsplit_nb_word(buf, ' ', &nb_word);
        num_builtins = find_builtin(strsp[0]);
        if (num_builtins)
	{
                ft_putstr("Good we have a builtin :)\n");
		if (num_builtins == PUT && nb_word >= 3)
			ft_put(strsp[1], buf + ft_strlen(strsp[0]) + ft_strlen(strsp[1]) + 2);
	}
        else
                ft_putstr("Builtins not reconize :\n");
        return (ft_strdup("Yo John Doe\n"));
}
