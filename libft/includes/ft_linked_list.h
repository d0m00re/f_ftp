/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linked_list.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 16:01:49 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/18 16:05:44 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LINKED_LIST_H
# define FT_LINKED_LIST_H

# include "ft_stdlib.h"

typedef struct				s_linked_list
{
	void					*content;
	size_t					content_size;
	struct s_linked_list	*next;
}							t_linked_list;

t_linked_list				*ft_lstcreate_elem(void *data);

void						ft_lstpush_back(t_linked_list **begin_list,\
		void *data);

void						ft_lstpush_front(t_linked_list **begin_list,\
		void *data);

void						ft_lstdestroy(t_linked_list **begin_list,\
		void (*del_node_content)(void *));

void						ft_lstdisplay(t_linked_list *begin_list,\
		void (*read_node_content)(void *));

#endif
