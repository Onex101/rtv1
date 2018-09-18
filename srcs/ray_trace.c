/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 09:12:04 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/18 13:51:19 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

int 	cast_ray(t_vector *s, t_ray r)
{
	int		j;
	t_shape	*cur_shp;

	j = -1;
	while (++j < s->total)
	{
		cur_shp = (t_shape *)vector_get(s, j);
		if (cur_shp->ray(cur_shp, r))
		{
			//ft_putendl("Collision found");
			return (1);
		}
	}
	return (0);
}

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

t_colour	get_colour(t_param *p, t_inter *in, t_ray r, t_vec3 hit_pnt)
{
	t_light		*l;
	int			i;
	int			total;
	t_colour	clr;
	t_colour	total_clr;

	total = vector_total(p->lis);
	i = -1;
	total_clr = (t_colour){0, 0, 0};
	while (++i < total)
	{
		l = (t_light *)vector_get(p->lis, i);
		clr = calc_light(l, p, in, r, hit_pnt);
		total_clr = (t_colour){total_clr.r + clr.r, total_clr.g + clr.g, total_clr.b + clr.b};
	}
	return (total_clr);
}

int 	ray_trace(t_param *p)
{
	int		i;
	int		j;
	t_vec3	scrn_cor;
	t_ray	ray;
	t_inter	inter;
	t_vec3 hit_pnt;
	unsigned long	col;

	j = -1;
	while(++j < p->img->w)
	{
		i = -1 ;
		while (++i < p->img->h)
		{
			vec3_init(&scrn_cor, (((2 * i) / (double)p->img->h) - 1), -(((-2 * j) / (double)p->img->w) + 1), 0);
			ray = make_ray(p->cam, scrn_cor);
/*
**	Create a ray
*/
			inter_init(&inter, ray);
/*
**	Inititalizse intercept
**	Check if intercept intercects with any of the shapes
*/			
			if (set_inter(p->set, &inter))
			{
				hit_pnt = vec3_add_new(inter.ray.org, vec3_mul_new(inter.ray.dir, inter.t));
				// vec3_nor(&hit_pnt);
				//lighting
				inter.col = get_colour(p, &inter, ray, hit_pnt);
				//
				gamma_correct(&(inter.col), 1, 2.2);
				clamp(&(inter.col), 255, 0);
				col = rgb_to_hex(inter.col.r, inter.col.g, inter.col.b);
				p->img->buf[p->img->w * j + i] = mlx_get_color_value(p->mlx, col);
			}
			else
				p->img->buf[p->img->w * j + i] = mlx_get_color_value(p->mlx, 0x000000);
		}
	}
	// exit (0);
	return (0);
}
