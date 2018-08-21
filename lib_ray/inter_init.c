/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeno <xeno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 09:52:04 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/21 19:12:13 by xeno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ray.h"

void	inter_init(t_inter *i, t_ray r, t_shape s, double t)
{
	i->ray = r;
	i->shape = s;
	i->t = t;
}

t_inter	inter(void)
{
	return((t_inter){ray(), NULL, RAY_T_MAX});
}