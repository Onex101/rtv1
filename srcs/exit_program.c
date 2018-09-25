/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 13:50:53 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/25 18:41:30 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	exit_program(t_param *p)
{
	ft_putendl("ep test 1");
	if (p->img)
		destroy_image(p->img, p->mlx);
	ft_putendl("ep test 2");
	if (p->win)
		mlx_destroy_window(p->mlx, p->win);
	ft_putendl("ep test 3");
	if (p->mlx)
		free(p->mlx);
	ft_putendl("ep test 4");
	if (p->set)
		vector_delete(p->set, 0);
	ft_putendl("ep test 5");
	if (p->cam)
		free(p->cam);
	if (p->lis)
		vector_delete(p->lis, 0);
	exit(0);
}
