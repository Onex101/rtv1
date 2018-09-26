/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 09:12:04 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/26 14:32:26 by shillebr         ###   ########.fr       */
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
	// printf("test ray trace 1\n");
	while (++j < p->img->w)
	{
		i = -1;
		// printf("test ray trace 2\n");
		while (++i < p->img->h)
		{
			vec3_init(&scrn_cor, (((2 * i) / (double)p->img->h) - 1),
								-(((-2 * j) / (double)p->img->w) + 1), 0);
			// printf("test ray trace 3\n");
			ray = make_ray(p->cam, scrn_cor);
			// printf("test ray trace 4\n");
			inter_init(&inter, ray);
			// printf("test ray trace 5\n");
			if (set_inter(p->set, &inter))
			{
				// printf("test ray trace 6\n");
				col = grab_col(ray, inter, p);
				// printf("test ray trace 7\n");
				p->img->buf[p->img->w * j + i] =
					mlx_get_color_value(p->mlx, col);
				// printf("test ray trace 8\n");
			}
			else
				p->img->buf[p->img->w * j + i] =
					mlx_get_color_value(p->mlx, 0x000000);
			// printf("test ray trace 9\n");
		}
	}
	// printf("test ray trace 10\n");
	return (0);
}
