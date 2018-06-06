/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 05:51:16 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/05 05:51:21 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "ft_string.h"
#include "ft_display.h"
#include <stdlib.h>
#include <stdio.h>

int	find_builtin(char *str)
{
	if (!str)
		return (ERROR_CMD);
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
