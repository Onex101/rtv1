/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 17:43:47 by xeno              #+#    #+#             */
/*   Updated: 2018/09/27 15:54:54 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_vec.h"

void	vec3_add(t_vec3 *v1, t_vec3 v2)
{
	v1->x += v2.x;
	v1->y += v2.y;
	v1->z += v2.z;
}

t_vec3	vec3_add_new(const t_vec3 v1, const t_vec3 v2)
{
	t_vec3 cpy;

	cpy = vec3_cpy(v1);
	vec3_add(&cpy, v2);
	return (cpy);
}
