/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeno <xeno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 13:50:53 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/28 16:00:23 by xeno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	exit_program(t_param *p)
{
	if (p->img)
		destroy_image(p->img, p->mlx);
	if (p->win)
		mlx_destroy_window(p->mlx, p->win);
	if (p->mlx)
		free(p->mlx);
	if (p->set)
		vector_delete(p->set, 0);
	if (p->cam)
		free(p->cam);
	exit(0);
}