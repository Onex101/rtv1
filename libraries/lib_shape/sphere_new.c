/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 12:00:48 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/12 06:13:27 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_shape.h"

t_shape	sphere_new(t_vec3 pos, double radius, t_colour col)
{
	t_shape s;

	s.pos = pos;
	s.radius = radius;
	s.height = 0;
	s.norm = vec3();
	s.inter = sphere_inter;
	s.ray = sphere_ray;
	s.hit_nor = sphere_hit_norm;
	s.col = col;
	matrix_identity(&(s.mat));
	s.imat = matrix_inverse(&(s.mat));
	return (s); 
}
