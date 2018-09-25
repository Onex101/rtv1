/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 09:11:25 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/25 13:15:16 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		init_param(t_param *p)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		ft_putendl("SDL Failed to initilise");
		return (0);
	}
	if (!(p->win = SDL_CreateWindow("RTV1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI)))
	{
		printf("Window failed to be initlaized");
		return (0);
	}
	if (!(p->cam = new_cam((t_vec3){2, 5, 10}, (t_vec3){0, 1, 0}, (t_vec3){0, 1, 0}, 60, WIDTH / HEIGHT)))
	{
		ft_putendl("Failed to initialise cam");
	}
	vector_init(p->set = vector_new());
	vector_init(p->lis = vector_new());
	return (1);
}
