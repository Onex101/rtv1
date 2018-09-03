/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 09:11:25 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/03 15:40:45 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		init_param(t_param *p)
{
	ft_putendl("init param 1");
	if (!(p->mlx = mlx_init()))
		return (0);
	ft_putendl("init param 2");
	if(!(p->win = mlx_new_window(p->mlx, WIDTH, HEIGHT, "rtv1")))
		return (0);
	ft_putendl("init param 3");
	if (!(p->img = new_image(p->mlx, WIDTH, HEIGHT)))
		return (0);
	ft_putendl("init param 4");
	if (!(p->cam = new_cam((t_vec3){-5, 1, 0}, (t_vec3){0, 1, 0}, vec3(), 25 * M_PI / 180, WIDTH / HEIGHT)))
		return (0);
	ft_putendl("init param 5");
	vector_init(p->set = vector_new());
	ft_putendl("init param 6");
	return (1);
}