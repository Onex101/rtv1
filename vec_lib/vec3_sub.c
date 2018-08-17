/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_sub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeno <xeno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 17:44:31 by xeno              #+#    #+#             */
/*   Updated: 2018/08/17 14:51:21 by xeno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_lib.h"

void	vec3_sub(t_vec3 *v1, const t_vec3 v2)
{
	v1->x -= v2.x;
	v1->y -= v2.y;
	v1->z -= v2.z;
}

t_vec3	vec3_sub_new(const t_vec3 v1, const t_vec3 v2)
{
	t_vec3 cpy;

	cpy = vec3_cpy(v1);
	vec3_sub(&cpy, v2);
	return (cpy);
}