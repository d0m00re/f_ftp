/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_ret.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 21:23:03 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/05 22:50:52 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display.h"

int	ft_putstr_ret(char const *str, int ret)
{
	if (!str)
		return (1);
	ft_putstr(str);
	return (ret);
}
