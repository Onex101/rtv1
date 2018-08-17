/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_sub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 17:44:31 by xeno              #+#    #+#             */
/*   Updated: 2018/08/17 12:14:21 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_lib.h"

void	vec2_sub(t_vec2 *v1, t_vec2 *v2)
{
	if (v1 && v2)
	{
		v1->x -= v2->x;
		v1->y -= v2->y;
	}
}

t_vec2	*vec2_sub_new(t_vec2 *v1, t_vec2 *v2)
{
	t_vec2 *cpy;

	if (v1 && v2)
	{
		if (!(cpy = vec2_cpy(v1)))
			return (NULL);
		vec2_sub(cpy, v2);
		return (cpy);	
	}
	return (NULL);
}