/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl_inter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 10:51:36 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/20 11:22:02 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_shape.h"
#include <stdio.h>

int cyl_inter(t_shape *s, t_inter *i)
{
	t_ray l_ray;
	t_vec3 ce;
	t_vec3 tmp;
	double dis;
	double t1;
	double t2;

	l_ray = ray_cpy(i->ray);
/*
**	Change ray location to be at origin, makes math easier
*/
	l_ray.org = matrix_vec_mult(vec3_sub_new(l_ray.org, s->pos), s->imat);
	l_ray.dir = matrix_vec_mult(l_ray.dir, s->imat);
	ce.x = ft_sqr(l_ray.dir.x) + ft_sqr(l_ray.dir.z);
	ce.y = 2 * l_ray.dir.x * l_ray.org.x + 2 * l_ray.dir.z * l_ray.org.z;
	ce.z = ft_sqr(l_ray.org.x) + ft_sqr(l_ray.org.z) - s->radius;
/*
** discriminant tells whether we intersect or not
*/
	dis = (ce.y * ce.y) - (4 * ce.x * ce.z);
	if (dis < 0)
		return (0);
	t1 = (-ce.y - sqrt(dis)) / (2 * ce.x);
	t2 = (-ce.y + sqrt(dis)) / (2 * ce.x);
	if (t1 > t2)
	{
		double tmp;
		tmp = t1;
		t1 = t2;
		t2 = tmp;
	}
	if (t1 >= RAY_T_MAX || t1 >= i->t) 
		return (0);
	tmp = vec3_add_new(l_ray.org , vec3_mul_new(l_ray.dir, t1));
	tmp = vec3_nor_cpy((t_vec3){tmp.x, 0, tmp.z});
	i->t = t1;
	i->shape = s;
	i->normal = (matrix_vec_mult(tmp, s->mat));
	return (1);
}

int cyl_ray(t_shape *s, t_ray l_ray)
{
	t_vec3 ce;
	double dis;
	double t1;
	double t2;
/*
**	Change ray location to be at origin, makes math easier
*/
	l_ray.org = matrix_vec_mult(vec3_sub_new(l_ray.org, s->pos), s->imat);
	l_ray.dir = matrix_vec_mult(l_ray.dir, s->imat);
	ce.x = ft_sqr(l_ray.dir.x) + ft_sqr(l_ray.dir.z);
	ce.y = 2 * l_ray.dir.x * l_ray.org.x + 2 * l_ray.dir.z * l_ray.org.z;
	ce.z = ft_sqr(l_ray.org.x) + ft_sqr(l_ray.org.z) - s->radius;
/*
** discriminant tells whether we intersect or not
*/
	dis = (ce.y * ce.y) - (4 * ce.x * ce.z);
	if (dis < 0)
		return (0);
	t1 = (-ce.y - sqrt(dis)) / (2 * ce.x);
	t2 = (-ce.y + sqrt(dis)) / (2 * ce.x);
	if (t1 > t2)
	{
		double tmp;
		tmp = t1;
		t1 = t2;
		t2 = tmp;
	}
	if (t1 > RAY_T_MIN && t1 < l_ray.max)
		return (1);
	return (0);
}