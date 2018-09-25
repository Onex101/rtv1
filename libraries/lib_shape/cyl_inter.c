/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl_inter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 10:51:36 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/25 18:13:42 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_shape.h"
#include <stdio.h>

static	double	cyl_discriminant(t_vec3 *ce, t_ray r, double rad)
{
	ce->x = ft_sqr(r.dir.x) + ft_sqr(r.dir.z);
	ce->y = 2 * r.dir.x * r.org.x + 2 * r.dir.z * r.org.z;
	ce->z = ft_sqr(r.org.x) + ft_sqr(r.org.z) - rad;
	return ((ce->y * ce->y) - (4 * ce->x * ce->z));
}

int				cyl_inter(t_shape *s, t_inter *i)
{
	t_ray	l_ray;
	t_vec3	ce;
	t_vec3	tmp;
	t_vec3	v;

	l_ray = ray_cpy(i->ray);
	l_ray.org = matrix_vec_mult(vec3_sub_new(l_ray.org, s->pos), s->imat);
	l_ray.dir = matrix_vec_mult(l_ray.dir, s->imat);
	v.x = cyl_discriminant(&ce, l_ray, s->radius);
	if (v.x < 0)
		return (0);
	v.y = (-ce.y - sqrt(v.x)) / (2 * ce.x);
	v.z = (-ce.y + sqrt(v.x)) / (2 * ce.x);
	v.y = fmin(v.y, v.z);
	if (v.y >= RAY_T_MAX || v.y >= i->t)
		return (0);
	tmp = vec3_add_new(l_ray.org, vec3_mul_new(l_ray.dir, v.y));
	tmp = vec3_nor_cpy((t_vec3){tmp.x, 0, tmp.z});
	i->t = v.y;
	i->shape = s;
	i->normal = (matrix_vec_mult(tmp, s->mat));
	return (1);
}

int				cyl_ray(t_shape *s, t_ray l_ray)
{
	t_vec3	ce;
	double	dis;
	double	t1;
	double	t2;
	double	tmp;

	l_ray.org = matrix_vec_mult(vec3_sub_new(l_ray.org, s->pos), s->imat);
	l_ray.dir = matrix_vec_mult(l_ray.dir, s->imat);
	dis = cyl_discriminant(&ce, l_ray, s->radius);
	if (dis < 0)
		return (0);
	t1 = (-ce.y - sqrt(dis)) / (2 * ce.x);
	t2 = (-ce.y + sqrt(dis)) / (2 * ce.x);
	if (t1 > t2)
	{
		tmp = t1;
		t1 = t2;
		t2 = tmp;
	}
	if (t1 > RAY_T_MIN && t1 < l_ray.max)
		return (1);
	return (0);
}
