/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 09:12:04 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/27 11:32:30 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

// static	unsigned	long	grab_col(t_ray r, t_inter i, t_param *p)
// {
// 	unsigned long col;
// 	t_vec3 hit;

// 	hit = vec3_add_new(i.ray.org,
// 				vec3_mul_new(i.ray.dir, i.t));
// 	i.col = get_colour(p, &i, r, hit);
// 	col = rgb_to_hex(i.col.r, i.col.g, i.col.b);
// 	return (col);
// }

int 	ray_trace(t_param *p)
{
	int		i;
	int		j;
	t_vec3	scrn_cor;
	t_ray	ray;
	t_inter	inter;
	t_vec3 hit_pnt;
	// unsigned long	col;

	j = -1;
	while(++j < WIDTH)
	{
		i = -1 ;
		while (++i < HEIGHT)
		{
			vec3_init(&scrn_cor, (((2 * i) / (double)HEIGHT) - 1), -(((-2 * j) / (double)WIDTH) + 1), 0);
			ray = make_ray(p->cam, scrn_cor);
			// printf("test ray trace 4\n");
			inter_init(&inter, ray);
			// printf("test ray trace 5\n");
			if (set_inter(p->set, &inter))
			{
				hit_pnt = vec3_add_new(inter.ray.org, vec3_mul_new(inter.ray.dir, inter.t));
				// vec3_nor(&hit_pnt);
				//lighting
				inter.col = get_colour(p, &inter, ray, hit_pnt);
				//
				gamma_correct(&(inter.col), 0.3, 1.5);
				clamp(&(inter.col), 1, 0);
				put_pixel(i, j, inter.col, p);
				// col = rgb_to_hex(inter.col.r, inter.col.g, inter.col.b);
				// p->img->buf[p->img->w * j + i] = mlx_get_color_value(p->mlx, col);
			}
			else
				put_pixel(i, j, (t_colour){0 ,0 ,0}, p);
				// p->img->buf[p->img->w * j + i] = mlx_get_color_value(p->mlx, 0x000000);
				continue;
		}
	}
	// printf("test ray trace 10\n");
	return (0);
}
