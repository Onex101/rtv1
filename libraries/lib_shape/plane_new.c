/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 08:01:27 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/05 10:41:57 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_shape.h"

t_shape		plane_new(t_vec3 pos, t_vec3 norm)
{
	t_shape plane;

	plane.inter = plane_inter; 
	plane.pos = pos;
	plane.radius = 0;
	plane.norm = norm;
	plane.ray = plane_ray;

	return(plane);
}