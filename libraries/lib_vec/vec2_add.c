/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 17:43:47 by xeno              #+#    #+#             */
/*   Updated: 2018/08/18 13:14:09 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_vec.h"

void	vec2_add(t_vec2 *v1, t_vec2 v2)
{
	v1->x += v2.x;
	v1->y += v2.y;
}

t_vec2	vec2_add_new(t_vec2 v1, t_vec2 v2)
{
	t_vec2 cpy;

	cpy = vec2_cpy(v1);
	vec2_add(&cpy, v2);
	return (cpy);	
}