/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 13:19:45 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/26 14:32:27 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		render(t_param *p)
{
	static int i;

	// printf("test render1\n");
	if (!i++)
		ray_trace(p);
	// printf("test render2\n");
	mlx_put_image_to_window(p->mlx, p->win, p->img->add, 0, 0);
	return (0);
}