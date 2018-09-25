/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 09:12:04 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/25 18:34:09 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

static	unsigned	long	grab_col(t_ray r, t_inter i, t_param *p)
{
	unsigned long col;
	t_vec3 hit;

	hit = vec3_add_new(i.ray.org,
				vec3_mul_new(i.ray.dir, i.t));
	i.col = get_colour(p, &i, r, hit);
	col = rgb_to_hex(i.col.r, i.col.g, i.col.b);
	return (col);
}

int 	ray_trace(t_param *p)
{
	int				i;
	int				j;
	t_vec3			scrn_cor;
	t_ray			ray;
	t_inter			inter;
	unsigned long	col;

	j = -1;
	while (++j < p->img->w)
	{
		i = -1;
		while (++i < p->img->h)
		{
			vec3_init(&scrn_cor, (((2 * i) / (double)p->img->h) - 1),
								-(((-2 * j) / (double)p->img->w) + 1), 0);
			ray = make_ray(p->cam, scrn_cor);
			inter_init(&inter, ray);
			if (set_inter(p->set, &inter))
			{
				col = grab_col(ray, inter, p);
				p->img->buf[p->img->w * j + i] =
					mlx_get_color_value(p->mlx, col);
			}
			else
				p->img->buf[p->img->w * j + i] =
					mlx_get_color_value(p->mlx, 0x000000);
		}
	}
	return (0);
}
