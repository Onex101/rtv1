/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 13:50:53 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/27 16:17:42 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	exit_program(t_param *p)
{
	int i;
	int total;

	i = -1;
	total = p->set->total;
	ft_putendl("ep test 1");
	while (++i < total)
		free(vector_get(p->set, i));
	i = -1;
	total = p->lis->total;
	ft_putendl("ep test 2");
	while (++i < total)
		free(vector_get(p->lis, i));
	ft_putendl("ep test 3");
	ft_putendl("ep test 4");
	if (p->set)
		vector_free(p->set);
	ft_putendl("ep test 5");
	if (p->cam)
		free(p->cam);
	ft_putendl("ep test 6");
	if (p->lis)
		vector_free(p->lis);
	free(p);
	SDL_DestroyWindow(win);
	SDL_Quit();
	ft_putendl("ep test 7");
	exit(0);
}
