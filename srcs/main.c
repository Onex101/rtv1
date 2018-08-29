/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 09:19:59 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/29 09:38:51 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		init_param(t_param *p)
{
	if (!(p->mlx = mlx_init()))
		return (-1);
	if(!(p->win = mlx_new_window(p->mlx, WIDTH, HEIGHT, "rtv1")))
		return (-1);	
	if (!(p->img = new_image(p->mlx, WIDTH, HEIGHT)))
		return (-1);
	if (!(p->cam = new_cam((t_vec3){-5, 1, 0}, (t_vec3){0, 1, 0}, vec3(), 3.147 / 4, WIDTH / HEIGHT)))
		return (-1);
	if (!(p->set))
		vector_init(p->set);
}

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
			scrn_cor = (t_vec3){(2 * j / p->img->w) - 1, (-2 * i / p->img->h) + 1, 0};
			ray = make_ray(p->cam, scrn_cor);
/*
**	Create a ray
* /
			inter_init(&inter, ray);
/*
**	Inititalizse intercept
**	Check if intercept intercects with any of the shapes
*/
			if(shape_inter(p->set, inter))
				p->img->buf[p->img->w * j + i] = 1;
			else
				p->img->buf[p->img->w * j + i] = 0;
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_param *p;
	t_shape sphere;
	t_shape plane;

	if (init_param(p) != -1)
	{
		sphere = sphere_new((t_vec3){0, 1, 0}, 1);
		plane = plane_new(vec3(), vec3());
		vector_add(p->set, &sphere);
		vector_add(p->set, &plane);
	}
	else
	{
		ft_putendl("Error: Failed to Initialize Parameters");
		exit_program(p);
	}
	return (0);
}