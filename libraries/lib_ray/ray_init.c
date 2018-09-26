/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 11:26:05 by xeno              #+#    #+#             */
/*   Updated: 2018/09/26 10:42:03 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ray.h"

void	ray_init(t_ray *r, t_vec3 org, t_vec3 dir, double max)
{
	r->org = org;
	r->dir = dir;
	r->max = max;
}

t_ray	ray(void)
{
	t_ray r;

	r.org = (t_vec3){0, 0, 0};
	r.dir = (t_vec3){0, 0, 0};
	r.max = RAY_T_MAX;
	return (r);
}
