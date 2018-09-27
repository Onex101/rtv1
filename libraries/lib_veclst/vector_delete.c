/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 08:34:13 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/26 10:48:57 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	vector_delete(t_vector *v, int index)
{
	int i;

	if (index < 0 || index >= v->total)
		return ;
	v->items[index] = NULL;
	i = index;
	while (i < v->total - 1)
	{
		v->items[i] = v->items[i + 1];
		v->items[i + 1] = NULL;
		i++;
	}
	v->total--;
	if (v->total > 0 && v->total == v->capacity / 4)
		vector_resize(v, v->capacity / 2);
}
