/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_nor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 17:47:45 by xeno              #+#    #+#             */
/*   Updated: 2018/09/25 18:14:10 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_vec.h"
#include "lib_ft.h"

double	vec3_nor(t_vec3 *v)
{
	double l;

	l = vec3_len(*v);
	vec3_div(v, l);
	return (l);
}

t_vec3	vec3_nor_cpy(t_vec3 v)
{
	t_vec3 cpy;
	double len;

	cpy = vec3_cpy(v);
	if (!(len = vec3_nor(&cpy)))
		return (vec3());
	if (len == 1)
		return (v);
	return (cpy);
}
