/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 17:40:40 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/25 17:40:54 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_colour	calc_light(t_light *l, t_param *p, t_inter *in, t_ray r, t_vec3 hit_pnt)
{
	t_vec3		dir_to_light;
	double		light_power;
	double		light_reflected;
	t_colour	clr;
	t_colour	l_clr;
	t_ray		shadow_ray;

	dir_to_light = vec3_nor_cpy(l->dir);
	dir_to_light = (t_vec3){-dir_to_light.x, -dir_to_light.y, -dir_to_light.z};
	
	shadow_ray = (t_ray){hit_pnt, dir_to_light, RAY_T_MAX};
	if ((cast_ray(p->set, shadow_ray)))
		light_power = 0;
	else
		light_power = (fmax(0, vec3_dot(in->normal, dir_to_light))) * l->intensity;
	light_reflected = in->tex / M_PI;
	l_clr = (t_colour){(l->col.r * light_power * light_reflected), (l->col.g * light_power * light_reflected), (l->col.b * light_power * light_reflected)};
	clr = (t_colour){(in->col.r * l_clr.r), (in->col.g * l_clr.g), (in->col.b * l_clr.b)};
	return (clr);
	if (r.max > 0 && hit_pnt.x > 0)
		return (clr);
}
