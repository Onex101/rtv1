/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 09:12:04 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/05 15:31:24 by xrhoda           ###   ########.fr       */
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

	j = -1;
	while(++j < p->img->w)
	{
		i = -1 ;
		while (++i < p->img->h)
		{
			//printf("a = [%f] b = [%f] c = [%f]\n", a, b, c);
			// ft_putstr("Cam org = ");
			// vec3_prnt(p->cam->org);
			//printf("WIDTH = [%d] HEIGHT = [%d]\n", p->img->w, p->img->h);
			vec3_init(&scrn_cor, (((2 * i) / (double)p->img->h) - 1), (((-2 * j) / (double)p->img->w) + 1), 0);
			//printf("scrn_cor {x = [%f] y = [%f] z = [%f]}\n", scrn_cor.x, scrn_cor.y, scrn_cor.z);
			ray = make_ray(p->cam, scrn_cor);
			// ft_putstr("Ray origin =    ");
			// vec3_prnt(ray.org);
			// ft_putstr("Ray direction = ");
			// vec3_prnt(ray.dir);
			//printf("ray.org.x = [%f] | ray.org.y= [%f]\n", ray.dir.x, ray.dir.y);

/*
**	Create a ray
*/
			inter_init(&inter, ray);
			//printf("inter.ray.org.x = [%f] | inter.ray.org.y= [%f] | inter.shape = [%p]\n", inter.ray.org.x, inter.ray.org.y, inter.shape);
/*
**	Inititalizse intercept
**	Check if intercept intercects with any of the shapes
*/			
			//p->img->buf[p->img->w * j + i] = mlx_get_color_value(p->mlx, 0xFFFFFF);
			if(set_inter(p->set, &inter))
			{
				//printf("ray.dir.x = [%f] | ray.dir.y= [%f] | ray.dir.z = [%f]\n", ray.dir.x, ray.dir.y, ray.dir.z);
				p->img->buf[p->img->w * j + i] = mlx_get_color_value(p->mlx, 0xFFFFFF);
			}
			else
				p->img->buf[p->img->w * j + i] = mlx_get_color_value(p->mlx, 0x000000);
		}
	}
	//ft_putendl("ray_trace done");
	return (0);
}