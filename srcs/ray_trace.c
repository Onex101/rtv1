/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 09:12:04 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/03 18:19:46 by xrhoda           ###   ########.fr       */
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
	while(++j < p->img->h)
	{
		i = -1 ;
		while (++i < p->img->w)
		{
			float a = (2 * j) / p->img->w - 1;
			float b = (-2 * i) / p->img->h + 1;
			float c = 0;
			//printf("a = [%f] b = [%f] c = [%f]\n", a, b, c);
			vec3_init(&scrn_cor, a, b, c);
			ft_putnbr(c);
			ft_putendl("");
			vec3_prnt(scrn_cor);
			ray = make_ray(p->cam, scrn_cor);
/*
**	Create a ray
*/
			inter_init(&inter, ray);
/*
**	Inititalizse intercept
**	Check if intercept intercects with any of the shapes
*/			
			//p->img->buf[p->img->w * j + i] = mlx_get_color_value(p->mlx, 0xFFFFFF);
			if(set_inter(p->set, inter))
				p->img->buf[p->img->w * j + i] = mlx_get_color_value(p->mlx, 0xFFFFFF);
			else
				p->img->buf[p->img->w * j + i] = mlx_get_color_value(p->mlx, 0x000000);
		}
	}
	//ft_putendl("ray_trace done");
	return (0);
}