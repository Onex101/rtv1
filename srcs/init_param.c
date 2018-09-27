/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 09:11:25 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/27 10:32:43 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		init_param(t_param *p)
{
	double fov;

	fov = 25 * M_PI / 180;
	if (!(p->mlx = mlx_init()))
		return (0);
	if (!(p->win = mlx_new_window(p->mlx, WIDTH, HEIGHT, "rtv1")))
		return (0);
	if (!(p->img = new_image(p->mlx, WIDTH, HEIGHT)))
		return (0);
	if (!(p->cam = new_cam((t_vec3){0, 3, -10}, (t_vec3){0, 1, 0}, fov)))
		return (0);
	if (!(p->set = vector_new()))
		return (0);
	if (!(p->lis = vector_new()))
		return (0);
	return (1);
}
