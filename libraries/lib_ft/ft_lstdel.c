/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 15:08:20 by xrhoda            #+#    #+#             */
/*   Updated: 2018/05/23 15:08:24 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp_node;
	t_list	*next;

	tmp_node = *alst;
	if (del != NULL)
	{
		while (tmp_node != NULL)
		{
			next = tmp_node->next;
			del(tmp_node->content, tmp_node->content_size);
			free(tmp_node);
			tmp_node = next;
		}
		*alst = NULL;
	}
}
