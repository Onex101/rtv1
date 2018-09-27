/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 13:19:45 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/27 15:24:06 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		render(t_param *p)
{
	static int i;

	printf("test render1\n");
	// while (1)
	// {
	if (!i++)
	{
		ft_putendl("test render2");
		ray_trace(p);
		ft_putendl("test render3");

	}
	ft_putendl("test render4");
	// exit(0);
	SDL_UpdateWindowSurface(win);
	ft_putendl("test render5");

	// }
	// mlx_put_image_to_window(p->mlx, p->win, p->img->add, 0, 0);
	return (0);
}
