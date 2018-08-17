/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 06:26:00 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/17 12:14:27 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_lib.h"

t_vec2	*vec2_new(double x, double y)
{
	t_vec2 *v;

	v = (t_vec2 *)malloc(sizeof(t_vec2));
	if (!v)
		return (NULL);
	vec2_init(v, x, y);
	return (v);
}

void	vec2_init(t_vec2 *v, double x, double y)
{
	if (v)
	{
		v->x = x;
		v->y = y;
	}
}

t_vec2	*vec2_cpy(t_vec2 *v)
{
	t_vec2 *cpy;

	if (v)
	{
		cpy = vec2_new(v->x, v->y);
		return (cpy);
	}
	return (NULL);
}

void	vec2_del(t_vec2 *v)
{
	if (v)
		free(v);
}
