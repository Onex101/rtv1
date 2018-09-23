/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeno <xeno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 07:53:02 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/23 13:19:22 by xeno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_shape.h"

t_vec3	cone_normal(t_vec3 hit_pnt, t_shape *c)
{
	t_vec3 ret;

	ret = vec3_sub_new(hit_pnt, c->pos);
	ret = vec3_sub_new(ret, vec3_mul_new(c->norm, (vec3_len(ret) / cos(atan(c->radius / c->height)))));
	vec3_nor(&ret);
	return (ret);
}

// t_vec3	cone_normal(t_shape *c, t_inter *i, t_vec3 hit_pnt)
// {
// 	t_vec3 n;
// 	// t_vec3 proj;
// 	double k;

// 	k = vec3_dot(i->ray.dir, c->norm) * i->t + vec3_dot(vec3_sub_new(i->ray.org, c->pos), c->norm);
// 	n = vec3_mul_new(vec3_mul_new(c->norm, k), (1 + ft_sqr(c->radius)));
// 	n = vec3_nor_cpy(vec3_sub_new(vec3_sub_new(hit_pnt, c->pos), n));
// 	if (vec3_dot(i->ray.dir, n) > 0.0001)
// 		n = vec3_mul_new(n, -1);
// 	return (n);
// 	// t_vec3		normal;
// 	// t_vec3		tmp;
// 	// t_vec3		project;
// 	// float		dot;

// 	// tmp = vec_sub3(poi, cone.pos);
// 	// dot = vec_dot3(tmp, cone.vector);
// 	// project = vec_scale3(cone.vector, dot);
// 	// normal = vec_sub3(tmp, project);
// 	// if (cone.mat.sin == 1)
// 	// {
// 	// 	normal.x = normal.x;
// 	// 	normal.y = sin(normal.y) * 20;
// 	// 	normal.z = normal.z;
// 	// }
// 	// return (vec_norme3(normal));
// }

int		cone_inter(t_shape *c, t_inter *i)
{
	t_ray l_ray;
	t_vec3 ce;
	t_vec3 tmp;
	double dis;
	double t1;
	double t2;

	//ft_putendl("INTER This shape is a sphere");
	l_ray = ray_cpy(i->ray);
/*
**	Change ray location to be at origin, makes math easier
*/
	l_ray.org = matrix_vec_mult(vec3_sub_new(l_ray.org, c->pos), c->imat);
	l_ray.dir = matrix_vec_mult(l_ray.dir, c->imat);
	ce.x = ft_sqr(l_ray.dir.x) + ft_sqr(l_ray.dir.z) - ft_sqr(l_ray.dir.y * c->radius);
	ce.y = 2 * (l_ray.org.x * l_ray.dir.x + l_ray.org.z * l_ray.dir.z - l_ray.org.y * l_ray.dir.y * ft_sqr(c->radius));
	ce.z = ft_sqr(l_ray.org.x) + ft_sqr(l_ray.org.z) - ft_sqr(l_ray.org.y * c->radius);;

	// tmp = vec3_sub_new(i->ray.org, c->pos);
	// ce.x = vec3_dot(i->ray.dir, c->norm);
	// ce.x = vec3_dot(i->ray.dir, i->ray.dir) - (1 + ft_sqr(c->radius) * ft_sqr(ce.x));
	// ce.y = 2 * (vec3_dot(i->ray.dir, tmp) - (1 + ft_sqr(c->radius)) * vec3_dot(i->ray.dir, c->norm) * vec3_dot(tmp, c->norm));
	// ce.z = vec3_dot(tmp, c->norm);
	// ce.z = vec3_dot(tmp, tmp) - (1 + ft_sqr(c->radius) * ft_sqr(ce.z));

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
	// if (t1  c->height || t2 <= c->height)
	// {
	if (t1 > RAY_T_MIN && t1 < i->t)
		i->t = t1;
	else if (t2 > RAY_T_MIN && t2 < i->t)
		i->t = t2;
	else
		return (0);
	// }
	// else
	// 	return (0);
	//printf("i.t = [%f] t1 = [%f] t2 = [%f]\n", i.t, t1, t2);
	i->shape = c;
	tmp = vec3_add_new(l_ray.org , vec3_mul_new(l_ray.dir, i->t));
	tmp = vec3_nor_cpy(tmp);
	int num;
	if (tmp.y <= 0)
		num = c->radius;
	else
		num = -c->radius;
	i->normal = vec3_nor_cpy((t_vec3){tmp.x, 0 , tmp.z});
	i->normal = vec3_nor_cpy((t_vec3){tmp.x / num, 0, tmp.z / num});
	// i->normal = (matrix_vec_mult((i->normal), c->mat));
	// // ft_putstr("Cylinder Normal calc: ");
	// // vec3_prnt(i->normal);
	// i->normal = cone_normal(c, i, tmp);
	return (1);
}

