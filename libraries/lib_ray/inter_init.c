/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 09:52:04 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/26 10:40:57 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ray.h"

void	inter_init(t_inter *i, t_ray r)
{
	i->ray = r;
	i->shape = NULL;
	i->t = r.max;
	i->col = (t_colour){0, 0, 0};
	i->normal = vec3();
}

t_inter	inter(void)
{
	return ((t_inter){ray(), NULL, RAY_T_MAX, vec3(), (t_colour){0, 0, 0}, 0});
}
