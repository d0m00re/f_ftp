/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 23:08:13 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/17 23:08:23 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"

void				ft_lstpush_back(t_linked_list **begin_list, void *data)
{
	t_linked_list	*list;

	list = *begin_list;
	while (list && list->next)
		list = list->next;
	if (!list)
		*begin_list = ft_lstcreate_elem(data);
	else
		list->next = ft_lstcreate_elem(data);
}
