/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 09:12:04 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/27 15:42:44 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

static unsigned long	grab_col(t_ray r, t_inter i, t_param *p)
{
	unsigned long	col;

	i.col = get_colour(p, &i, r);
	col = rgb_to_hex(i.col.r, i.col.g, i.col.b);
	return (col);
}

void					ray_calc(t_param *p, int i, int j)
{
	t_vec3			scrn_cor;
	t_ray			ray;
	t_inter			inter;
	unsigned long	col;

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

int						ray_trace(t_param *p)
{
	int				i;
	int				j;

	j = -1;
	while (++j < p->img->w)
	{
		i = -1;
		while (++i < p->img->h)
			ray_calc(p, i, j);
	}
	return (0);
}
