/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_inter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 08:06:56 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/26 09:48:27 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_shape.h"
#include <stdio.h>

int		plane_inter(t_shape *plane, t_inter *i)
{
	double dot;
	double t;

	dot = vec3_dot(i->ray.dir, plane->norm);
	if (dot == 0)
		return (0);
	t = vec3_dot(vec3_sub_new(plane->pos, i->ray.org), plane->norm) / dot;
	if (t <= RAY_T_MIN || t >= i->t)
		return (0);
	i->t = t;
	i->normal = plane->norm;
	i->shape = plane;
	return (1);
}

int		plane_ray(t_shape *plane, t_ray ray)
{
	double dot;
	double t;

	dot = vec3_dot(ray.dir, plane->norm);
	if (dot == 0)
		return (0);
	t = vec3_dot(vec3_sub_new(plane->pos, ray.org), plane->norm) / dot;
	if (t <= RAY_T_MIN || t >= ray.max)
		return (0);
	return (1);
}
