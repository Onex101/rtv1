/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 09:19:59 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/27 18:46:04 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	main(int argc, char **argv)
{
	t_param *p;
	
	char *name = argv[1];

	name--;
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
			t_light		*l;
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
			total = vector_total(p->lis);
			printf("lis total after read= [%d]\n", vector_total(p->lis));
			i = -1;	
			while (++i < total)
			{
				l = (t_light *)vector_get(p->lis, i);
				printf("l[%d] col[%f, %f, %f]\n", i, l->col.b, l->col.g, l->col.r);
				printf("l[%d] intensity[%f]\n", i, l->intensity);
			}
			// while (1)
			render(p);
			ft_putendl("About to loop");
			SDL_Event win_event;
			bool	running = true;
			while (running)
			{
				//ft_putendl("running");

				SDL_PollEvent(&win_event);
				
				if (win_event.type == SDL_QUIT || (win_event.type == SDL_WINDOWEVENT && win_event.window.event == SDL_WINDOWEVENT_CLOSE))
				{
					ft_putendl("Quitting program");	
					running = false;
				} else if (win_event.type == SDL_KEYDOWN) {
					ft_putendl("Key was pressed");
				}			
			}
			ft_putendl("Done loop");
			printf("Camera: org[%f, %f, %f], target[%f, %f, %f], up[%f, %f, %f], fov[%f], aspect_ratio[%f]\n", p->cam->org.x, p->cam->org.y, p->cam->org.z, p->cam->tar.x, p->cam->tar.y, p->cam->tar.z, p->cam->up.x, p->cam->up.y, p->cam->up.z, p->cam->h, p->cam->w);
			if (p)
			{
				exit_program(p);
				SDL_DestroyWindow(win);
				SDL_Quit();
				ft_putendl("ep test 7");
				exit(0);
			}
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