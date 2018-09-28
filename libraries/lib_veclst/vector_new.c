/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 12:15:44 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/27 20:31:00 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	*vector_new(void)
{
	t_vector *v;

	if (!(v = (t_vector *)malloc(sizeof(t_vector))))
		return (NULL);
	v->capacity = 10;
	v->total = 0;
	v->items = ft_memalloc(sizeof(void *) * v->capacity);
	return (v);
}
