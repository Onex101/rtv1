/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 12:00:48 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/05 20:06:29 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_shape.h"

t_shape	sphere_new(t_vec3 pos, double radius)
{
	t_shape s;

	s.pos = pos;
	s.radius = radius;
	s.norm = vec3();
	s.inter = sphere_inter;
	s.ray = sphere_ray;
	s.col = (t_colour){255, 0, 255};
	return (s); 
}
