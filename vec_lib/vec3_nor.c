/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_nor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 17:47:45 by xeno              #+#    #+#             */
/*   Updated: 2018/08/17 12:13:51 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_lib.h"

double	vec3_nor(t_vec3 *v)
{
	double l;

	l = vec3_len(v);
	(vec3_div(v, l));
	return (l);
}

t_vec3	*vec3_nor_cpy(t_vec3 *v)
{
	t_vec3 *cpy;

	if (v)
	{
		if(!(cpy = vec3_cpy(v)))
			return (NULL);
		vec3_nor(cpy);
		return(cpy);
	}
	return (NULL);
}