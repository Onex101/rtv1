/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 07:50:53 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/27 16:05:39 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_shape.h"

t_shape		*cone_new(t_vec3 pos, t_vec3 axis, double rad, t_colour col)
{
	t_shape	*cone;
	double	angle;

	if (!(cone = (t_shape *)malloc(sizeof(t_shape))))
		return (NULL);
	cone->pos = pos;
	cone->norm = vec3_nor_cpy(axis);
	cone->radius = rad;
	cone->height = 2;
	cone->inter = cone_inter;
	cone->ray = cone_ray;
	cone->col = col;
	cone->tex = 0;
	angle = acos(vec3_dot((t_vec3){0, 1, 0}, axis) / vec3_len(axis));
	cone->imat = matrix_axis_rot(vec3_crs(axis, (t_vec3){0, 1, 0}), -angle);
	cone->mat = matrix_inverse(&cone->imat);
	return (cone);
}
