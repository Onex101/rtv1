/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 06:34:26 by xrhoda            #+#    #+#             */
/*   Updated: 2018/05/28 06:34:32 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp_node;
	t_list *r_list;

	if (!lst)
		return (NULL);
	r_list = f(lst);
	if (!r_list)
		return (NULL);
	tmp_node = r_list;
	lst = lst->next;
	while (lst)
	{
		tmp_node->next = f(lst);
		tmp_node = tmp_node->next;
		lst = lst->next;
	}
	return (r_list);
}
