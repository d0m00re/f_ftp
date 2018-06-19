/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 23:07:01 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/17 23:07:11 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"

void				ft_lstpush_front(t_linked_list **begin_list, void *data)
{
	t_linked_list	*list;

	list = *begin_list;
	if (!list)
		*begin_list = ft_lstcreate_elem(data);
	else
	{
		*begin_list = ft_lstcreate_elem(data);
		(*begin_list)->next = list;
	}
}
