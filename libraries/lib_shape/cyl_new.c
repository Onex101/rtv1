/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 07:27:36 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/07 10:55:58 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_shape.h"

t_shape	cyl_new(t_vec3 pos, t_vec3 norm, t_colour col, double rad)
{
	t_shape cyl;

	cyl.inter = cyl_inter;
	cyl.norm = norm;
	cyl.pos = pos;
	cyl.radius = rad;
	cyl.ray = NULL;
	cyl.col = col;
	return (cyl);
}