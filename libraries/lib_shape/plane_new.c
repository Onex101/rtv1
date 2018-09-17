/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 08:01:27 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/17 08:19:58 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_shape.h"

t_shape		plane_new(t_vec3 pos, t_vec3 norm, t_colour col, double tex)
{
	t_shape plane;

	plane.inter = plane_inter; 
	plane.pos = pos;
	plane.radius = 0;
	plane.norm = vec3_nor_cpy(norm);
	plane.ray = plane_ray;
	plane.col = col;
	plane.tex = tex;
	return(plane);
}