/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 13:50:53 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/25 13:10:39 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	exit_program(t_param *p)
{
	ft_putendl("ep test 1");
	if (p->win)
		SDL_DestroyWindow(p->win);
	ft_putendl("ep test 2");
	if (p->set)
		vector_free(p->set);
	ft_putendl("ep test 3");
	if (p->cam)
		free(p->cam);
	ft_putendl("ep test 3");
	if (p->lis)
		vector_free(p->lis);
	SDL_Quit();
	exit(0);
}