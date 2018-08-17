/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_mul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 17:45:11 by xeno              #+#    #+#             */
/*   Updated: 2018/08/17 12:14:24 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_lib.h"

void	vec2_mul(t_vec2 *v, double i)
{
	if (v)
	{
		v->x *= i;
		v->y *= i;
	}
}

t_vec2	*vec2_add_new(t_vec2 *v1, double i)
{
	t_vec2 *cpy;

	if (!(cpy = vec2_cpy(v1)))
		return (NULL);
	vec2_mul(cpy, i);
	return (cpy);	
}