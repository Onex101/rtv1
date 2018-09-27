/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 13:50:53 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/27 08:50:15 by shillebr         ###   ########.fr       */
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
		vector_free(p->set);
	ft_putendl("ep test 5");
	if (p->cam)
		free(p->cam);
	if (p->lis)
		vector_free(p->lis);
	exit(0);
}
