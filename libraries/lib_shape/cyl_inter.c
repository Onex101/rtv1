/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl_inter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 10:51:36 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/07 12:46:29 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_shape.h"
#include <stdio.h>

int cyl_inter(t_shape *s, t_inter *i)
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
	ce.x = ft_sqr(l_ray.dir.x) + ft_sqr(l_ray.dir.y);
	ce.y = 2 * l_ray.dir.x * l_ray.org.x + 2 * l_ray.dir.y * l_ray.org.y;
	ce.z = ft_sqr(l_ray.org.x) + ft_sqr(l_ray.org.y) - 1;
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
	if (t1 > t2)
	{
		double tmp;
		tmp = t1;
		t1 = t2;
		t2 = tmp;
	}
	double y1;
	double y2;
	i->t = t1;
	y1 = l_ray.org.y + t1 * l_ray.dir.y;
	y2 = l_ray.org.y + t2 * l_ray.dir.y;

	if (y1 < -1)
	{
		if (y2 < -1)
			return (0);
		else
		{
			// hit the cap at -1
			double th = t1 + (t2 - t1) * (y1 + 1) / (y1 - y2);
			if (th <= 0) 
				return (0);
			i->t = vec3_len(vec3_mul_new(l_ray.dir, th));
			// i->t = y1;
			i->shape = s;
			return (1);
		}
	}
	else if (y1 > 1)
	{
		if (y2 > 1)
			return (0);
		else
		{
			// hit the cap at +1
			double th = t1 + (t2 - t1) * (y1 - 1) / (y1 - y2);
			if (th <= 0)
				return (0);
			i->t = vec3_len(vec3_mul_new(l_ray.dir, th));
			// i->t = y2;
			i->shape = s;
			return (1);
		}
	}
	else if (y2 >= -1 && y1 <= 1)
	{
		// hit the cylinder
		if (t1 <= 0) 
			return (0);
		i->t = t1;
		i->shape = s;
		return (1);
	}
	return (0);
}
