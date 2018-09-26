/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 07:53:02 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/26 10:48:22 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_shape.h"
#include <stdio.h>

t_vec3	cone_normal(t_vec3 hit_pnt, t_shape *c, t_ray r)
{
	t_vec3 ret;
	t_vec3 tmp;
	double p;

	tmp = vec3_sub_new(hit_pnt, c->pos);
	p = vec3_dot(vec3_nor_cpy(tmp), c->norm);
	p = sqrt(vec3_dot(tmp, tmp)) / p;
	ret = vec3_mul_new(c->norm, p);
	ret = vec3_nor_cpy(vec3_sub_new(tmp, ret));
	if (vec3_dot(r.dir, ret) > 0.0001)
		vec3_mul(&tmp, -1);
	return (ret);
}

double	cone_discriminant(t_shape *c, t_ray r, t_vec3 *ce)
{
	t_vec3 tmp;
	double angle;
	t_vec3 i;
	t_vec3 k;

	angle = 20 * M_PI / 180;
	tmp = vec3_sub_new(r.org, c->pos);
	i = vec3_sub_new(r.dir, vec3_mul_new(c->norm, vec3_dot(r.dir, c->norm)));
	ce->x = ft_sqr(cos(angle)) * vec3_dot(i, i) -
			ft_sqr(sin(angle)) * ft_sqr(vec3_dot(r.dir, c->norm));
	k = vec3_sub_new(tmp, vec3_mul_new(c->norm, vec3_dot(tmp, c->norm)));
	ce->z = ft_sqr(cos(angle)) * vec3_dot(k, k) -
			ft_sqr(sin(angle)) * ft_sqr(vec3_dot(tmp, c->norm));
	ce->y = 2 * (ft_sqr(cos(angle)) * vec3_dot(i, k) -
				ft_sqr(sin(angle)) *
				vec3_dot(r.dir, c->norm) * vec3_dot(tmp, c->norm));
	return (ft_sqr(ce->y) - 4 * ce->x * ce->z);
}

int		cone_inter(t_shape *c, t_inter *i)
{
	double	dis;
	t_vec3	ce;
	double	t1;
	double	t2;

	dis = cone_discriminant(c, i->ray, &ce);
	if (dis < 0)
		return (0);
	t1 = (-ce.y - sqrt(dis)) / (2 * ce.x);
	t2 = (-ce.y + sqrt(dis)) / (2 * ce.x);
	if ((t1 < i->t && t1 > RAY_T_MIN) || (t2 < i->t && t2 > RAY_T_MIN))
	{
		if (t1 < 0 || t2 < 0)
			i->t = fmax(t1, t2);
		else
			i->t = fmin(t1, t2);
		i->shape = c;
		i->normal = cone_normal(vec3_add_new(i->ray.org,
					vec3_mul_new(i->ray.dir, i->t)), c, i->ray);
		return (1);
	}
	return (0);
}

int		cone_ray(t_shape *c, t_ray r)
{
	double	dis;
	t_vec3	ce;
	double	t1;
	double	t2;

	dis = cone_discriminant(c, r, &ce);
	if (dis < 0)
		return (0);
	t1 = (-ce.y - sqrt(dis)) / (2 * ce.x);
	t2 = (-ce.y + sqrt(dis)) / (2 * ce.x);
	if ((t1 < r.max && t1 > RAY_T_MIN) || (t2 < r.max && t2 > RAY_T_MIN))
		return (1);
	return (0);
}
