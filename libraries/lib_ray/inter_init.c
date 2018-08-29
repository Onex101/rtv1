/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeno <xeno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 09:52:04 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/28 16:32:22 by xeno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ray.h"

void	inter_init(t_inter *i, t_ray r)
{
	i->ray = r;
	i->shape = NULL;
	i->t = r.max;
}

t_inter	inter(void)
{
	return((t_inter){ray(), NULL, RAY_T_MAX});
}