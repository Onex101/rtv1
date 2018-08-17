/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_mul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 17:45:11 by xeno              #+#    #+#             */
/*   Updated: 2018/08/17 12:13:54 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_lib.h"

void	vec3_mul(t_vec3 *v, double i)
{
	if (v)
	{
		v->x *= i;
		v->y *= i;
		v->z *= i;
	}
}

t_vec3	*vec3_add_new(t_vec3 *v1, double i)
{
	t_vec3 *cpy;

	if (v1)
	{
		if (!(cpy = vec3_cpy(v1)))
			return (NULL);
		vec3_mul(cpy, i);
		return (cpy);
	}
	return (NULL);
}