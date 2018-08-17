/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 06:26:00 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/17 12:13:45 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_lib.h"

t_vec3	*vec3_new(double x, double y, double z)
{
	t_vec3 *v;

	v = (t_vec3 *)malloc(sizeof(t_vec3));
	if (!v)
		return (NULL);
	vec3_init(v, x, y, z);
	return (v);
}

void	vec3_init(t_vec3 *v, double x, double y, double z)
{
	if (v)
	{
		v->x = x;
		v->y = y;
		v->z = z;
	}
}

t_vec3	*vec3_cpy(t_vec3 *v)
{
	t_vec3 *cpy;

	if (v)
	{
		cpy = vec3_new(v->x, v->y, v->z);
		return (cpy);
	}
	return (NULL);
}

void	vec3_del(t_vec3 *v)
{
	if (v)
		free(v);
}
