/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 08:35:02 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/27 10:29:33 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	vector_resize(t_vector *v, int capacity)
{
	void **items;

	if(!(items = (void **)malloc(sizeof(void *) * capacity)))
		return ;
	ft_memcpy(items, v->items, sizeof(void *) * v->capacity);
	free((v->items));
	if (items)
	{
		v->items = items;
		v->capacity = capacity;
	}
}
