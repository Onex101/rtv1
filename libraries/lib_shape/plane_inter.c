/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_inter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 08:06:56 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/13 06:25:44 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_shape.h"
#include <stdio.h>

int		plane_inter(t_shape *plane, t_inter *i)
{
	double dot;
	double t;

	//ft_putendl("INTER This shape is a plane");
	dot  = vec3_dot(i->ray.dir, plane->norm);
	if (dot == 0)
		return (0);
	//printf("i->ray.org.x = [%f], i->ray.org.y = [%f], i->ray.org.z = [%f]\n", i->ray.org.x, i->ray.org.y, i->ray.org.z);
	t = vec3_dot(vec3_sub_new(plane->pos, i->ray.org), plane->norm) / dot;
	//printf("t = [%f]\n", t);
	if (t <= RAY_T_MIN || t >= i->t)
		return (0);
	//ft_putendl("INtercept plane");
	i->t = t;
	i->normal = plane->norm;
	i->shape = plane;
	return (1);
}

int		plane_ray(t_shape *plane, t_ray ray)
{
	double dot;
	double t;

	//ft_putendl("RAY This shape is a plane");
	dot = vec3_dot(ray.dir, plane->norm);
	if (dot == 0)
		return (0);
	t = vec3_dot(vec3_sub_new(plane->pos, ray.org), plane->norm) / dot;
	if (t <= RAY_T_MIN || t >= ray.max)
		return (0);
	return (1);
}