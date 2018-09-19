/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 07:27:36 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/19 06:58:16 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_shape.h"

t_shape	cyl_new(t_vec3 pos, t_vec3 axis, t_colour col, double rad)
{
	t_shape cyl;
	t_mat mat;
	double angle;

	matrix_identity(&mat);
	cyl.norm = vec3_nor_cpy(axis);
	cyl.pos = pos;
	cyl.radius = rad;
	cyl.height = 1;
	cyl.inter = cyl_inter;
	cyl.ray = cyl_ray;
	cyl.col = col;
	angle = acos(vec3_dot(axis, (t_vec3){0, 1, 0}) / vec3_len(axis));
	cyl.imat = matrix_axis_rot(vec3_crs(axis, (t_vec3){0, 1, 0}), angle);
	cyl.mat = matrix_inverse(&(cyl.imat));
	return (cyl);
}