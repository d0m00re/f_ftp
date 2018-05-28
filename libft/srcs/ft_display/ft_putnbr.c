/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 23:00:46 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/17 23:01:31 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display.h"

void				ft_putnbr(int nb)
{
	unsigned int	nbb;

	nbb = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		nbb *= -1;
	}
	if (nbb > 9)
	{
		ft_putnbr(nbb / 10);
		ft_putnbr(nbb % 10);
	}
	else
	{
		ft_putchar(nbb + '0');
		nbb = 0;
	}
}

void				ft_putnbr_ui(unsigned int nb)
{
	if (nb > 9)
	{
		ft_putnbr_ui(nb / 10);
		ft_putnbr_ui(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
		nb = 0;
	}
}

void				ft_putnbr_base(int nb, unsigned int base)
{
	unsigned int	nbb;

	nbb = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		nbb *= -1;
	}
	if (nbb > base - 1)
	{
		ft_putnbr_base(nbb / base, base);
		ft_putnbr_base(nbb % base, base);
	}
	else
	{
		if (nbb < 10)
			ft_putchar(nbb + '0');
		else
			ft_putchar(nbb - 10 + 'A');
		nbb = 0;
	}
}

void				ft_putnbr_base_ui(unsigned int nb, unsigned int base)
{
	if (nb > base - 1)
	{
		ft_putnbr_base_ui(nb / base, base);
		ft_putnbr_base_ui(nb % base, base);
	}
	else
	{
		if (nb < 10)
			ft_putchar(nb + '0');
		else
			ft_putchar(nb - 10 + 'A');
		nb = 0;
	}
}
