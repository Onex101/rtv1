/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_inter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 13:12:06 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/13 08:04:03 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_shape.h"
#include <stdio.h>

int sphere_inter(t_shape *s, t_inter *i)
{
	t_ray l_ray;
	t_vec3 ce;
	double dis;
	double t1;
	double t2;

	//ft_putendl("INTER This shape is a sphere");
	l_ray = ray_cpy(i->ray);
/*
**	Change ray location to be at origin, makes math easier
*/
	vec3_sub(&l_ray.org, s->pos);
	ce.x = vec3_len_sqr(l_ray.dir);
	ce.y = 2 * vec3_dot(l_ray.dir, l_ray.org);
	ce.z = vec3_len_sqr(l_ray.org) - (s->radius * s->radius);
/*
** discriminant tells whether we intersect or not
*/
	dis = (ce.y * ce.y) - (4 * ce.x * ce.z);
	if (dis < 0)
	{
		//printf("ray.dir.x = [%f] | ray.dir.y= [%f] | ray.dir.z = [%f]\n", l_ray.dir.x, l_ray.dir.y, l_ray.dir.z);
		//printf("Ray doesn't intercept\n");
		return (0);
	}
	//printf("INTERCEPT WITH SPHERE\n");
	//printf("ray.dir.x = [%f] | ray.dir.y= [%f] | ray.dir.z = [%f]\n", l_ray.dir.x, l_ray.dir.y, l_ray.dir.z);
	t1 = (-ce.y - sqrt(dis)) / (2 * ce.x);
	t2 = (-ce.y + sqrt(dis)) / (2 * ce.x);
	if (t1 > RAY_T_MIN && t1 < i->t)
		i->t = t1;
	else if (t2 > RAY_T_MIN && t2 < i->t)
		i->t = t2;
	else
		return (0);
	//printf("i.t = [%f] t1 = [%f] t2 = [%f]\n", i.t, t1, t2);
	i->normal = vec3_nor_cpy(vec3_add_new(l_ray.org, vec3_mul_new(l_ray.dir, i->t)));
	i->shape = s;
	return (1);
}

int sphere_ray(t_shape *s, t_ray r)
{
	t_ray l_ray;
	t_vec3 ce;
	double dis;
	double t1;
	double t2;

	//ft_putendl("RAY This shape is a sphere");
	l_ray = ray_cpy(r);
	vec3_sub(&l_ray.org, s->pos);
	ce.x = vec3_len_sqr(l_ray.dir);
	ce.y = 2 * vec3_dot(l_ray.dir, l_ray.org);
	ce.z = vec3_len_sqr(l_ray.org) - (s->radius * s->radius);
	dis = (ce.y * ce.y) - (4 * ce.x * ce.z);
	if (dis < 0)
		return (0);
	t1 = (-ce.y - sqrt(dis)) / (2 * ce.x);
	t2 = (-ce.y + sqrt(dis)) / (2 * ce.x); 
	if (t1 > RAY_T_MIN && t1 < r.max)
		return (1);
	else if (t2 > RAY_T_MIN && t2 < r.max)
		return (1);
	return (0);
}