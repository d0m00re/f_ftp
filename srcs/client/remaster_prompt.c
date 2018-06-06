/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remaster_prompt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 05:12:32 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/05 05:14:47 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display.h"
#include "ft_string.h"
#include <stdio.h>

int		remaster_prompt(char *str, int size)
{
	if (size < 3)
		return (ft_putstr_ret("Error nb argument\n", 1));
	if (strncmp(str, "20", 2) == 0)
		ft_putstr("SUCCESS : ");
	else
		ft_putstr("ERROR : ");
	if (str[0] == '5')
	{
		if (!ft_strncmp(str, "500", 3))
			ft_putstr(" invalid repertories");
		else if (!ft_strncmp(str, "511", 3) ||\
		!ft_strncmp(str, "522", 3))
			ft_putstr(" invalid path");
		else if (!ft_strncmp(str, "523", 3))
			ft_putstr(" file not found on the server");
		else if (!ft_strncmp(str, "524", 3) ||\
		!ft_strncmp(str, "533", 3))
			ft_putstr(" this is not a file");
		else
			ft_putstr(" unknown error");
	}
	else
		ft_putstr(&(str[4]));
	ft_putstr("\n\n");
	return (0);
}
