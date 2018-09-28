/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 08:34:51 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/27 20:24:12 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	vector_init(t_vector *v)
{
	if (v)
	{
		v->capacity = 10;
		v->total = 0;
		v->items = ft_memalloc(sizeof(void *) * v->capacity);
	}
}
