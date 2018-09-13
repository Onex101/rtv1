/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 09:12:04 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/13 08:08:25 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

int ray_trace(t_param *p)
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
				gamma_correct(&(inter.col), 1, 2.2);
				clamp(&(inter.col), 255, 0);
				col = rgb_to_hex(inter.col.r, inter.col.g, inter.col.b);
				p->img->buf[p->img->w * j + i] = mlx_get_color_value(p->mlx, col);
			}
			else
				p->img->buf[p->img->w * j + i] = mlx_get_color_value(p->mlx, 0x000000);
		}
	}
	return (0);
}