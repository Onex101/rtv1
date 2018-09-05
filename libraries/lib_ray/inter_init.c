/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 09:52:04 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/05 20:13:31 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ray.h"

void	inter_init(t_inter *i, t_ray r)
{
	i->ray = r;
	i->shape = NULL;
	i->t = r.max;
	i->col = (t_colour){0, 0 ,0};
}

t_inter	inter(void)
{
	return((t_inter){ray(), NULL, RAY_T_MAX, (t_colour){0, 0, 0}});
}