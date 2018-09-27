/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_div.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 17:45:43 by xeno              #+#    #+#             */
/*   Updated: 2018/09/27 15:53:44 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_vec.h"

void	vec3_div(t_vec3 *v, double i)
{
	if (v)
	{
		v->x /= i;
		v->y /= i;
		v->z /= i;
	}
}

t_vec3	vec3_div_new(const t_vec3 v1, double i)
{
	t_vec3 cpy;

	cpy = vec3_cpy(v1);
	vec3_div(&cpy, i);
	return (cpy);
}
