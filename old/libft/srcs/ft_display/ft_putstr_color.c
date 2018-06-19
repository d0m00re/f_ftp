/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 06:23:14 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/06 06:23:19 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "ft_display.h"

void	ft_putstr_gen(char *str, char *color)
{
	ft_putstr(color);
	ft_putstr(str);
	ft_putstr(ANSI_COLOR_RESET);
}

void	ft_putstr_green(char *str)
{
	ft_putstr(ANSI_COLOR_GREEN);
	ft_putstr(str);
	ft_putstr(ANSI_COLOR_RESET);
}

void	ft_putstr_red(char *str)
{
	ft_putstr(ANSI_COLOR_RED);
	ft_putstr(str);
	ft_putstr(ANSI_COLOR_RESET);
}

void	ft_color_reset(void)
{
	ft_putstr(ANSI_COLOR_RESET);
}
