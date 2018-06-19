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

int	find_builtin(char *str)
{
	if (!str)
		return (ERROR_CMD);
	if (!ft_strcmp(str, "ls") || !ft_strcmp(str, "ls\n"))
		return (LS);
	else if (!ft_strcmp(str, "cd") || !ft_strcmp(str, "cd\n"))
		return (CD);
	else if (!ft_strcmp(str, "get") || !ft_strcmp(str, "get\n"))
		return (GET);
	else if (!(ft_strcmp(str, "put")) || !ft_strcmp(str, "put\n"))
		return (PUT);
	else if (!ft_strcmp(str, "pwd") || !ft_strcmp(str, "pwd\n"))
		return (PWD);
	else if (!ft_strcmp(str, "quit") || !ft_strcmp(str, "quit\n"))
		return (QUIT);
	else if (!ft_strcmp(str, "mkdir") || !ft_strcmp(str, "mkdir\n"))
		return (MKDIR);
	return (ERROR_CMD);
}
