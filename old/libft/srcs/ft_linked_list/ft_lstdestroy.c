/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdestroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 23:06:19 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/17 23:06:35 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"

void				ft_lstdestroy(t_linked_list **list,\
		void (*del_node_content)(void *))
{
	t_linked_list	*tmp;
	t_linked_list	*tmp2;

	if (!list || !(*list))
		return ;
	tmp = *list;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		del_node_content(tmp);
		free(tmp2);
	}
	*list = 0;
}
