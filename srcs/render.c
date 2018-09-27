/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 13:19:45 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/27 11:24:14 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		render(t_param *p)
{
	static int i;

	printf("test render1\n");
	if (!i++)
		ray_trace(p);
	SDL_UpdateWindowSurface(p->win);
	// mlx_put_image_to_window(p->mlx, p->win, p->img->add, 0, 0);
	return (0);
}