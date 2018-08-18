/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 06:26:00 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/18 13:14:07 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_vec.h"

t_vec2	vec2_new(double x, double y)
{
	t_vec2 v;

	vec2_init(&v, x, y);
	return (v);
}

void	vec2_init(t_vec2 *v, double x, double y)
{
	v->x = x;
	v->y = y;
}

t_vec2	vec2_cpy(t_vec2 v)
{
	t_vec2 cpy;

	cpy = vec2_new(v.x, v.y);
	return (cpy);
}
