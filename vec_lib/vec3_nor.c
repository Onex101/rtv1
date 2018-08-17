/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_nor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeno <xeno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 17:47:45 by xeno              #+#    #+#             */
/*   Updated: 2018/08/17 14:49:29 by xeno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_lib.h"

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

	cpy = vec3_cpy(v); 
	vec3_nor(&cpy);
	return(cpy);
}