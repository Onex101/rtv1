/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_pnt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 12:27:39 by xeno              #+#    #+#             */
/*   Updated: 2018/09/27 16:05:55 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ray.h"

t_vec2	calc_pnt(t_ray r, double t)
{
	t_vec3 tmp;
	t_vec2 pnt;

	tmp = vec3_mul_new(r.dir, t);
	pnt.x = r.org.x + tmp.x;
	pnt.y = r.org.y + tmp.y;
	return (pnt);
}
