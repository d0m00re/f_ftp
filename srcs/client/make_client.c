/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 04:58:01 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/05 04:58:10 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "client.h"
#include "ft_string.h"

t_client		*make_client(void)
{
	t_client	*client;

	if (!(client = malloc(sizeof(t_client))))
		return (0);
	ft_bzero(client, sizeof(t_client));
	client->running = 1;
	return (client);
}