int		cone_ray(t_shape *c, t_ray l_ray)
{
	t_vec3 ce;
	// t_vec3 tmp;
	double dis;
	double t1;
	double t2;

/*
**	Change ray location to be at origin, makes math easier
*/
	l_ray.org = matrix_vec_mult(vec3_sub_new(l_ray.org, c->pos), c->imat);
	l_ray.dir = matrix_vec_mult(l_ray.dir, c->imat);
	ce.x = ft_sqr(l_ray.dir.x) + ft_sqr(l_ray.dir.z) - ft_sqr(l_ray.dir.y * c->radius);
	ce.y = 2 * (l_ray.org.x * l_ray.dir.x + l_ray.org.z * l_ray.dir.z - l_ray.org.y * l_ray.dir.y * ft_sqr(c->radius));
	ce.z = ft_sqr(l_ray.org.x) + ft_sqr(l_ray.org.z) - ft_sqr(l_ray.org.y * c->radius);;
	// tmp = vec3_sub_new(ray.org, c->pos);
	// ce.x = vec3_dot(ray.dir, c->norm);
	// ce.x = vec3_dot(ray.dir, ray.dir) - (1 + ft_sqr(c->radius) * ft_sqr(ce.x));
	// ce.y = 2 * (vec3_dot(ray.dir, tmp) - (1 + ft_sqr(c->radius)) * vec3_dot(ray.dir, c->norm) * vec3_dot(tmp, c->norm));
	// ce.z = vec3_dot(tmp, c->norm);
	// ce.z = vec3_dot(tmp, tmp) - (1 + ft_sqr(c->radius) * ft_sqr(ce.z));
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
	// if (t1  c->height || t2 <= c->height)
	// {
	if (t1 > RAY_T_MIN && t1 < l_ray.max)
		return (1);
	else if (t2 > RAY_T_MIN && t2 < l_ray.max)
		return (1);
	return (0);
}
// static int	lower_than_min(double r, t_shape *c, t_ray ray)
// {
// 	if (r > 0)
// 	{
// 		if (vec3_dot(c->norm, vec3_sub_new(vec3_add_new(ray.org, vec3_mul_new(ray.dir, r)), c->pos)) < 0.0)
// 			return (1);
// 	}
// 	else
// 		return (1);
// 	return (0);
// }

// static int	higher_than_max(double r, t_shape *c, t_ray ray)
// {
// 	if (r > 0)
// 	{
// 		if (vec3_dot(c->norm, vec3_sub_new(vec3_add_new(ray.org, vec3_mul_new(ray.dir, r)),
// 			vec3_add_new(c->pos, vec3_mul_new(c->norm, c->height)))) > 0.0)
// 			return (1);
// 	}
// 	else
// 		return (1);
// 	return (0);
// }

// static void	get_finite_cone_intersection(double *t1, double *t2, t_ray ray, t_shape *c)
// {
// 	int	r1_too_low;
// 	int	r1_too_high;
// 	int	r2_too_low;
// 	int	r2_too_high;

