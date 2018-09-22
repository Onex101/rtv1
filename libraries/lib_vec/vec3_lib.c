/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 06:26:00 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/03 18:13:10 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_vec.h"

t_vec3	vec3_new(double x, double y, double z)
{
	t_vec3 v;

	vec3_init(&v, x, y, z);
	return (v);
}

void	vec3_init(t_vec3 *v, double x, double y, double z)
{
	v->x = x;
	v->y = y;
	v->z = z;
}

t_vec3	vec3(void)
{
	return((t_vec3){0, 0, 0});
}

t_vec3	vec3_cpy(const t_vec3 v)
{
	return (vec3_new(v.x, v.y, v.z));
}
