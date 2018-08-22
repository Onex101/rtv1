/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_inter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 08:06:56 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/22 13:14:01 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_shape.h"

int		plane_inter(t_shape plane, t_inter i)
{
	double dot;
	double t;

	dot  = vec3_dot(i.ray.dir, plane.norm);
	if (dot == 0)
		return (0);
	else
		t = vec3_dot(vec3_sub_new(plane.pos, i.ray.org), plane.norm) / dot;
	if (t <= RAY_T_MIN || t >= i.t)
		return (0);
	i.t = t;
	i.shape = plane;
	return (1);
}

int		plane_ray(t_shape plane, t_ray ray)
{
	double dot;
	double t;
	
	dot = vec3_dot(ray.dir, plane.norm);
	if (dot == 0)
		return (0);
	t  = vec3_dot(vec3_sub_new(plane.pos, ray.org), plane.norm) / dot;
	if (t < RAY_T_MIN || t >= ray.max)
		return (0);
	return (1);
}