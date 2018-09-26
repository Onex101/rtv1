/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 08:34:01 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/26 10:49:02 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	vector_add(t_vector *v, void *item)
{
	if (v->capacity == v->total)
		vector_resize(v, v->capacity * 2);
	v->items[(int)(v->total)++] = item;
}
