/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdisplay.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 23:06:40 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/17 23:06:55 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"

void				ft_lstdisplay(t_linked_list *begin_list,\
				void (*read_node_content)(void *))
{
	t_linked_list	*list;

	if (!begin_list)
		return ;
	list = begin_list;
	while (list)
	{
		read_node_content(list->content);
		list = list->next;
	}
}
