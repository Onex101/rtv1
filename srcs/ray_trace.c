/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 09:12:04 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/13 14:03:21 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

void	get_colour(t_param *p, t_inter *in, t_ray r, t_vec3 hitpoint)
{
	t_light		*l;

	l = (t_light *)vector_get(p->lis, 0);
	printf("___________________________\n");
	printf("l->dir [%f, %f, %f]\n", l->dir.x, l->dir.y, l->dir.z);
	printf("intersect = [%f, %f, %f]    normal = [%f, %f, %f]\n", hitpoint.x, hitpoint.y, hitpoint.z, in->normal.x, in->normal.y, in->normal.z);
	if (p && in)
		return ;
	else if (r.org.x > 0)
		return ;
	else if(hitpoint.x > 0)
		return ;
	else
		return ;

	// t_vec3	dir_to_light;

	// dir_to_light = -vec3_nor(p->lis->dir);
	// light_power = (fmax(0, vec3_dot(in->n, dir_to_light))) * p->lis.light.intensity;
	// light_reflected = in->shape.text / M_PI;
	// color = int->shp.col * p->lis->light->col * light_power * light_reflected;

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
			vec3_init(&scrn_cor, (((2 * i) / (double)p->img->h) - 1), (((-2 * j) / (double)p->img->w) + 1), 0);
			ray = make_ray(p->cam, scrn_cor);
/*
**	Create a ray
*/
			inter_init(&inter, ray);
/*
**	Inititalizse intercept
**	Check if intercept intercects with any of the shapes
*/			
			if(set_inter(p->set, &inter))
			{
				hit_pnt = vec3_add_new(inter.ray.org, vec3_mul_new(inter.ray.dir, inter.t));
				vec3_nor(&hit_pnt);
				//lighting
				get_colour(p, &inter, ray, hit_pnt);
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
	exit (0);
	return (0);
}