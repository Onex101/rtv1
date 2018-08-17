/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_sub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 17:44:31 by xeno              #+#    #+#             */
/*   Updated: 2018/08/17 12:13:48 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_lib.h"

void	vec3_sub(t_vec3 *v1, t_vec3 *v2)
{
	if (v1 && v2)
	{
		v1->x -= v2->x;
		v1->y -= v2->y;
		v1->z -= v2->z;
	}
}

t_vec3	*vec3_sub_new(t_vec3 *v1, t_vec3 *v2)
{
	t_vec3 *cpy;

	if (v1 && v2)
	{
		if (!(cpy = vec3_cpy(v1)))
			return (NULL);
		vec3_sub(cpy, v2);
		return (cpy);	
	}
	return (NULL);
}