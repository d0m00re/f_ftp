#include "ft_string.h"
#include "ft_display.h"
#include "server.h"

/*
int                                             server_bitch(char buffer[1024], int r)
{
        char **split_arg;
        int nb_arg;
        int ret_type_cmd;

        split_arg = 0;
        buffer[r] = '\0';
        split_arg = ft_strsplit_nb_word(buffer, ' ', &nb_arg); //free le split
        ret_type_cmd = find_builtin(split_arg[0]);
        return (ret_type_cmd);
}
*/

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
