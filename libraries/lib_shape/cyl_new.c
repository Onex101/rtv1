/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 07:27:36 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/10 09:21:57 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_shape.h"

t_shape	cyl_new(t_vec3 pos, t_vec3 norm, t_colour col, double rad)
{
	t_shape cyl;

	cyl.inter = cyl_inter;
	cyl.norm = vec3_nor_cpy(norm);
	cyl.pos = pos;
	cyl.radius = rad;
	cyl.ray = NULL;
	cyl.col = col;
	return (cyl);
}