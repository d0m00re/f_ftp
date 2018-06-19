/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 06:58:40 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/03 06:58:58 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	g_sigint = 0;

int			get_sigint(void)
{
	return (g_sigint);
}

void		true_sigint(void)
{
	g_sigint = 1;
}

void		false_sigint(void)
{
	g_sigint = 0;
}
