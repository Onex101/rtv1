/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 08:35:02 by xrhoda            #+#    #+#             */
/*   Updated: 2018/07/17 08:35:03 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	vector_resize(t_vector *v, int capacity)
{
	void **items;

	items = (void **)malloc(sizeof(void *) * capacity);
	ft_memcpy(items, v->items, sizeof(void *) * v->capacity);
	free(v->items);
	if (items)
	{
		v->items = items;
		v->capacity = capacity;
	}
}
