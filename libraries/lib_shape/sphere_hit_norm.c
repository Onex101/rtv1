/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_hit_norm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:12:05 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/26 10:34:53 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_shape.h"

t_vec3	sphere_hit_norm(t_shape *s, t_vec3 hit)
{
	t_vec3 hit_norm;

	hit_norm = vec3_sub_new(hit, s->pos);
	vec3_nor(&hit_norm);
	return (hit_norm);
}