// 	r1_too_low = lower_than_min(*t1, c, ray) || *t1 == -1;
// 	r1_too_high = higher_than_max(*t1, c, ray) || *t1 == -1;
// 	r2_too_low = lower_than_min(*t2, c, ray) || *t2 == -1;
// 	r2_too_high = higher_than_max(*t2, c, ray) || *t2 == -1;
// 	if (r1_too_low || r1_too_high)
// 	{
// 		*t1 = NAN;
// 		if (r2_too_low || r2_too_high)
// 			*t2 = NAN;
// 	}
// 	else if (!r1_too_low && !r1_too_high)
// 		*t2 = NAN;
// }

// int		cone_inter(t_shape *c, t_inter *i)
// {
// 	t_vec3	tmp;
// 	t_vec3	ce;
// 	t_ray	r;
// 	double	dis;
// 	double angle;
// 	double t1;
// 	double t2;

// 	if (c->height)
// 		angle = tan(atan(c->radius / c->height));
// 	else
// 		return (0);
// 	r = ray_cpy(i->ray);
// 	tmp = vec3_sub_new(i->ray.org, c->pos);
// 	ce.x = vec3_dot(r.org, r.org) - (1 + ft_sqr(angle)) * ft_sqr(vec3_dot(r.dir, c->norm));
// 	ce.y = 2 * (vec3_dot(r.dir, tmp) - (1 + ft_sqr(angle)) * vec3_dot(r.dir, c->norm) * vec3_dot(tmp, c->norm));
// 	ce.z = vec3_dot(tmp, tmp) - (1 + ft_sqr(angle) * ft_sqr(vec3_dot(tmp, c->norm)));
// 	dis = (ce.y * ce.y) - (4 * ce.x * ce.z);
// 	if (dis < 0)
// 		return (0);
// 	t1 = (-ce.y - sqrt(dis)) / (2 * ce.x);
// 	t2 = (-ce.y + sqrt(dis)) / (2 * ce.x);
// 	if (t1 > t2)
// 	{
// 		t1 = t1 + t2;
// 		t2 = t1 - t2;
// 		t1 = t1 - t2;
// 	}
// 	get_finite_cone_intersection(&t1, &t2, r, c);
// 	(t1 < 0 || isnan(t1)) ? t1 = t2 : 0;
// 	if (t1 < 0 || isnan(t1))
// 		return (0);
// 	i->t > t1 ? i->t = t1 : 0;
// 	i->shape = c;
// 	tmp = vec3_add_new(r.org , vec3_mul_new(r.dir, i->t));
// 	i->normal = cone_normal(tmp, c);
// 	return (1);
// }
// int		cone_ray(t_shape *c, t_ray r)
// {
// 	t_vec3	tmp;
// 	t_vec3	ce;
// 	double	dis;
// 	double angle;
// 	double t1;
// 	double t2;

// 	if (c->height)
// 		angle = tan(atan(c->radius / c->height));
// 	else
// 		return (0);
// 	tmp = vec3_sub_new(r.org, c->pos);
// 	ce.x = vec3_dot(r.org, r.org) - (1 + ft_sqr(angle)) * ft_sqr(vec3_dot(r.dir, c->norm));
// 	ce.y = 2 * (vec3_dot(r.dir, tmp) - (1 + ft_sqr(angle)) * vec3_dot(r.dir, c->norm) * vec3_dot(tmp, c->norm));
// 	ce.z = vec3_dot(tmp, tmp) - (1 + ft_sqr(angle) * ft_sqr(vec3_dot(tmp, c->norm)));
// 	dis = (ce.y * ce.y) - (4 * ce.x * ce.z);
// 	if (dis < 0)
// 		return (0);
// 	t1 = (-ce.y - sqrt(dis)) / (2 * ce.x);
// 	t2 = (-ce.y + sqrt(dis)) / (2 * ce.x);
// 	if (t1 > t2)
// 	{
// 		t1 = t1 + t2;
// 		t2 = t1 - t2;
// 		t1 = t1 - t2;
// 	}
// 	get_finite_cone_intersection(&t1, &t2, r, c);
// 	(t1 < 0 || isnan(t1)) ? t1 = t2 : 0;
// 	if (t1 < 0 || isnan(t1))
// 		return (0);
// 	return (1);
// }