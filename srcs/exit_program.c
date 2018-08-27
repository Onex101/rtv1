/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 13:50:53 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/27 16:33:18 by xrhoda           ###   ########.fr       */
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
	exit(0);
}