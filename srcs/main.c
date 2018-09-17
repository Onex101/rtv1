/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 09:19:59 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/17 11:49:56 by shillebr         ###   ########.fr       */
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
	// t_shape sphere0;
	t_shape sphere1;
	// t_shape sphere2;
	t_shape plane;
	// t_shape cyl;
	t_light	lit;
	// char	*name;

	if (argc == 1)
	{
		p = (t_param *)malloc(sizeof(t_param));
		if (init_param(p))
		{
			// name  = argv[0];
			ft_putendl(argv[0]);
			// sphere0 = sphere_new((t_vec3){0, -1, 0}, 0.1, (t_colour){0, 255, 0}, 0.001);
			
			sphere1 = sphere_new((t_vec3){0, -3, -2}, 1.5, (t_colour){255, 255, 0}, 0.001);

			// sphere2 = sphere_new((t_vec3){0, -1, 2}, 0.3, (t_colour){0, 0, 255}, 0.001);
			// cyl = cyl_new((t_vec3){0, -1, 0}, (t_vec3){1, 0, 1}, (t_colour){0, 0, 255}, 1);
			plane = plane_new((t_vec3){0, 0, 0}, (t_vec3){0, 1, 0}, (t_colour){255, 0, 0}, 0.001);
			vector_add(p->set, &plane);
			// vector_add(p->set, &cyl);
			// vector_add(p->set, &sphere0);
			vector_add(p->set, &sphere1);
			// vector_add(p->set, &sphere2);
			
			lit = light_new((t_vec3){2, 5, -4}, 0.5, (t_colour){255, 255, 255});
			
			vector_add(p->lis, &lit);
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
		ft_putendl("Error: To Many Arguments");
		return (1);
	}
	return (0);
}