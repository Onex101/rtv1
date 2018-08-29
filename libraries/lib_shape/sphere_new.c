/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 12:00:48 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/29 10:38:02 by xrhoda           ###   ########.fr       */
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
	return (s); 
}
