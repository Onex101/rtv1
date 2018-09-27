/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 09:19:59 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/27 11:30:25 by xrhoda           ###   ########.fr       */
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
	SDL_Event win_event;

	if (argc == 2)
	{
		if (!(p = malloc(sizeof(t_param))))
		{
			ft_putendl("Failed to malloc");
			return (0);
		}
		if (init_param(p))
		{
			if (!(ft_rt(argv[1])))
			{
				ft_putendl("Error: Invalid File Type");
				if (p)
					exit_program(p);
			}
			if (!(read_file(argv[1], &p)))
			{
				ft_putendl("Error: Invalid File Read");
				if (p)
					exit_program(p);
			}
			t_shape		*s;
			int			i;
			int			total;

			total = vector_total(p->set);
			printf("set total after read= [%d]\n", vector_total(p->set));
			i = -1;
			while (++i < total)
			{
				s = (t_shape *)vector_get(p->set, i);
				printf("s[%d] pos[%f, %f, %f]\n", i, s->pos.x, s->pos.y, s->pos.z);
				printf("s[%d] radius[%f]\n", i, s->radius);
			}
			render(p);
			while (true)
			{
				if (SDL_PollEvent(&win_event))
				{
					if (SDL_QUIT == win_event.type)
					{
						break;
					}
				}
			}
			printf("Camera: org[%f, %f, %f], target[%f, %f, %f], up[%f, %f, %f], fov[%f], aspect_ratio[%f]\n", p->cam->org.x, p->cam->org.y, p->cam->org.z, p->cam->tar.x, p->cam->tar.y, p->cam->tar.z, p->cam->up.x, p->cam->up.y, p->cam->up.z, p->cam->h, p->cam->w);
			if (p)
				exit_program(p);
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