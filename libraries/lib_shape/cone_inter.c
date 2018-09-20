/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 07:53:02 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/20 13:49:05 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_shape.h"

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
	// if (t2 > RAY_T_MIN && t2 < i->t)
	// 	i->t = t2;
	else
		return (0);
	// }
	// else
	// 	return (0);
	//printf("i.t = [%f] t1 = [%f] t2 = [%f]\n", i.t, t1, t2);
	i->shape = c;
	tmp = vec3_add_new(l_ray.org , vec3_mul_new(l_ray.dir, i->t));
	vec3_nor(&tmp);
	int num;
	if (tmp.y <= 0)
		num = c->radius;
	else
		num = -c->radius;
	i->normal = vec3_nor_cpy((t_vec3){tmp.x, 0 , tmp.z});
	// i->normal = vec3_nor_cpy((t_vec3){tmp.x / c->radius, num, tmp.z / c->radius});
	// i->normal = (matrix_vec_mult((i->normal), c->mat));
	return (1);
}

int		cone_ray(t_shape *c, t_ray l_ray)
{
	t_vec3 ce;
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
	// else if (t2 > RAY_T_MIN && t2 < l_ray.max)
	// 	return (1);
	return (0);
}