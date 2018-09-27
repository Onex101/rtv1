/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 17:40:40 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/27 15:42:23 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_colour	light_col(t_light *l, double light_power, double light_reflected)
{
	double	r;
	double	g;
	double	b;

	r = (l->col.r * light_power * light_reflected);
	g = (l->col.g * light_power * light_reflected);
	b = (l->col.b * light_power * light_reflected);
	return ((t_colour){r, g, b});
}

t_colour	calc_col(t_inter *in, t_colour l_clr)
{
	double	r;
	double	g;
	double	b;

	r = (in->col.r * l_clr.r);
	g = (in->col.g * l_clr.g);
	b = (in->col.b * l_clr.b);
	return ((t_colour){r, g, b});
}

t_colour	calc_light(t_light *l, t_param *p, t_inter *in, t_ray r)
{
	t_vec3		dir_to_l;
	double		light_power;
	t_colour	clr;
	t_colour	l_clr;
	t_vec3		hit_pnt;

	hit_pnt = vec3_add_new(in->ray.org,
				vec3_mul_new(in->ray.dir, in->t));
	dir_to_l = vec3_nor_cpy(l->dir);
	dir_to_l = (t_vec3){-dir_to_l.x, -dir_to_l.y, -dir_to_l.z};
	if ((cast_ray(p->set, (t_ray){hit_pnt, dir_to_l, RAY_T_MAX})))
		light_power = 0;
	else
		light_power = (fmax(0, vec3_dot(in->normal, dir_to_l))) * l->intensity;
	l_clr = light_col(l, light_power, in->tex / M_PI);
	clr = calc_col(in, l_clr);
	return (clr);
	if (r.max > 0 && hit_pnt.x > 0)
		return (clr);
}
