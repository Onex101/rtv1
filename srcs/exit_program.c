/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 13:50:53 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/28 13:15:13 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	exit_program(t_param *p)
{
	int i;

	if (!p)
		exit(0);
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
	i = -1;
	ft_putendl("ep test 1");
	while (++i < p->set->total)
		free(vector_get(p->set, i));
	i = -1;
	ft_putendl("ep test 2");
	while (++i < p->lis->total)
		free(vector_get(p->lis, i));
	if (p->set)
		vector_free(p->set);
	ft_putendl("ep test 5");
	if (p->cam)
		free(p->cam);
	if (p->lis)
		vector_free(p->lis);
	exit(0);
}
