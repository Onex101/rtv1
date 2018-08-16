/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeno <xeno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 06:26:00 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/16 16:18:50 by xeno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec3	*vec3_new(double x, double y, double z)
{
	t_vec3 *v;

	v = (t_vec3 *)malloc(sizeof(t_vec3));
	if (!v)
		return (NULL);
	vec3_init(v, x, y, z);
	return (vertex);
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

	cpy = vec3_new(v->x, v->y, v->z);
	return (cpy);
}

void	vec3_del(t_vec3 *v)
{
	if (v)
		free(v);
}
