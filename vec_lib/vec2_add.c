/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 17:43:47 by xeno              #+#    #+#             */
/*   Updated: 2018/08/17 12:14:34 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_lib.h"

void	vec2_add(t_vec2 *v1, t_vec2 *v2)
{
	if (v1 && v2)
	{
		v1->x += v2->x;
		v1->y += v2->y;
	}
}

t_vec2	*vec2_add_new(t_vec2 *v1, t_vec2 *v2)
{
	t_vec2 *cpy;

	if (!(cpy = vec2_cpy(v1)))
		return (NULL);
	vec2_add(cpy, v2);
	return (cpy);	
}