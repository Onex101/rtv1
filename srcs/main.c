/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 09:19:59 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/26 10:37:11 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_exit(t_param *p)
{
	if (p)
	{
		exit (0);
	}
	exit (0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_param *p;
	t_shape sphere0;
	t_shape sphere1;
	t_shape sphere2;
	t_shape sphere3;
	t_shape plane;
	t_shape plane1;
	t_shape cyl;
	t_light	lit;
	t_light	lit2;
	t_light	lit3;
	t_light lit4;
	t_shape cone0;
	t_shape cone1;
	t_shape cone2;
	t_shape cone3;
	// char	*name;

	if (argc == 1)
	{
		p = (t_param *)malloc(sizeof(t_param));
		if (init_param(p))
		{

			// if (!(ft_rt(argv[1])))
			// {
			// 	ft_putendl("Error: Invalid File Type");
			// 	if (p)
			// 		exit_program(p);
			// }
			// if (!(read_file(argv[1], p)))
			// {
			// 	ft_putendl("Error: Invalid File Read");
			// 	if (p)
			// 		exit_program(p);
			// }
			// printf("Camera: org[%f, %f, %f], target[%f, %f, %f], up[%f, %f, %f], fov[%f], aspect_ratio[%f]\n", p->cam->org.x, p->cam->org.y, p->cam->org.z, p->cam->tar.x, p->cam->tar.y, p->cam->tar.z, p->cam->up.x, p->cam->up.y, p->cam->up.z, p->cam->h, p->cam->w);
			
			// name  = argv[0];
			ft_putendl(argv[0]);
			sphere0 = sphere_new((t_vec3){0, 3, 5}, 0.2, (t_colour){255, 0, 0}, 0.001);
			sphere1 = sphere_new((t_vec3){2, 2, -4}, 0.5, (t_colour){0, 255, 0}, 0.001);
			sphere2 = sphere_new((t_vec3){2, 2, 4}, 0.5, (t_colour){0, 255, 0}, 0.001);
			sphere3 = sphere_new((t_vec3){-2, 2, 4}, 0.5, (t_colour){0, 255, 0}, 0.001);
			cyl = cyl_new((t_vec3){0, 0, 0}, (t_vec3){0, 1, 0}, (t_colour){255, 255, 255}, 0.001);
			plane = plane_new((t_vec3){0, 0, 0}, (t_vec3){0, 1, 0}, (t_colour){125, 255, 0}, 0.001);
			plane1 = plane_new((t_vec3){0, 5, 10}, (t_vec3){0, 0, 0.5}, (t_colour){125, 0, 255}, 0.001);
			cone0 = cone_new((t_vec3){0, 3, 5}, (t_vec3){0.7, 0.5, 0}, 1, (t_colour){255, 255, 0});
			cone1 = cone_new((t_vec3){0, 3, 5}, (t_vec3){-0.7, 0.5, 0}, 1, (t_colour){255, 255, 0});
			cone2 = cone_new((t_vec3){2, 2, 4}, (t_vec3){0, 1, 0}, 1, (t_colour){255, 255, 0});
			cone3 = cone_new((t_vec3){-2, 2, 4}, (t_vec3){0, 1, 0}, 1, (t_colour){255, 255, 0});
			vector_add(p->set, &plane);
			vector_add(p->set, &plane1);
			vector_add(p->set, &cone0);
			vector_add(p->set, &cone1);
			// vector_add(p->set, &cone2);
			// vector_add(p->set, &cone3);
			// vector_add(p->set, &cyl);
			vector_add(p->set, &sphere0);
			// vector_add(p->set, &sphere1);
			// vector_add(p->set, &sphere2);
			// vector_add(p->set, &sphere3);
			// vector_add(p->set, &sphere1);
			// vector_add(p->set, &sphere2);
			
			lit = light_new((t_vec3){-1, -1, -1}, 1, (t_colour){255, 255, 255});
			lit2 = light_new((t_vec3){0, -5, 5}, 0.5, (t_colour){255, 255, 255});
			lit3 = light_new((t_vec3){1, -1, 1}, 0.3, (t_colour){255, 255, 255});
			lit4 = light_new((t_vec3){-1, -1, 1}, 0.3, (t_colour){255, 255, 255});
			
			vector_add(p->lis, &lit);
			vector_add(p->lis, &lit2);
			// vector_add(p->lis, &lit3);
			// vector_add(p->lis, &lit4);
			// vector_add(p->set, &sphere1);
			// vector_add(p->set, &sphere2);
			if (OS)
				mlx_hook(p->win, 2, 0, key_press, p);
			else
				mlx_hook(p->win, 2, 1, key_press, p);
			mlx_hook(p->win, 17, 0, ft_exit, p);
			mlx_loop_hook(p->mlx, render, p);
			mlx_loop(p->mlx);
		}
		else
		{
			ft_putendl("Error: Failed to Initialize Parameters");
			if (p)
				exit_program(p);
		}
	}
	else
	{
		ft_putendl("Error: Incorrect Number of Arguments");
		return (1);
	}
	return (0);
}