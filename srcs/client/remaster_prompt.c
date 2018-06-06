/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remaster_prompt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 05:12:32 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/06 06:34:48 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display.h"
#include "ft_string.h"
#include <stdio.h>

static void		message_5xx(char *str)
{
	if (!ft_strncmp(str, "500", 3))
		ft_putstr_red(" invalid repertories");
	else if (!ft_strncmp(str, "511", 3) ||\
	!ft_strncmp(str, "522", 3))
		ft_putstr_red(" invalid path");
	else if (!ft_strncmp(str, "523", 3))
		ft_putstr_red(" file not found on the server");
	else if (!ft_strncmp(str, "524", 3) ||\
		!ft_strncmp(str, "533", 3))
		ft_putstr_red(" this is not a file");
	else
		ft_putstr_red(" unknown error");
}

int				remaster_prompt(char *str, int size)
{
	if (strncmp(str, "20", 2) == 0)
		ft_putstr_green("SUCCESS : ");
	else
		ft_putstr_red("ERROR : ");
	if (size < 3)
		ft_putstr_red("Error nb argument.\n");
	else if (str[0] == '5')
		message_5xx(str);
	else if (str[0] == '2')
		ft_putstr_green(&(str[4]));
	else
		ft_putstr_red(&(str[4]));
	ft_putstr("\n\n");
	return (0);
}
