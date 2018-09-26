/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_mul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 17:45:11 by xeno              #+#    #+#             */
/*   Updated: 2018/09/26 10:32:42 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_vec.h"

void	vec3_mul(t_vec3 *v, double i)
{
	v->x *= i;
	v->y *= i;
	v->z *= i;
}

t_vec3	vec3_mul_new(const t_vec3 v1, double i)
{
	t_vec3 cpy;

	cpy = vec3_cpy(v1);
	vec3_mul(&cpy, i);
	return (cpy);
}
