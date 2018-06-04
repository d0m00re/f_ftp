/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_no_dess.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 03:38:20 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/04 03:38:45 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_string.h"
#include <unistd.h>

/*
** obtenir un repertoire a partir du repertoire courant
** like cd target
*/

char		*get_rep_with_pathname(char *target)
{
	char	actual_rep[2048];
	char	*path_target;

	if (!getcwd(actual_rep, 2048))
		return (0);
	if (chdir(target))
		return (0);
	if (!(path_target = malloc(sizeof(char) * 2048)))
		return (0);
	if (!getcwd(path_target, 2048))
	{
		free(path_target);
		return (0);
	}
	chdir(actual_rep);
	return (path_target);
}

/*
** path valid non dessendant
*/

int			valid_path_no_dess(char *actual_path, char *target)
{
	int		ret;
	char	*future_path;

	if (!(future_path = get_rep_with_pathname(target)))
		return (0);
	ret = ft_strncmp(actual_path, future_path, ft_strlen(actual_path));
	free(future_path);
	return (!ret);
}

int			valid_path_no_dess_auto(char *target)
{
	char	actual_path[2048];

	if (!getcwd(actual_path, 2048))
		return (0);
	return (valid_path_no_dess(actual_path, target));
}

/*
**int main(int ac, char **argv)
**{
**        char str[2000];
**        int new;
**
**        if (ac != 2)
**                return (0);
**        //new = get_rep_with_pathname(argv[1]);
**        new = valid_path_no_dess_auto(argv[1]);
**        if (new)
**        {
**                printf("%d\n", new);
**        }
**        else
**                printf("BAD\n");
**        return (1);
** }
*/
