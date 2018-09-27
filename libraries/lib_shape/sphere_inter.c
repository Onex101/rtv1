/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_inter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 13:12:06 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/25 17:59:35 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_shape.h"
#include <stdio.h>

static	double	sphere_disriminant(t_vec3 *ce, t_ray r, double rad)
{
	ce->x = vec3_len_sqr(r.dir);
	ce->y = 2 * vec3_dot(r.dir, r.org);
	ce->z = vec3_len_sqr(r.org) - (rad * rad);
	return ((ce->y * ce->y) - (4 * ce->x * ce->z));
}

int				sphere_inter(t_shape *s, t_inter *i)
{
	t_ray	l_ray;
	t_vec3	ce;
	double	dis;
	double	t1;
	double	t2;

	l_ray = ray_cpy(i->ray);
	vec3_sub(&l_ray.org, s->pos);
	dis = sphere_disriminant(&ce, l_ray, s->radius);
	if (dis < 0)
		return (0);
	t1 = (-ce.y - sqrt(dis)) / (2 * ce.x);
	t2 = (-ce.y + sqrt(dis)) / (2 * ce.x);
	if (t1 > RAY_T_MIN && t1 < i->t)
		i->t = t1;
	else if (t2 > RAY_T_MIN && t2 < i->t)
		i->t = t2;
	else
		return (0);
	i->normal = vec3_nor_cpy(
				vec3_add_new(l_ray.org,
				vec3_mul_new(l_ray.dir, i->t)));
	i->shape = s;
	return (1);
}

int				sphere_ray(t_shape *s, t_ray r)
{
	t_ray	l_ray;
	t_vec3	ce;
	double	dis;
	double	t1;
	double	t2;

	l_ray = ray_cpy(r);
	vec3_sub(&l_ray.org, s->pos);
	dis = sphere_disriminant(&ce, l_ray, s->radius);
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
