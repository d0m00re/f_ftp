/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcreate_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 23:06:07 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/17 23:06:16 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"

t_linked_list		*ft_lstcreate_elem(void *data)
{
	t_linked_list	*elem;

	elem = malloc(sizeof(t_linked_list));
	if (!elem)
		return (0);
	elem->next = NULL;
	elem->content = data;
	return (elem);
}
