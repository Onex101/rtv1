/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_div.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 17:45:43 by xeno              #+#    #+#             */
/*   Updated: 2018/09/26 10:34:21 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_vec.h"

void	vec2_div(t_vec2 *v, double i)
{
	v->x /= i;
	v->y /= i;
}

t_vec2	vec2_div_new(t_vec2 v1, double i)
{
	t_vec2 cpy;

	cpy = vec2_cpy(v1);
	vec2_div(&cpy, i);
	return (cpy);
}
